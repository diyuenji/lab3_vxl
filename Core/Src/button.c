/*
 * button.c
 *
 *  Created on: Oct 11, 2022
 *      Author: Admin
 */

#include "button.h"
int Key1Reg0=NORMAL_STATE;
int Key1Reg1=NORMAL_STATE;
int Key1Reg2=NORMAL_STATE;
int Key1Reg3=NORMAL_STATE;

int Key2Reg0=NORMAL_STATE;
int Key2Reg1=NORMAL_STATE;
int Key2Reg2=NORMAL_STATE;
int Key2Reg3=NORMAL_STATE;

int Key3Reg0=NORMAL_STATE;
int Key3Reg1=NORMAL_STATE;
int Key3Reg2=NORMAL_STATE;
int Key3Reg3=NORMAL_STATE;


int TimeOutForKeyPress= 200;
int button1_flag=0;
int button2_flag=0;
int button3_flag=0;

int isButton1Pressed(){
	if(button1_flag==1){
		button1_flag=0;
		return 1;
	}
	return 0;
}
void subKeyProcces1(){
	button1_flag=1;
}

void getKeyInput1(){
	Key1Reg0=Key1Reg1;
	Key1Reg1=Key1Reg2;
	Key1Reg2=HAL_GPIO_ReadPin(BUT1_GPIO_Port, BUT1_Pin);
	if((Key1Reg0==Key1Reg1)&&(Key1Reg1==Key1Reg2)){
		if(Key1Reg2!=Key1Reg3){
			Key1Reg3=Key1Reg2;

			if(Key1Reg2==PRESSED_STATE){
				TimeOutForKeyPress=200;
				subKeyProcces1();
			}
		}
		else{
			TimeOutForKeyPress--;
			if(TimeOutForKeyPress==0){
				Key1Reg3=NORMAL_STATE;
			}
		}
	}

}
int isButton2Pressed(){
	if(button2_flag==1){
		button2_flag=0;
		return 1;
	}
	return 0;
}
void subKeyProcces2(){
	button2_flag=1;
}

void getKeyInput2(){
	Key2Reg0=Key2Reg1;
	Key2Reg1=Key2Reg2;
	Key2Reg2=HAL_GPIO_ReadPin(BUT2_GPIO_Port, BUT2_Pin);
	if((Key2Reg0==Key2Reg1)&&(Key2Reg1==Key2Reg2)){
		if(Key2Reg2!=Key2Reg3){
			Key2Reg3=Key2Reg2;

			if(Key2Reg2==PRESSED_STATE){
				TimeOutForKeyPress=200;
				subKeyProcces2();
			}
		}
		else{
			TimeOutForKeyPress--;
			if(TimeOutForKeyPress==0){
				Key2Reg3=NORMAL_STATE;
			}
		}
	}

}
int isButton3Pressed(){
	if(button3_flag==1){
		button3_flag=0;
		return 1;
	}
	return 0;
}
void subKeyProcces3(){
	button3_flag=1;
}

void getKeyInput3(){
	Key3Reg0=Key3Reg1;
	Key3Reg1=Key3Reg2;
	Key3Reg2=HAL_GPIO_ReadPin(BUT3_GPIO_Port, BUT3_Pin);
	if((Key3Reg0==Key3Reg1)&&(Key3Reg1==Key3Reg2)){
		if(Key3Reg2!=Key3Reg3){
			Key3Reg3=Key3Reg2;

			if(Key3Reg2==PRESSED_STATE){
				TimeOutForKeyPress=200;
				subKeyProcces3();
			}
		}
		else{
			TimeOutForKeyPress--;
			if(TimeOutForKeyPress==0){
				Key3Reg3=NORMAL_STATE;
			}
		}
	}

}

