/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897(����)  ��Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ790875685)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32G12K128
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-12-18
 ********************************************************************************************************************/

#include "headfile.h"


/*
 * ϵͳƵ�ʣ��ɲ鿴board.h�е� FOSC �궨���޸ġ�
 * board.h�ļ���FOSC��ֵ����Ϊ0,������Զ�����ϵͳƵ��Ϊ33.1776MHZ
 * ��board_init��,�Ѿ���P54��������Ϊ��λ
 * �����Ҫʹ��P54����,������board.c�ļ��е�board_init()������ɾ��SET_P54_RESRT����
 */

char r_speed=0.0,l_speed=0.0;
char page_buf[60];
char circle_L=0;
int time_counter = 0; //��Ļˢ��
int ips_counter = 0; //��Ļ����
int IPS_test=10;

void IPS(void);

void IPS(void)
{
	time_counter++;
	ips_counter++;
	
	if(time_counter > 5)//25msˢ��һ����Ļ
	{		
		time_counter = 0;
		ips114_showint16(0,0,IPS_test);
		sprintf(page_buf,"L:%d ",r_speed);						
		if(ips_counter > 180)//ˢ��һ����Ļ
		{
			ips_counter = 0;
			ips114_clear(WHITE);	
		}
	}

}

void main()
{
	board_init();			// ��ʼ���Ĵ���,��ɾ���˾���롣
	lcd_init(); 
  lcd_clear(WHITE); 
	


	while(1)
	{
		
		lcd_showstr(0, 180, "RAMP_NONE ");


		delay_ms(500);
		P52 = !P52;
		

		
    }
}

