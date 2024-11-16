#ifndef _MOTOR_H_
#define _MOTOR_H_

extern void motor(void);
extern void multistage_pid(void);
extern void multistage_pid_turn(void);
extern float forwardfeed_L(float in);
extern float forwardfeed_R(float inc_in);			
extern float forward_flag;
extern float set_turn;

extern float forwardfeed_turn(float inc_in);			

extern float r_target_speed;
extern float l_target_speed;
extern float r_endspeed;
extern float l_endspeed;
extern float r_speed,l_speed;
extern float angle_speed, turn_speed;

#endif
