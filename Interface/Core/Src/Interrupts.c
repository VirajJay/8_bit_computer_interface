/*
 * Tasks.c
 *
 *  Created on: Apr 14, 2022
 *      Author: viraj
 */

#include "Interrupts.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if( timer_tog.state == 1 ){
		timer_tog.state = 0;
	}else{
		timer_tog.state = 1;
	}
}
