#include "headfile.h"

//控制周期
int time_counter = 0; //屏幕刷新
int ips_counter = 0; //屏幕清屏
int8 ips_page = 0; 
int abc=1345;
extern float set_turn;

extern int judge_sign;		//元素判断启动标志

extern char circle_count;		//圆环次数
extern  int shizi_count;		//十字次数
extern char barrier_count;	//避障次数

//--------------------圆环
extern char circle_L;
extern char circle_R;

extern float straight_inc;			//直道积分
extern int circle_inc;			//环岛编码器积分
extern float motor_inc;			//电机积分

extern float s_r;
extern float s_r_RYUAN;
//////-------------------


extern char flag_SHIZI_KNN;
//---------------------------十字

extern char flag_shizi;
extern int switch_shizi_circle;
void yuanshu(int sign);
//--------------------------
extern int collection_shizi[10];
extern int collection_shizi_R[10];
//----------------------	归一化

//extern float save_max_adc[7];
//extern float save_min_adc[7]; 
//extern int target_adc;

//extern float error_last;
	extern float mask[2][7];
	
	
//////----------------------




		char page_buf[60];
 void IPS_page_show(void)
{
	
	switch(ips_page)
	{
		case 0:
				 ips114_showint16(0,0,a);
				 ips114_showint16(0,7,ips_page);
		break;
		case 1:

//			ips114_clear(WHITE);
//		ips114_showstr(0, 0, "acc.x=");
//		ips114_showstr(0, 1, "acc.y=");
//		ips114_showstr(0, 2, "acc.z=");
//		ips114_showstr(0, 0, "gyro.x=");
//		ips114_showstr(0, 1, "gyro.y=");
//		ips114_showstr(0, 2, "gyro.z=");
//		ips114_showint16(6*10, 0, imu660ra_gyro_x);
//		ips114_showint16(6*10, 1, imu660ra_gyro_y);
//		ips114_showint16(6*10, 2, imu660ra_gyro_z);
		
				
				sprintf(page_buf,"L:%d ",circle_L);						
				ips114_showstr(0,0,page_buf);
				sprintf(page_buf,"R:%d ",circle_R);						
				ips114_showstr(45,0,page_buf);
				sprintf(page_buf,"s_r:%.2f   ",s_r*1000);						
				ips114_showstr(0,1,page_buf);
				sprintf(page_buf,"s_r_R:%.2f  ",s_r_RYUAN*1000);						
				ips114_showstr(0,2,page_buf);
				
				sprintf(page_buf,"+:%d ",flag_shizi);						
				ips114_showstr(80,0,page_buf);
				
		
				sprintf(page_buf,"bz_F:%d ",bizhangSTARTFlag);						
				ips114_showstr(0,3,page_buf);
				sprintf(page_buf,"judge:%d ",judge_sign);						
				ips114_showstr(60,3,page_buf);
				
				sprintf(page_buf,"zhi:%.2f  ",motor_inc-straight_inc);						
				ips114_showstr(120,0,page_buf);
				sprintf(page_buf,"YUAN:%d  ",circle_inc);						
				ips114_showstr(120,1,page_buf);
				sprintf(page_buf,"motor:%.2f  ",motor_inc);						
				ips114_showstr(120,2,page_buf);
		
		
				sprintf(page_buf,"err:%.2f  ",error);						//z角速度
				ips114_showstr(140,3,page_buf);
				sprintf(page_buf,"r_speed:%.2f  ",r_endspeed);						
				ips114_showstr(140,4,page_buf);
				sprintf(page_buf,"l_speed:%.2f  ",l_endspeed);						
				ips114_showstr(140,5,page_buf);
				
				sprintf(page_buf,"cir_cou:%d",circle_count);						
				ips114_showstr(140,7,page_buf);
				sprintf(page_buf,"sz_count:%d    ",shizi_count);
				ips114_showstr(140,6,page_buf);
				sprintf(page_buf,"bz_count:%d    ",barrier_count);
				ips114_showstr(0,6,page_buf);
				

				sprintf(page_buf,"l_speed:%.1f  ",l_speed);						
				ips114_showstr(0,4,page_buf);
				sprintf(page_buf,"r_speed:%.1f  ",r_speed);						
				ips114_showstr(0,5,page_buf);
				
				
				sprintf(page_buf,"X:%.2f ,%.2f ",x_inc,gyro_x);						//z角速度
				ips114_showstr(0,7,page_buf);
				
//				ips114_clear(WHITE);									//清屏
		
//				sprintf(page_buf,"Xds:%d  ",abc);						//z角速度
//				ips114_showstr(0,0,page_buf); 				//显示字符串
//				sprintf(page_buf,"X:%.1f ,%.1f ",z_inc,gyro_z);						//z角速度
//				ips114_showstr(0,1,page_buf);
//		
//		
//		
////        ips114_showstr(0,0,"pid canshu"); 				//显示字符串
////        ips114_showuint16(0,1,abc);                				//显示一个16位无符号整数
//        ips114_showint32(0,2,abc,3);               				//显示一个32位有符号数  并去除无效0
//        ips114_showint32(0,3,-666,3);              				//显示一个32位有符号数  并去除无效0
//        ips114_showfloat(0,4,56.35,3,1);           				//显示一个浮点数        并去除整数部分无效0
			break;
//		
		case 2:                            ///////////////////////////ADC

		  sprintf(page_buf,"R:%.1f    ",adc[0]*1000);	
				ips114_showstr(0,0,page_buf);
			sprintf(page_buf,"RS:%.1f    ",adc[1]*1000);
				ips114_showstr(0,1,page_buf);
			sprintf(page_buf,"RH:%.1f    ",adc[2]*1000);
				ips114_showstr(0,2,page_buf);
			sprintf(page_buf,"M:%.1f    ",adc[3]*1000);
				ips114_showstr(0,3,page_buf);
			sprintf(page_buf,"LH:%.1f    ",adc[4]*1000);
				ips114_showstr(0,4,page_buf);
		  sprintf(page_buf,"LS:%.1f    ",adc[5]*1000);
				ips114_showstr(0,5,page_buf);
		  sprintf(page_buf,"L:%.1f    ",adc[6]*1000);
				ips114_showstr(0,6,page_buf);
		  sprintf(page_buf,"NAN:%.1f    ",adc[7]*1000);
				ips114_showstr(0,7,page_buf);
			sprintf(page_buf,"ips_page:%d    ",temp_count);
				ips114_showstr(140,7,page_buf);
		
			sprintf(page_buf,"e:%.3f  ",error);	
				ips114_showstr(96,0,page_buf);
			sprintf(page_buf,"e_x:%.3f  ",error_xie);
				ips114_showstr(96,1,page_buf);
			sprintf(page_buf,"e_s:%.3f  ",error_shu);
				ips114_showstr(96,2,page_buf);
			sprintf(page_buf,"e_s2:%.3f  ",error_shu2);
				ips114_showstr(96,3,page_buf);
			sprintf(page_buf,"dis:%d"    ,Lidar1.distance);
				ips114_showstr(100,4,page_buf);
				
			sprintf(page_buf,"shizi_count:%d ",shizi_count);	
				ips114_showstr(100,5,page_buf);
			sprintf(page_buf,"test_sign:%d ",switch_shizi_circle);	
				ips114_showstr(100,6,page_buf);
				
			if(switch_shizi_circle == 1)
			{
				sprintf(page_buf,"|%d ",collection_shizi[0]);	
					ips114_showstr(188,0,page_buf);
				sprintf(page_buf,"|%d ",collection_shizi[1]);
					ips114_showstr(188,1,page_buf);
				sprintf(page_buf,"|%d ",collection_shizi[2]);
					ips114_showstr(188,2,page_buf);
				sprintf(page_buf,"|%d ",collection_shizi[3]);
					ips114_showstr(188,3,page_buf);
				sprintf(page_buf,"|%d ",collection_shizi[4]);
					ips114_showstr(188,4,page_buf);
				
		  sprintf(page_buf,"|%d ",collection_shizi[5]);
				ips114_showstr(215,0,page_buf);
		  sprintf(page_buf,"|%d ",collection_shizi[6]);
				ips114_showstr(215,1,page_buf);
			sprintf(page_buf,"|%d ",collection_shizi[7]);
				ips114_showstr(215,2,page_buf);
		  sprintf(page_buf,"|%d ",collection_shizi[8]);
				ips114_showstr(215,3,page_buf);
		  sprintf(page_buf,"|%d ",collection_shizi[9]);
				ips114_showstr(215,4,page_buf);
			}
		
		if(switch_shizi_circle == 2)
		{
			sprintf(page_buf,"|%d ",collection_shizi_R[0]);	
				ips114_showstr(188,0,page_buf);
			sprintf(page_buf,"|%d ",collection_shizi_R[1]);
				ips114_showstr(188,1,page_buf);
			sprintf(page_buf,"|%d ",collection_shizi_R[2]);
				ips114_showstr(188,2,page_buf);
			sprintf(page_buf,"|%d ",collection_shizi_R[3]);
				ips114_showstr(188,3,page_buf);
			sprintf(page_buf,"|%d ",collection_shizi_R[4]);
				ips114_showstr(188,4,page_buf);
			
			sprintf(page_buf,"|%d ",collection_shizi_R[5]);
				ips114_showstr(215,0,page_buf);
			sprintf(page_buf,"|%d ",collection_shizi_R[6]);
				ips114_showstr(215,1,page_buf);
			sprintf(page_buf,"|%d ",collection_shizi_R[7]);
				ips114_showstr(215,2,page_buf);
			sprintf(page_buf,"|%d ",collection_shizi_R[8]);
				ips114_showstr(215,3,page_buf);
			sprintf(page_buf,"|%d ",collection_shizi_R[9]);
				ips114_showstr(215,4,page_buf);
		  
			
			}
//			sprintf(page_buf,"error_x:%.3f ",error_xie);
//				ips114_showstr(100,6,page_buf);
//			sprintf(page_buf,"error_s:%.3f ",error_shu);
//				ips114_showstr(100,7,page_buf);
			
				
//	  	sprintf(page_buf,"shu:%.2f",error_shu);
//			oled_p6x8str(50,3,page_buf);
//		  sprintf(page_buf,"xie:%.2f    ",error_xie);
//			oled_p6x8str(50,5,page_buf);
//		  sprintf(page_buf,"heng:%.2f    ",error_heng);
//			oled_p6x8str(50,4,page_buf);
//		  sprintf(page_buf,"error:%.2f    ",error);
//			oled_p6x8str(50,6,page_buf);
//	  	sprintf(page_buf,"                       ");
//			oled_p6x8str(1,7,page_buf);
			break;
		
		case 3:
			
			switch(key_function_flag)
			{
				case 1:
					sprintf(page_buf,"fun:bizhang  ");	
					ips114_showstr(0,0,page_buf);
					sprintf(page_buf,"%d   ",key_function_flag);	
					ips114_showstr(120,0,page_buf);
					break;
				case 2:
					sprintf(page_buf,"fun:YUAN  ");	
					ips114_showstr(0,0,page_buf);
					sprintf(page_buf,"%d   ",key_function_flag);	
					ips114_showstr(120,0,page_buf);
					break;
				case 3:
					sprintf(page_buf,"fun:speed  ");	
					ips114_showstr(0,0,page_buf);
					sprintf(page_buf,"%d   ",key_function_flag);	
					ips114_showstr(120,0,page_buf);
					break;
				case 4:
					sprintf(page_buf,"fun:cricle_function  ");	
					ips114_showstr(0,0,page_buf);
					sprintf(page_buf,"%d   ",key_function_flag);	
					ips114_showstr(180,0,page_buf);
					break;
			}
			
			sprintf(page_buf,"YUAN:%d   ",cricle_order);	
			ips114_showstr(0,1,page_buf);
			sprintf(page_buf,"bizhang:%d   ",bizhang_order);	
			ips114_showstr(0,2,page_buf);
			sprintf(page_buf,"l-r speed:%.2f   %.2f   ",l_target_speed,r_target_speed);	
			ips114_showstr(0,3,page_buf);
			sprintf(page_buf,"cricle_function:%d   ",cricle_function_switch);						
			ips114_showstr(0,4,page_buf);

//----------------------------------------------------------------	
			break;
		
		
	}
	
}



void IPS(void)
{
	time_counter++;
	ips_counter++;
	if(time_counter > 5)//25ms刷新一次屏幕
	{		
		time_counter = 0;
//		key();
		IPS_page_show();		
		if(ips_counter > 180)//刷新一次屏幕
		{
			ips_counter = 0;
			ips114_clear(WHITE);	
		}
	}

}


