#ifndef _INIT_H_
#define _INIT_H_

#define OELD_CLS oled_fill(0x00)
#define PI 3.14
#define PAGE_MAX 3


extern float adc[11];
extern float r_pwm,l_pwm;

extern float Xdata,Ydata,Zdata;
extern float acc_x,acc_y,acc_z;
extern float gyro_x,gyro_y,gyro_z;

extern char a;
extern int text;//text零漂标志位
extern float z_inc ,x_inc,y_inc;

extern void car_pre_init(void);
extern void get_adc(void);	//ADC获取并处理
extern void gyroOffsetInit(void);     //去零漂




#endif
