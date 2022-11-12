/*
 * fsm_auto.h
 *
 *  Created on: Nov 1, 2022
 *      Author: Admin
 */

#include "fsm_auto.h"


void fsm_automatic_run(){


	fsm_auto1_run();
	fsm_auto2_run();
	/*if(timer3_flag==1&&key1==1&&key2==1){
		display7Seg1(count1);
		display7Seg2(count2);

		count1--;
		count2--;
		key1=0;
		key2=0;
		setTimer3(time*2);
				}*/




}
void fsm_auto1_run(){

	switch(status1){
		case INIT:
			status1=AUTO_RED;
			setLEDRED1();

			count1=red_val;
			display7Seg1(count1);
			count1--;

			setTimer3(time*2);
			//key1=1;
			setTimer1(red_val*time*2);
			break;
		case AUTO_RED:
			setLEDRED1();
			if(timer1_flag==1){
					count1=green_val;
					status1=AUTO_GREEN;
					//key1=1;
					setTimer1(green_val*time*2);


			}
			//key1=1;
			else if(timer3_flag==1){
					display7Seg1(count1);
					count1--;
					setTimer3(time*2);
			}
			break;
		case AUTO_GREEN:
			setLEDGREEN1();
			if(timer1_flag==1){
				count1=yellow_val;
				status1=AUTO_YELLOW;
				key1=1;
				setTimer1(yellow_val*time*2);
			}
			else if(timer3_flag==1){
				display7Seg1(count1);
				count1--;
				setTimer3(time*2);
			}
			break;
		case AUTO_YELLOW:
			setLEDYELLOW1();
			if(timer1_flag==1){
				count1=red_val;
				status1=AUTO_RED;
				key1=1;
				setTimer1(red_val*time*2);

			}
			else if(timer3_flag==1){
				display7Seg1(count1);
				count1--;
				setTimer3(time*2);
			}
			break;
		default:
			break;
		}


}
void fsm_auto2_run(){
	switch(status2){
		case INIT:
			status2=AUTO_GREEN;
			setLEDGREEN2();

			count2=green_val;
			display7Seg2(count2);
			count2--;
			setTimer2(green_val*time*2);
			setTimer4(time*2);
			key2=1;
			break;
		case AUTO_RED:
			setLEDRED2();
			if(timer2_flag==1){
				count2=green_val;
				status2=AUTO_GREEN;
				key2=1;
				setTimer2(green_val*time*2);

			}
			else if(timer4_flag==1){
				display7Seg2(count2);
				count2--;
				setTimer4(time*2);
			}
			break;
		case AUTO_GREEN:
			setLEDGREEN2();
			if(timer2_flag==1){
				count2=yellow_val;
				status2=AUTO_YELLOW;
				key2=1;
				setTimer2(yellow_val*time*2);
			}
			else if(timer4_flag==1){
				display7Seg2(count2);
				count2--;
				setTimer4(time*2);
			}
			break;
		case AUTO_YELLOW:
			setLEDYELLOW2();
			if(timer2_flag==1){
				count2=red_val;
				status2=AUTO_RED;
				key2=1;
				setTimer2(red_val*time*2);
			}
			else if(timer4_flag==1){
				display7Seg2(count2);
				count2--;
				setTimer4(time*2);
			}
			break;
		default:
			break;
		}

}

