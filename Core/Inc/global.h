/*
 * global.h
 *
 *  Created on: Oct 5, 2022
 *      Author: Admin
 */
#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "input_proc.h"
#include "traffic.h"
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_



#define INIT 0
#define AUTO_RED 1
#define AUTO_GREEN 2
#define AUTO_YELLOW 3

extern int key1,key2;

extern int count1,count2;

extern int red_val,yellow_val,green_val;

extern int index_led ;
extern int led_buffer [4] ;
extern int status1;
extern int status2;
extern int mode;
extern int time;

extern int red_val;
extern int yellow_val;
extern int green_val;

void display7Seg1(int val);
void display7Seg2(int val);
void updateBuffer(int mode,int value);

#endif /* INC_GLOBAL_H_ */
