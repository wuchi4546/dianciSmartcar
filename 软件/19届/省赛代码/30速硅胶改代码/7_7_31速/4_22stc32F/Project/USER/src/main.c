/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897(已满)  三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ790875685)
 * @version    		查看doc内version文件 版本说明
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2023-07-27

 ********************************************************************************************************************/
#include "headfile.h"

// 关于内核频率的设定，可以查看board.h文件
// 在board_init中,已经将P54引脚设置为复位
// 如果需要使用P54引脚,可以在board.c文件中的board_init()函数中删除SET_P54_RESRT即可

//char page_buf[60];


int OLED_Open = 1;

void main()
{
	DisableGlobalIRQ();						//关闭EA
	clock_init(SYSTEM_CLOCK_52M);	// 初始化系统频率,勿删除此句代码。
	board_init();					// 初始化寄存器,勿删除此句代码。

    // 此处编写用户代码 例如外设初始化代码等
	car_pre_init();					//智能车外设初始化
	
	pit_timer_ms(TIM_1,5);				// 使用TIMER作为周期中断，时间5ms一次
														// pit周期中断只支持0-10ms
    // 此处编写用户代码 例如外设初始化代码等

	EnableGlobalIRQ();		//开启总中断

	
	
    while(1)
    {
			
//		// 此处编写需要循环执行的代码

			
			key();
			
			IPS();
//			printf("%lf,%lf\n",l_speed,l_target_speed);
			
//					printf("acc.z=%d\r\n",  imu660ra_acc_z);
		//在1.14IPS屏幕上显示，需要初始化1.14寸ips屏幕，才能使用。


    }
}


