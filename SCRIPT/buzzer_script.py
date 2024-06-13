import numpy as np
import aubio
import soundfile as sf

# 加载音频文件
filename = r"d:\2024_ZJH\Buzzer\SCRIPT/alone.wav"
audio_data, sample_rate = sf.read(filename)

# 检查audio_data是否为多维数组，如果是，则只取第一个通道
if audio_data.ndim > 1:
    audio_data = audio_data[:, 0]  # 假设audio_data是numpy数组，取所有行的第0列（即左声道）

# 创建aubio频率检测器
downsample = 1

win_s = 2048 // downsample # fft size
hop_s = 512  // downsample # hop size

pitch_detector = aubio.pitch("yin", win_s, hop_s, sample_rate)

tolerance = 0.5 # 设置容差

pitch_detector.set_tolerance(tolerance)

pitches_raw = []
confidences_raw = []
# 创建一个空列表来存储频率和时长信息
pitches = []
confidences = []
durations = []

# 提取音频中的频率和时长
total_frames = len(audio_data)
current_frame = 0
while current_frame < total_frames:
    end_frame = current_frame + pitch_detector.hop_size
    samples = audio_data[current_frame:end_frame]
    # 检查samples的长度是否为1024
    if len(samples) < pitch_detector.hop_size:
        # 如果不是，可以选择跳过这部分数据
        break  # 或者使用其他逻辑处理这种情况
    samples = np.array(samples).astype(np.float32)  # 将samples转换为float32类型
    pitch = pitch_detector(samples)[0]
    confidence = pitch_detector.get_confidence()
    pitches_raw.append(pitch)
    confidences_raw.append(confidence)
    if confidence > 0.4:  # 可以根据信心阈值过滤频率
        pitches.append(pitch)
        confidences.append(confidence)
        durations.append(len(samples) / float(sample_rate))
    current_frame += pitch_detector.hop_size

print("const tNote test[] = {")

# 打印提取到的频率和时长信息，每10组换一行
for i, (pitch, duration) in enumerate(zip(pitches, durations), 1):
    rounded_pitch = round(pitch)  # 对频率进行四舍五入
    ms_duration = round(duration * 1000)  # 将持续时间转换为毫秒
    # 打印或处理pitch和duration
    print(f"  {{{rounded_pitch}, {ms_duration}}}", end=",")
    if i % 10 == 0:
        print()  # 每10组换行
print("\n  {0, 0}//end\n};")  # 打印最后一组数据





import matplotlib.pyplot as plt

# 创建一个图像，设置大小
plt.figure(figsize=(10, 6))

# 创建双轴图
plt.subplot(2, 1, 1)  # 2行1列的图像中的第1个
ax1 = plt.gca()  # 获取当前轴
ax2 = ax1.twinx()  # 创建另一个轴，共享同一个x轴

# 绘制音高到第一个轴
ax1.plot(pitches_raw, label='Pitch', color='blue')
ax1.set_title('RAW')
ax1.set_ylabel('Frequency (Hz)', color='blue')
ax1.tick_params(axis='y', labelcolor='blue')
ax1.grid(True)

# 绘制置信度到第二个轴
ax2.plot(confidences_raw, label='Confidence', color='orange')
ax2.set_ylabel('Confidence', color='orange')
ax2.tick_params(axis='y', labelcolor='orange')

# 计算置信度的平均值
confidence_mean = sum(confidences_raw) / len(confidences_raw)
# 在置信度图上画一条表示平均值的水平线
ax2.axhline(y=confidence_mean, color='red', linestyle='--', label='Average Confidence')

# 添加平均值的数值文本
# 选择合适的x位置和y位置来放置文本，这里以图的右上角为例
text_x_position = 0.95  # x位置，以图的宽度比例表示
text_y_position = confidence_mean  # y位置，即平均值的高度
plt.text(text_x_position, text_y_position, f'Avg: {confidence_mean:.2f}', 
         horizontalalignment='right', verticalalignment='center', 
         transform=ax2.get_yaxis_transform(), color='red')

# 添加图例
ax1.legend(loc='upper left')
ax2.legend(loc='upper right')

plt.subplot(2, 1, 2)  # 2行1列的图像中的第2个
ax1 = plt.gca()  # 获取当前轴
ax2 = ax1.twinx()  # 创建另一个轴，共享同一个x轴

# 绘制音高到第一个轴
ax1.plot(pitches, label='Pitch', color='blue')
ax1.set_title('AFTER')
ax1.set_ylabel('Frequency (Hz)', color='blue')
ax1.tick_params(axis='y', labelcolor='blue')
ax1.grid(True)

# 绘制置信度到第二个轴
ax2.plot(confidences, label='Confidence', color='orange')
ax2.set_ylabel('Confidence', color='orange')
ax2.tick_params(axis='y', labelcolor='orange')

# 计算置信度的平均值
confidence_mean = sum(confidences) / len(confidences)
# 在置信度图上画一条表示平均值的水平线
ax2.axhline(y=confidence_mean, color='red', linestyle='--', label='Average Confidence')

# 添加平均值的数值文本
# 选择合适的x位置和y位置来放置文本，这里以图的右上角为例
text_x_position = 0.95  # x位置，以图的宽度比例表示
text_y_position = confidence_mean  # y位置，即平均值的高度
plt.text(text_x_position, text_y_position, f'Avg: {confidence_mean:.2f}', 
         horizontalalignment='right', verticalalignment='center', 
         transform=ax2.get_yaxis_transform(), color='red')

# 添加图例
ax1.legend(loc='upper left')
ax2.legend(loc='upper right')


# 显示图像
plt.tight_layout()
plt.show()