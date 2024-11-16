#ifndef _ELEMENT_H_
#define _ELEMENT_H_


float pow2(float w);
char YUANHUAN(void);
void judge(void);
void trend_judge(void);

extern float motor_inc;
extern char flag_shizi;
extern int shizi_count;
extern char circle_count;
extern char adc_state[11];
extern int switch_shizi_circle;	//‘™Àÿ≤‚ ‘œ‘ æ«–ªª
extern char barrier;
extern char flag_barrier;

extern char zhijiao_L;
extern char zhijiao_R;

extern float s_r_SHIZI;
extern float s_r_WSHIZI;

extern float s_r_RSHIZI;
extern float s_r_LSHIZI;

extern float target_speed_save;

#endif