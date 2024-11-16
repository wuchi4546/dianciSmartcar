#ifndef _CONTROL_H_
#define _CONTROL_H_

typedef struct 
{
		 float   Kp;             // 比例常数 Proportional Const
		 float   Ki;               // 积分常数 Integral Const
		 float   Kd;             // 微分常数 Derivative Const
		 float 	 Kd2;
		 float			Integral;
		 float      Bias;                 
		 float      Last_Bias;                
		 float      Pre_Bias;                
}PID_TypDef;

extern PID_TypDef mr_pid,ml_pid,Steer_pid,turn_pid,w_pid;		//电机pid	
extern PID_TypDef s_pid,R_pid,L_pid;		//电机pid




void PID_init(PID_TypDef* sptr);   //===PID数值初始化
void PID_Set(PID_TypDef *PID,float Kp,float Ki,float Kd);   //===PID数值设置
void PID_turnSet(PID_TypDef *PID,float Kp,float Ki,float Kd,float Kd2);


float IncPID(float Encoder,float Target,PID_TypDef* sptr);    	//===增量式pid
float PstPID(float Angle, float Target,PID_TypDef* sptr);   //===位置式PId
float turn_PstPID(float turn_error,PID_TypDef* sptr);				//转向增量式PID





#endif
