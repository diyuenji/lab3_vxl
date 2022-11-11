/*
 * global.c
 *
 *  Created on: Oct 5, 2022
 *      Author: Admin
 */
#include "global.h"

int count1,count2;

int index_led=0 ;
int led_buffer [4]={1,2,3,4};
int status1=0;
int status2=0;
int mode=0;


int key1=0;
int key2=0;

void display7Seg1(int num)
{
	switch(num){
	case 0:
		HAL_GPIO_WritePin ( SEG_1_0_GPIO_Port , SEG_1_0_Pin ,0 ) ;
		HAL_GPIO_WritePin ( SEG_1_1_GPIO_Port , SEG_1_1_Pin ,0 ) ;
		HAL_GPIO_WritePin ( SEG_1_2_GPIO_Port , SEG_1_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_3_GPIO_Port , SEG_1_3_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_4_GPIO_Port , SEG_1_4_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_5_GPIO_Port , SEG_1_5_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_6_GPIO_Port , SEG_1_6_Pin ,1) ;
			break;
	case 1:
		HAL_GPIO_WritePin ( SEG_1_0_GPIO_Port , SEG_1_0_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_1_GPIO_Port , SEG_1_1_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_2_GPIO_Port , SEG_1_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_3_GPIO_Port , SEG_1_3_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_4_GPIO_Port , SEG_1_4_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_5_GPIO_Port , SEG_1_5_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_6_GPIO_Port , SEG_1_6_Pin ,1) ;
		break;
	case 2:
		HAL_GPIO_WritePin ( SEG_1_0_GPIO_Port , SEG_1_0_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_1_GPIO_Port , SEG_1_1_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_2_GPIO_Port , SEG_1_2_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_3_GPIO_Port , SEG_1_3_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_4_GPIO_Port , SEG_1_4_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_5_GPIO_Port , SEG_1_5_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_6_GPIO_Port , SEG_1_6_Pin ,0) ;
		break;
	case 3:
		HAL_GPIO_WritePin ( SEG_1_0_GPIO_Port , SEG_1_0_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_1_GPIO_Port , SEG_1_1_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_2_GPIO_Port , SEG_1_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_3_GPIO_Port , SEG_1_3_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_4_GPIO_Port , SEG_1_4_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_5_GPIO_Port , SEG_1_5_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_6_GPIO_Port , SEG_1_6_Pin ,0) ;
		break;
	case 4:
		HAL_GPIO_WritePin ( SEG_1_0_GPIO_Port , SEG_1_0_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_1_GPIO_Port , SEG_1_1_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_2_GPIO_Port , SEG_1_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_3_GPIO_Port , SEG_1_3_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_4_GPIO_Port , SEG_1_4_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_5_GPIO_Port , SEG_1_5_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_6_GPIO_Port , SEG_1_6_Pin ,0) ;
		break;
	case 5:
		HAL_GPIO_WritePin ( SEG_1_0_GPIO_Port , SEG_1_0_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_1_GPIO_Port , SEG_1_1_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_2_GPIO_Port , SEG_1_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_3_GPIO_Port , SEG_1_3_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_4_GPIO_Port , SEG_1_4_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_5_GPIO_Port , SEG_1_5_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_6_GPIO_Port , SEG_1_6_Pin ,0) ;
		break;
	case 6:
		HAL_GPIO_WritePin ( SEG_1_0_GPIO_Port , SEG_1_0_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_1_GPIO_Port , SEG_1_1_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_2_GPIO_Port , SEG_1_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_3_GPIO_Port , SEG_1_3_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_4_GPIO_Port , SEG_1_4_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_5_GPIO_Port , SEG_1_5_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_6_GPIO_Port , SEG_1_6_Pin ,0) ;
		break;
	case 7:
		HAL_GPIO_WritePin ( SEG_1_0_GPIO_Port , SEG_1_0_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_1_GPIO_Port , SEG_1_1_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_2_GPIO_Port , SEG_1_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_3_GPIO_Port , SEG_1_3_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_4_GPIO_Port , SEG_1_4_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_5_GPIO_Port , SEG_1_5_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_6_GPIO_Port , SEG_1_6_Pin ,1) ;
		break;
	case 8:
		HAL_GPIO_WritePin ( SEG_1_0_GPIO_Port , SEG_1_0_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_1_GPIO_Port , SEG_1_1_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_2_GPIO_Port , SEG_1_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_3_GPIO_Port , SEG_1_3_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_4_GPIO_Port , SEG_1_4_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_5_GPIO_Port , SEG_1_5_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_6_GPIO_Port , SEG_1_6_Pin ,0) ;
		break;
	case 9:
		HAL_GPIO_WritePin ( SEG_1_0_GPIO_Port , SEG_1_0_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_1_GPIO_Port , SEG_1_1_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_2_GPIO_Port , SEG_1_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_3_GPIO_Port , SEG_1_3_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_4_GPIO_Port , SEG_1_4_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_1_5_GPIO_Port , SEG_1_5_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_1_6_GPIO_Port , SEG_1_6_Pin ,0) ;
		break;
	default :
		break;
	}
}

void display7Seg2(int num)
{
	switch(num){
	case 0:
		HAL_GPIO_WritePin ( SEG_2_0_GPIO_Port , SEG_2_0_Pin ,0 ) ;
		HAL_GPIO_WritePin ( SEG_2_1_GPIO_Port , SEG_2_1_Pin ,0 ) ;
		HAL_GPIO_WritePin ( SEG_2_2_GPIO_Port , SEG_2_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_3_GPIO_Port , SEG_2_3_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_4_GPIO_Port , SEG_2_4_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_5_GPIO_Port , SEG_2_5_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_6_GPIO_Port , SEG_2_6_Pin ,1) ;
			break;
	case 1:
		HAL_GPIO_WritePin ( SEG_2_0_GPIO_Port , SEG_2_0_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_1_GPIO_Port , SEG_2_1_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_2_GPIO_Port , SEG_2_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_3_GPIO_Port , SEG_2_3_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_4_GPIO_Port , SEG_2_4_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_5_GPIO_Port , SEG_2_5_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_6_GPIO_Port , SEG_2_6_Pin ,1) ;
		break;
	case 2:
		HAL_GPIO_WritePin ( SEG_2_0_GPIO_Port , SEG_2_0_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_1_GPIO_Port , SEG_2_1_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_2_GPIO_Port , SEG_2_2_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_3_GPIO_Port , SEG_2_3_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_4_GPIO_Port , SEG_2_4_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_5_GPIO_Port , SEG_2_5_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_6_GPIO_Port , SEG_2_6_Pin ,0) ;
		break;
	case 3:
		HAL_GPIO_WritePin ( SEG_2_0_GPIO_Port , SEG_2_0_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_1_GPIO_Port , SEG_2_1_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_2_GPIO_Port , SEG_2_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_3_GPIO_Port , SEG_2_3_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_4_GPIO_Port , SEG_2_4_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_5_GPIO_Port , SEG_2_5_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_6_GPIO_Port , SEG_2_6_Pin ,0) ;
		break;
	case 4:
		HAL_GPIO_WritePin ( SEG_2_0_GPIO_Port , SEG_2_0_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_1_GPIO_Port , SEG_2_1_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_2_GPIO_Port , SEG_2_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_3_GPIO_Port , SEG_2_3_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_4_GPIO_Port , SEG_2_4_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_5_GPIO_Port , SEG_2_5_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_6_GPIO_Port , SEG_2_6_Pin ,0) ;
		break;
	case 5:
		HAL_GPIO_WritePin ( SEG_2_0_GPIO_Port , SEG_2_0_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_1_GPIO_Port , SEG_2_1_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_2_GPIO_Port , SEG_2_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_3_GPIO_Port , SEG_2_3_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_4_GPIO_Port , SEG_2_4_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_5_GPIO_Port , SEG_2_5_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_6_GPIO_Port , SEG_2_6_Pin ,0) ;
		break;
	case 6:
		HAL_GPIO_WritePin ( SEG_2_0_GPIO_Port , SEG_2_0_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_1_GPIO_Port , SEG_2_1_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_2_GPIO_Port , SEG_2_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_3_GPIO_Port , SEG_2_3_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_4_GPIO_Port , SEG_2_4_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_5_GPIO_Port , SEG_2_5_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_6_GPIO_Port , SEG_2_6_Pin ,0) ;
		break;
	case 7:
		HAL_GPIO_WritePin ( SEG_2_0_GPIO_Port , SEG_2_0_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_1_GPIO_Port , SEG_2_1_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_2_GPIO_Port , SEG_2_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_3_GPIO_Port , SEG_2_3_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_4_GPIO_Port , SEG_2_4_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_5_GPIO_Port , SEG_2_5_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_6_GPIO_Port , SEG_2_6_Pin ,1) ;
		break;
	case 8:
		HAL_GPIO_WritePin ( SEG_2_0_GPIO_Port , SEG_2_0_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_1_GPIO_Port , SEG_2_1_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_2_GPIO_Port , SEG_2_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_3_GPIO_Port , SEG_2_3_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_4_GPIO_Port , SEG_2_4_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_5_GPIO_Port , SEG_2_5_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_6_GPIO_Port , SEG_2_6_Pin ,0) ;
		break;
	case 9:
		HAL_GPIO_WritePin ( SEG_2_0_GPIO_Port , SEG_2_0_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_1_GPIO_Port , SEG_2_1_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_2_GPIO_Port , SEG_2_2_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_3_GPIO_Port , SEG_2_3_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_4_GPIO_Port , SEG_2_4_Pin ,1) ;
		HAL_GPIO_WritePin ( SEG_2_5_GPIO_Port , SEG_2_5_Pin ,0) ;
		HAL_GPIO_WritePin ( SEG_2_6_GPIO_Port , SEG_2_6_Pin ,0) ;
		break;
	default :
		break;
	}
}

void update7SEG ( int index ) {
switch ( index ) {
	case 0:
		display7Seg1(led_buffer[0]);
		break ;
	case 1:
		display7Seg1(led_buffer[1]);
		break ;
	case 2:
		display7Seg2(led_buffer[2]);
		break ;
	case 3:
		display7Seg2(led_buffer[3]);
		break ;
	default :
		break ;
	}
}
void updateBuffer(int mode,int value)
{
	led_buffer[0]=mode/10;
	led_buffer[1]=mode%10;
	led_buffer[2]=value/10;
	led_buffer[3]=value%10;
}



