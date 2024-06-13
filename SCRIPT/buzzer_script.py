import numpy as np
import aubio
import soundfile as sf

# 加载音频文件
filename = r"d:\2024_ZJH\Buzzer\SCRIPT\alone.wav"
audio_data, sample_rate = sf.read(filename)

# 检查audio_data是否为多维数组，如果是，则只取第一个通道
if audio_data.ndim > 1:
    audio_data = audio_data[:, 0]  # 假设audio_data是numpy数组，取所有行的第0列（即左声道）

# 创建aubio频率检测器
downsample = 1

win_s = 4096 // downsample # fft size
hop_s = 512  // downsample # hop size

pitch_detector = aubio.pitch("yin", win_s, hop_s, sample_rate)

tolerance = 0.8 # 设置容差

pitch_detector.set_tolerance(tolerance)
# 创建一个空列表来存储频率和时长信息
pitches = []
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
    if confidence > 0.8:  # 可以根据信心阈值过滤频率
        pitches.append(pitch)
        durations.append(len(samples) / float(sample_rate))
    current_frame += pitch_detector.hop_size

print("const tNote test_note[] = { ")

# 打印提取到的频率和时长信息，每10组换一行
for i, (pitch, duration) in enumerate(zip(pitches, durations), 1):
    rounded_pitch = round(pitch)  # 对频率进行四舍五入
    ms_duration = round(duration * 1000)  # 将持续时间转换为毫秒
    # 打印或处理pitch和duration
    print(f"  {{{rounded_pitch}, {ms_duration}}}", end=", ")
    if i % 10 == 0:
        print()  # 每10组换行

print("\n  {0, 0}//end\n};")  # 打印最后一组数据
