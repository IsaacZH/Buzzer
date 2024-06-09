/*******************************************************************************
                      ��Ȩ���� (C), 2022-,NCUROBOT
 *******************************************************************************
  �� �� ��   : buzzer.c
  �� �� ��   :
  ��    ��   : ����
  ��������   :
  ����޸�   :
  ��������   :
  �����б�   :
*******************************************************************************/
/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "buzzer.h"
#include "tim.h"

/* �ڲ��궨�� ----------------------------------------------------------------*/

/* �ڲ��Զ����������͵ı��� --------------------------------------------------*/

/* �ڲ����� ------------------------------------------------------------------*/

/* �ڲ�����ԭ������ ----------------------------------------------------------*/
void Timer_Set(TIM_HandleTypeDef* htim, uint32_t channel, uint32_t frequency, float dutyCycle);

/* �������岿�� --------------------------------------------------------------*/
/**
  * @brief				��������LED����
  * @param[out]		��ͬƵ�ʼ���Ӧ����
  * @param[in]		note������long����
  * @retval				
*/
float db_value = 1.f;
void Note(int note,float Long)
{
	static uint32_t last_tick = 0;
	static int8_t sgn = 1;
	Timer_Set(&htim12, TIM_CHANNEL_2, note, db_value);

	HAL_Delay(Long*200);
	if (HAL_GetTick()-last_tick > 50)
	{
		db_value = db_value + sgn * 0.1;
		last_tick = HAL_GetTick();
	}
	
	if (db_value > 10)
	{
		sgn *= -1;
	}
	if (db_value < 1)
	{
		sgn *= -1;
	}
		
}

// ����ռ�ձȺ�Ƶ�ʵĺ���
void Timer_Set(TIM_HandleTypeDef* htim, uint32_t channel, uint32_t frequency, float dutyCycle)
{
    // ȷ��Ƶ�ʺ�ռ�ձ��ں���Χ��
    if (frequency == 0 || dutyCycle < 0.0f || dutyCycle > 100.0f)
        return;

    // ���㶨ʱ����ʱ��Ƶ��
    uint32_t timerClock = 2400000; // Ĭ�϶�ʱ����ʱ��Ƶ��Ϊ 100MHz

    // �������ں�Ԥ��Ƶ��
    uint32_t prescaler = timerClock / frequency;
		
		__HAL_TIM_SET_AUTORELOAD(htim, prescaler);//����ARR

    // ����Ƚ�ֵ
    uint32_t compareValue = (uint32_t)((dutyCycle / 100.0f) * prescaler);

    // ����ͨ�����ñȽ�ֵ

    __HAL_TIM_SET_COMPARE(htim, channel, compareValue);
	  HAL_TIM_PWM_Start(htim,channel); 
}
/********** ���㡷-GALA**********/
void gala_you(void) 
{
	float t=0.2;

	Note( note_5B , 1 );    //ǰ��
	Note( note_G , 1 );
	Note( note_5B , 2 );
	Note( note_G , 1 );
	Note( note_5B ,  2);
	Note( note_G , 1 );
	Note( note_5D ,  2);
	Note( note_G , 1 );
	Note( note_5C , 1 );
	Note( note_5C , 1 );
	Note( note_G , 1 );
	Note( note_5B , 1 );
	Note( note_5C , 1 );
	
	Note( note_5B , 1 );
	Note( note_G , 1 );
	Note( note_5B , 2 );
	Note( note_G , 1 );
	Note( note_5B ,  2);
	Note( note_G , 1 );
	Note( note_5D ,  2);
	Note( note_G , 1 );
	Note( note_5C , 1 );
	Note( note_5C , 1 );
	Note( note_G , 1 );
	Note( note_5B , 1 );
	Note( note_5C , 1 );
	
	Note( note_5B , 1 );
	Note( note_G , 1 );
	Note( note_5B , 2 );
	Note( note_G , 1 );
	Note( note_5B ,  2);
	Note( note_G , 1 );
	Note( note_5D ,  2);
	Note( note_G , 1 );
	Note( note_5C , 1 );
	Note( note_5C , 1 );
	Note( note_G , 1 );
	Note( note_5B , 1 );
	Note( note_5C , 1 );

  Note( note_5B , 1 );
	Note( note_G , 1 );
	Note( note_5B , 2 );
	Note( note_G , 1 );
	Note( note_5B , 2 );
	Note( note_G , 1 );
	Note( note_5D ,  2);
	Note( note_G , 1 );
	Note( note_5C , 1 );
	Note( note_5C , 1 );
	Note( note_G , 1 );
	Note( note_D , 2 );
	
	Note( note_E , 6 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 4 );
	
	Note( note_5C , 4 );
	Note( note_5B , 4 );
	Note( note_E , 4 );
	Note( note_D , 2 );
	
	Note( note_E , 6 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5C , 8 );
	
	Note( note_5B , 2 );
	Note( note_5D , 4 );
	Note( note_E , 10 );
	
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5B , 4 );
	
	Note( note_5C , 4 );
	Note( note_5B , 4 );
	Note( note_E , 4 );
	Note( note_D , 2 );
	
	Note( note_E , 6 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5B , 4 );
	
	Note( note_5C , 4 );
	Note( note_5D , 10 );

	Note( 0 , 4 );      //��һֱ׷Ѱ����
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	
	Note( 0 , 2 );      //�����ԶҲ����
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 4 );
	Note( note_C , 6 );
	 
	Note( 0 , 2 );      //ȴ�ܱ����ž���
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
//	Note( note_D , 2 );
	Note( note_D , 2 );
//	Note( note_C , 1 );
	Note( note_C , 2 );  
	Note( note_D , 2 );  

	Note( 0 , 2 );      
	Note( note_E , 2 );  //��һֱ��������
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	
	Note( 0 , 2 );      //����������һ���
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5C , 4 );
	Note( note_C , 6 );
	
	Note( 0 , 2 );      //���һ�Ц���ҿ���
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_B , 2 );
	Note( note_A , 1 );
	Note( note_3G , 5 );
	
	Note( 0 , 1 );      //��������������
	Note( note_3G , 1 );
	Note( 0 , t );
	Note( note_3G , 1 );
	Note( 0 , t );
	Note( note_3G , 1 );
	Note( note_G , 4 );
	Note( note_E , 3 );
	Note( note_D , 1 );
	Note( note_C , 2 );
	Note( 0 , t );
	Note( note_C , 4 );  
	
	Note( 0 , 1 );
	Note( note_C , 2 );      //���յ�ϸ��
	Note( 0 , 0.05 );
	Note( note_C , 2 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_A , 6 );
	
	Note( 0 , 2 );          //Ĺ���ĳ���
	Note( note_A , 2 );
	Note( note_E , 2 );
	Note( note_D , 2 );
	Note( note_C , 2 );
	Note( note_D , 6 );
	Note( 0 , 2 ); 
	
	Note( note_E , 4 );      //�Ҵ�������������
	Note( note_F , 4 );
	Note( note_G , 6 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5B , 4 );
	Note( note_5C , 6 );
	
	Note( note_C , 2 );     //Ϊ������������޵�����
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 4 );
	Note( note_5A , 4 );
	Note( note_G , 1 );
	Note( note_5A , 3 );
	Note( note_G , 1 );
	Note( 0 , 0.1 );    
	Note( note_G , 3 );
	Note( 0 , 0.1 );
	Note( note_G , 4 );
	Note( note_D , 8 );
	
	Note( note_E , 4 );     //����������һ��Ц��
	Note( note_F , 4 );
	Note( note_G , 6 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5B , 4 );
	Note( note_5C , 6 );

	Note( note_C , 2 );     //Ҳ���Һ�ɵ���Ҳ�����
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5B , 4 );
	Note( note_5A , 6 );
	Note( 0 , t );
	Note( note_5A , 2 );
	Note( note_G , 1 );
	Note( note_5A , 3 );
	Note( note_5C , 4 );
	Note( note_5D , 6 );
	
	Note( 0 , 2 );
	Note( note_G , 2 );   //��Ը��ѽ
	Note( note_5C , 2 );
	Note( note_5B , 1 );
	Note( note_5C , 12 );
		
	Note( 0 , 4 );
		
  Note( 0 , 2 );      //���Ƕ�׷Ѱ����
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	
	Note( 0 , 2 );      //�������㵱��Ψһ
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 4 );
	Note( note_C , 6 );
	
//	Note( 0 , 4 );
	
	Note( 0 , 2 );      //���ȴ����Ϊ��
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
//	Note( note_D , 2 );
	Note( note_D , 2 );
//	Note( note_C , 1 );
	Note( note_C , 2 );  
	Note( note_D , 2 );
	
	Note( 0 , 2 );      //���Ƕ���������
	Note( note_E , 2 );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	
	Note( 0 , 2 );      //����������������
	Note( note_E , 2 );
	Note( 0 , t );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5C , 4 );
	Note( note_C , 6 );
	
//	Note( 0 , 4 );
	
	Note( 0 , 2 );      //һ��ӵ��һ������
	Note( note_E , 2 );
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_E , 3 );
	Note( note_D , 2 );
	Note( note_B , 2 );
	Note( note_A , 1 );
	Note( note_3G , 5 );
	
	Note( 0 , 1 );      //�����㲻Ϊ˭�غ�
	Note( note_3G , 1 );
	Note( 0 , t );
	Note( note_3G , 1 );
	Note( 0 , t );
	Note( note_3G , 1 );
	Note( note_G , 4 );
	Note( note_E , 3 );
	Note( note_D , 1 );
	Note( note_C , 2 );
	Note( 0 , t );
	Note( note_C , 4 );
	
	Note( 0 , 1 );
	Note( note_C , 2 );      //����ŵ����
	Note( 0 , t );
	Note( note_C , 2 );
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_A , 6 );
	
	Note( 0 , 2 );          //������ͣ��
	Note( note_A , 2 );
	Note( note_E , 2 );
	Note( note_D , 2 );
	Note( note_C , 2 );
	Note( note_D , 10 );
	
	Note( 0 , 4 ); 
	Note( note_E , 4 );      //��֪��ֻ�в��ϳ���
	Note( note_F , 4 );
	Note( note_G , 6 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5B , 4 );
	Note( note_5C , 6 );
	
	Note( note_C , 2 );     //���ܹ�����������Ĳ���
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 4 );
	Note( note_5A , 5 );
	Note( note_G , 1 );
	Note( note_5A , 2 );
	Note( note_G , 1 );
	Note( 0 , t );
	Note( note_G , 3 );
	Note( 0 , 0.1 );
	Note( note_D , 2 );
	Note( 0 , 0.1 );
	Note( note_D , 8 );
	
	Note( note_E , 4 );     //�����Ǻ���������
	Note( note_F , 4 );
	Note( note_G , 4 );
	Note( 0 , 0.5 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5D , 4 );
	Note( note_5C , 6 );
	
	Note( note_C , 2 );    //��˿��׷�
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5C , 4 );
	Note( note_5A , 5 );

	Note( note_G , 1 );     //ֻ������ش�
	Note( note_5A , 2 );
	Note( note_G , 1 );
	Note( note_5A , 3 );
	Note( note_5C , 4 );
	Note( note_5D , 6 );
	
	Note( 0 , 2 );
	Note( note_D , 2 );   //��Ը��ѽ
	Note( note_E , 2 );
	Note( note_D , 1 );
	Note( note_C , 12 );
	
	//������
	
	Note( 0 , 4 );
	Note( note_E , 4 );      //�Ҵ�������������
	Note( note_F , 4 );
	Note( note_G , 6 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5B , 4 ); 
	Note( note_5C , 6 );
	
	Note( note_C , 2 );     //Ϊ������������޵�����
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 4 );
	Note( note_5A , 5 );
	Note( note_G , 1 );
	Note( note_5A , 2 );
	Note( note_G , 1 );
	Note( 0 , 0.1 );
	Note( note_G , 3 );
	Note( 0 , 0.1 );
	Note( note_G , 4 );
	Note( note_D , 8 );
	
	Note( note_E , 4 );     //����������һ��Ц��
	Note( note_F , 4 );
	Note( note_G , 6 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5B , 4 );
	Note( note_5C , 6 );

	Note( note_C , 2 );     //Ҳ���Һ�ɵ���Ҳ�����
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5C , 4 );
	Note( note_5A , 6 );
	Note( 0 , t );
	Note( note_5A , 2 );
	Note( note_G , 1 );
	Note( note_5A , 3 );
	Note( note_5C , 4 );
	Note( note_5D , 6 );
	
  Note( note_E , 4 );      //��֪��ֻ�в��ϳ���
	Note( note_F , 4 );
	Note( note_G , 6 );
	Note( note_E , 2 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5B , 4 );
	Note( note_5C , 6 );
	
	Note( note_C , 2 );     //���ܹ�����������Ĳ���
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_G , 4 );
	Note( note_5A , 5 );
	Note( note_G , 1 );
	Note( note_5A , 2 );
	Note( note_G , 1 );
	Note( 0 , 0.1 );
	Note( note_G , 3 );
	Note( 0 , 0.1 );
	Note( note_G , 4 );
//	Note( note_D , 2 );
//	Note( 0 , 0.1 );
	Note( note_D , 8 );
	
	Note( note_E , 4 );     //�����Ǻ���������
	Note( note_F , 4 );
	Note( note_G , 4 );
	Note( 0 , 1 );
	Note( note_G , 2 );
	Note( note_E , 1 );
	Note( note_G , 3 );
	Note( note_5D , 4 );
	Note( note_5C , 6 );
	
	Note( note_C , 2 );    //��˿��׷�
	Note( note_D , 2 );
	Note( note_E , 2 );
	Note( note_5C , 4 );
	Note( note_5A , 5 );

	Note( note_G , 1 );     //ֻ������ش�
	Note( note_5A , 2 );
	Note( note_G , 1 );
	Note( note_5A , 3 );
	Note( note_5C , 4 );
	Note( note_5D , 6 );
	
	Note( 0 , 2 );
	Note( note_G , 2 );   //��Ը��ѽ
	Note( note_5C , 2 );
	Note( note_5B , 1 );
	Note( note_5C , 12 );
	
	//β
	Note( 0 , 4 );
	Note( note_E , 4 );
	Note( note_D , 4 );   
	Note( note_C , 4 );
	Note( note_G , 4 );
	Note( note_C , 4 );
	Note( note_D , 4 );
	Note( note_E , 4 );   
	Note( note_F , 4 );
	Note( note_G , 4 );
	Note( note_F , 4 );
	
	Note( note_E , 4 );
	Note( note_D , 4 );   
	Note( note_C , 4 );
	Note( note_D , 4 );
	Note( note_E , 4 );
	Note( note_F , 4 );
	Note( note_E , 4 );   
	Note( note_D , 4 );
	Note( note_C , 4 );
	Note( note_G , 4 );
	
	Note( note_E , 4 );
	Note( note_D , 4 );   
	Note( note_E , 4 );
	Note( note_F , 4 );
	Note( note_G , 4 );
	Note( note_F , 4 );
	Note( note_E , 4 );   
	Note( note_D , 4 );
	
	Note( note_E , 4 );   
	Note( note_D , 4 );
	Note( note_E , 4 );
	Note( note_F , 4 );
	
	Note( note_E , 4 );
	Note( note_D , 4 );   
	Note( note_C , 4 );
	Note( note_G , 4 );
	Note( note_C , 4 );
	Note( note_D , 4 );
	Note( note_E , 4 );   
	Note( note_F , 4 );
	Note( note_G , 4 );
	Note( note_F , 4 );
	Note( note_E , 4 );
	Note( note_D , 4 ); 
	
}
	

