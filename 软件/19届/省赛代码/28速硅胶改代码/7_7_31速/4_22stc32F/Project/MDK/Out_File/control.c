#include "headfile.h"

PID_TypDef mr_pid,ml_pid,R_pid,L_pid,Steer_pid,turn_pid,w_pid;	//左右电机PID
PID_TypDef s_pid;

void PID_init(PID_TypDef* sptr)
{
		sptr->Kp = 0.0;             // 比例常数 Proportional Const
		sptr->Ki = 0.0;               // 积分常数 Integral Const
		sptr->Kd = 0.0;             // 微分常数 Derivative Const
		sptr->Kd2 = 0.0;
		sptr->Bias      = 0.0;    
		sptr->Integral  = 0.0;
		sptr->Last_Bias = 0.0;                
		sptr->Pre_Bias  = 0.0;
		
			
}

//PID设置
void PID_Set(PID_TypDef *PID,float Kp,float Ki,float Kd)
{
	PID->Kp = Kp;
	PID->Ki = Ki;
	PID->Kd = Kd;
}

void PID_turnSet(PID_TypDef *PID,float Kp,float Ki,float Kd,float Kd2)
{
	PID->Kp = Kp;
	PID->Ki = Ki;
	PID->Kd = Kd;
	PID->Kd2 = Kd2;
}

//速度环(增量式PID)
float IncPID(float Encoder,float Target,PID_TypDef* sptr) 
{
  float	Pwm;
	
  sptr->Bias = Target - Encoder;                                     // 计算当前误差
  Pwm = sptr->Kp * (sptr->Bias-sptr->Last_Bias)+sptr->Ki * sptr->Bias +sptr->Kd * (sptr->Bias-2*sptr->Last_Bias+sptr->Pre_Bias);  //P I D
//  p=((sptr->Bias-sptr->Last_Bias));
  sptr->Pre_Bias=sptr->Last_Bias;                          // 存储误差，用于下次计算
  sptr->Last_Bias=sptr->Bias;		
	
//	if(abs(Pwm)<=10)
//	{
//		Pwm=0;
//	}
	 
  return Pwm;                                    // 返回增量值
	
}


//位置式PID
float PstPID(float Angle, float Target,PID_TypDef* sptr)
{
	float Pwm;
	
	sptr->Bias = Target -Angle ;
	sptr->Integral += sptr->Bias;
	
	Pwm = sptr->Kp   * sptr->Bias              // P
         +sptr->Ki * sptr->Integral                         // I
         +sptr->Kd * (sptr->Bias-sptr->Last_Bias);  // D
	
	sptr->Last_Bias=sptr->Bias;
	
	return(Pwm); 
	
}

//转向增量式PID
float turn_PstPID(float turn_error,PID_TypDef* sptr)
{
  float	Pwm;
  sptr->Bias = turn_error;                                     // 计算当前误差
	
	Pwm = sptr->Kp * (sptr->Bias-sptr->Last_Bias)+sptr->Ki * sptr->Bias +sptr->Kd * sptr->Bias *fabs(sptr->Bias)+sptr->Kd2*sptr->Bias *sptr->Bias *sptr->Bias ;  //P I D
	
//	if(fabs(sptr->Bias) <= 1.5)
//  Pwm = sptr->Kp * (sptr->Bias-sptr->Last_Bias)+sptr->Ki * sptr->Bias +sptr->Kd * sptr->Bias *fabs(sptr->Bias) * 0.7 ;  //P I D
//	else
//	Pwm = sptr->Kp * (sptr->Bias-sptr->Last_Bias)+sptr->Ki * sptr->Bias +sptr->Kd * sptr->Bias *fabs(sptr->Bias) * 1.1;  
	
//  p=((sptr->Bias-sptr->Last_Bias));
  sptr->Pre_Bias=sptr->Last_Bias;                          // 存储误差，用于下次计算
  sptr->Last_Bias=sptr->Bias;		
	

	 
  return Pwm;                                    // 返回增量值
	
	
}












