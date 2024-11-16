#include "headfile.h"

extern float set_turn;
char bizhangSTARTFlag = 0;
int switch_shizi_circle = 0; 			//元素测试显示切换
extern int judge_sign;		//元素判断启动标志


char motor_start = 0;
char key_function_flag = 1;
char cricle_order = 20;
char bizhang_order = 0;
char cricle_function_switch = 1;


void key(void)			//利用按键控制OLED
{
	if(KEY0 == 0)      //切换模式
	{
		delay_ms(10);
		if(KEY0 == 0)
		{
			while(KEY0 == 0);
			
			if(motor_start==1)
			{
				l_pwm=0;		//手动脱线保护
				r_pwm=0;
				mr_pid.Bias=0;
				ml_pid.Bias=0;

				pwm_duty(MOTOR1,0); //左
				pwm_duty(MOTOR2,0); //右
				
				motor_start = 0;
				
			}
			else
			{
				motor_start = 1;
			}
		
		}
	}

	if(KEY1 == 0)
	{
		delay_ms(10);
		if(KEY1 == 0)
		{

			while(!KEY1);	//等待按键松开
			ips_page+=1;
			if(ips_page==4)
			{
				ips_page=1;
			}
			
		}
	}
	
	
	if(KEY2 == 0)					//向上切换页面
	{
		delay_ms(3);
		if(KEY2 == 0)
		{
			while(KEY2 == 0);
			
			key_function_flag+=1;
			if(key_function_flag==5)
			{
				key_function_flag=1;
			}
			
			
			
		}
	}
	
	if(KEY3 == 0)
	{
		delay_ms(10);
		if(KEY3 == 0)
		{
			while(KEY3 == 0);
			
			switch(key_function_flag)	//功能键
			{
			  case 1:		//避障顺序
					
					bizhang_order += 2;
					if(bizhang_order > 20)
					{
						bizhang_order = 0;
					}
					break;
				
				case 2:		//圆环顺序
					
					cricle_order += 2;
					if(cricle_order > 20)
					{
						cricle_order = 0;
					}
					break;
				
				case 3:		//改变速度
					
					r_target_speed += 2;
					l_target_speed += 2;
					target_speed_save = l_target_speed;
					break;
				
				case 4:
					
					cricle_function_switch++;
					if(cricle_function_switch > 1)
					{
						cricle_function_switch = 0;
					}
					
			}
				
		}
	}
	
	if(KEY4 == 0)
	{
		delay_ms(10);
		if(KEY4 == 0)
		{
			while(KEY4 == 0);	//等待按键松开
			
		switch(key_function_flag)
			{
			  case 1:
					
					bizhang_order += -1;
					break;
				
				case 2:
					
					cricle_order += -1;
					break;
				
				case 3:
					
					r_target_speed += -1;
					l_target_speed += -1;
					target_speed_save = l_target_speed;
					break;
				
			}
		}
	}
	
	
}


