/*
 * fsm.c
 *
 *  Created on: Nov 1, 2022
 *      Author: Admin
 */
#include "fsm.h"
//#include"main.c"
int red_val=5;
int yellow_val=2;
int green_val=3;


int RED_INC=0;
int YELLOW_INC=0;
int GREEN_INC=0;


void fsm(){
	switch(mode){
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
			fsm_automatic_run();
			if(isButton1Pressed()){
					setTimer1(time);
					HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
					HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port , LED_GREEN1_Pin ,1) ;
					HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port , LED_YELLOW1_Pin ,1) ;
					HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port , LED_GREEN2_Pin ,1) ;
					HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port , LED_YELLOW2_Pin ,1) ;
					HAL_GPIO_WritePin(LED_RED1_GPIO_Port , LED_RED1_Pin ,1) ;
					HAL_GPIO_WritePin(LED_RED2_GPIO_Port , LED_RED2_Pin ,1) ;
					mode++;
					updateBuffer(mode+1, red_val);

			}


			break;

		case 1:
			if(isButton2Pressed()){
				RED_INC++;
				updateBuffer(mode+1, red_val+RED_INC);
			}
			if(timer1_flag==1){
					  			switch(index_led){
					  				case 0:
					  					HAL_GPIO_WritePin ( EN0_GPIO_Port , EN0_Pin ,0) ;
					  					HAL_GPIO_WritePin ( EN1_GPIO_Port , EN1_Pin ,1) ;
					  					HAL_GPIO_WritePin ( EN2_GPIO_Port , EN2_Pin ,0) ;
					  					HAL_GPIO_WritePin ( EN3_GPIO_Port , EN3_Pin ,1) ;
					  					display7Seg1(led_buffer[index_led]);
					  					display7Seg2(led_buffer[index_led+2]);
					  					index_led++;
					  					break;
					  				case 1:
					  					HAL_GPIO_WritePin ( EN0_GPIO_Port , EN0_Pin ,1) ;
					  					HAL_GPIO_WritePin ( EN1_GPIO_Port , EN1_Pin ,0) ;
					  					HAL_GPIO_WritePin ( EN2_GPIO_Port , EN2_Pin ,1) ;
					  					HAL_GPIO_WritePin ( EN3_GPIO_Port , EN3_Pin ,0) ;
					  					display7Seg1(led_buffer[index_led]);
					  					display7Seg2(led_buffer[index_led+2]);
					  					index_led=0;
					  					break;
					  				default:
					  					break; }
					  			//display7Seg1(led_buffer[]);
					  			HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
					  			HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
					  			setTimer1(time);

			}
			if(isButton3Pressed()){
					red_val+=RED_INC;
					updateBuffer(2, red_val);
					RED_INC=0;
			}


			if(isButton1Pressed()){
				HAL_GPIO_WritePin(LED_RED1_GPIO_Port , LED_RED1_Pin ,1) ;
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port , LED_RED2_Pin ,1) ;
				mode++;
				updateBuffer(mode+1, yellow_val);
				setTimer1(time);
			}
			break;
		case 2:
			if(isButton2Pressed()){
				YELLOW_INC++;
				updateBuffer(mode+1, yellow_val+YELLOW_INC);
			}
			if(timer1_flag==1){
				switch(index_led){
					case 0:
						HAL_GPIO_WritePin ( EN0_GPIO_Port , EN0_Pin ,0) ;
						HAL_GPIO_WritePin ( EN1_GPIO_Port , EN1_Pin ,1) ;
	 					HAL_GPIO_WritePin ( EN2_GPIO_Port , EN2_Pin ,0) ;
						HAL_GPIO_WritePin ( EN3_GPIO_Port , EN3_Pin ,1) ;
						display7Seg1(led_buffer[index_led]);
						display7Seg2(led_buffer[index_led+2]);
						index_led++;
						break;
					case 1:
					  	HAL_GPIO_WritePin ( EN0_GPIO_Port , EN0_Pin ,1) ;
					  	HAL_GPIO_WritePin ( EN1_GPIO_Port , EN1_Pin ,0) ;
						HAL_GPIO_WritePin ( EN2_GPIO_Port , EN2_Pin ,1) ;
	 					HAL_GPIO_WritePin ( EN3_GPIO_Port , EN3_Pin ,0) ;
					  	display7Seg1(led_buffer[index_led]);
						display7Seg2(led_buffer[index_led+2]);
					  	index_led=0;
						break;
					default:
					  	break; }
					  			//display7Seg1(led_buffer[]);
					  	HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
					  	HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
					  	setTimer1(time);
			}
			if(isButton3Pressed()){
				yellow_val+=YELLOW_INC;
				updateBuffer(mode+1, yellow_val);
				YELLOW_INC=0;
			}
			if(isButton1Pressed()){
				HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port , LED_YELLOW1_Pin ,1) ;
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port , LED_YELLOW2_Pin ,1) ;
				mode++;
				updateBuffer(mode+1, green_val);
				setTimer1(time);
			}
			break;
		case 3:
			if(isButton2Pressed()){
				GREEN_INC++;
				updateBuffer(mode+1, green_val+GREEN_INC);
						}
			if(timer1_flag==1){
				switch(index_led){
	  				case 0:
	  					HAL_GPIO_WritePin ( EN0_GPIO_Port , EN0_Pin ,0) ;
					  	HAL_GPIO_WritePin ( EN1_GPIO_Port , EN1_Pin ,1) ;
					  	HAL_GPIO_WritePin ( EN2_GPIO_Port , EN2_Pin ,0) ;
					  	HAL_GPIO_WritePin ( EN3_GPIO_Port , EN3_Pin ,1) ;
					  	display7Seg1(led_buffer[index_led]);
					  	display7Seg2(led_buffer[index_led+2]);
					  	index_led++;
					  	break;
					case 1:
	 					HAL_GPIO_WritePin ( EN0_GPIO_Port , EN0_Pin ,1) ;
					  	HAL_GPIO_WritePin ( EN1_GPIO_Port , EN1_Pin ,0) ;
						HAL_GPIO_WritePin ( EN2_GPIO_Port , EN2_Pin ,1) ;
				  		HAL_GPIO_WritePin ( EN3_GPIO_Port , EN3_Pin ,0) ;
						display7Seg1(led_buffer[index_led]);
						display7Seg2(led_buffer[index_led+2]);
						index_led=0;
						break;
					default:
						break; }
					  			//display7Seg1(led_buffer[]);
				HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
				HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
	 			setTimer1(time);
			}
			if(isButton3Pressed()){
				green_val+=GREEN_INC;
				updateBuffer(mode+1, green_val);
				GREEN_INC=0;
			}
			if(isButton1Pressed()){
				HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port , LED_GREEN1_Pin ,1) ;
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port , LED_GREEN2_Pin ,1) ;
				setTimer1(red_val*time*2);
				setTimer2(green_val*time*2);
				status1=AUTO_RED;
				status2=AUTO_GREEN;
				count1=red_val;
				count2=green_val;
				key1=1;
				key2=1;
				mode=0;}
			break;
		default:
			break;

	}
}

