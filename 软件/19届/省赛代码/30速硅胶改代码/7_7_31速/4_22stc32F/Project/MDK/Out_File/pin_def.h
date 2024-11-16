#ifndef __PIN_DEF_H_
#define __PIN_DEF_H_



#define ADC0 ADC_P05//ADC_P01
#define ADC1 ADC_P11//ADC_P00
#define ADC2 ADC_P00//ADC_P02
#define ADC3 ADC_P14//ADC_P15
#define ADC4 ADC_P01//ADC_P14	
#define ADC5 ADC_P15//ADC_P11
#define ADC6 ADC_P02//ADC_P05	
#define ADC7 //ADC_P06	

//编码器接口定义,这里只使用一个引脚作为输入
#define MOTOR1_ENCODER CTIM0_P34			//Z相
#define MOTOR2_ENCODER CTIM3_P04
#define MOTOR1_DIR P35								//dir方向
#define MOTOR2_DIR P53

//电机接口定义
#define MOTOR1 PWMA_CH2N_P13 //左   8701
#define MOTOR2 PWMA_CH1P_P10 //右
#define MOTOR1_d P26
#define MOTOR2_d P24

//#define MOTOR1_CH1 PWMA_CH1P_P10 //左     7971
//#define MOTOR1_CH2 PWMA_CH3P_P24 //左

//#define MOTOR2_CH1 PWMA_CH2N_P13 //右
//#define MOTOR2_CH2 PWMA_CH4P_P26 //右


//按键引脚定义
#define KEY0 P16
#define KEY1 P50
#define KEY2 P17
#define KEY3 P51
#define KEY4 P45

//蜂鸣器引脚定义
#define buzzer P32


#endif
