/*
 * aux_functions.h
 *
 *  Created on: Mar 27, 2022
 *      Author: viraj
 */

#ifndef INC_AUX_FUNCTIONS_H_
#define INC_AUX_FUNCTIONS_H_

#include "main.h"
#include "cmsis_os.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>

//Address Pins
#define W6502_A0_PORT	GPIOA
#define W6502_A1_PORT	GPIOA
#define W6502_A2_PORT	GPIOA
#define W6502_A3_PORT	GPIOB
#define W6502_A4_PORT	GPIOC
#define W6502_A5_PORT	GPIOC
#define W6502_A6_PORT	GPIOA
#define W6502_A7_PORT	GPIOB
#define W6502_A8_PORT	GPIOB
#define W6502_A9_PORT	GPIOB
#define W6502_A10_PORT	GPIOA
#define W6502_A11_PORT	GPIOA
#define W6502_A12_PORT	GPIOC
#define W6502_A13_PORT	GPIOB
#define W6502_A14_PORT	GPIOA
#define W6502_A15_PORT	GPIOA

#define W6502_A0_PIN	GPIO_PIN_0
#define W6502_A1_PIN 	GPIO_PIN_1
#define W6502_A2_PIN	GPIO_PIN_4
#define W6502_A3_PIN	GPIO_PIN_0
#define W6502_A4_PIN	GPIO_PIN_1
#define W6502_A5_PIN	GPIO_PIN_0
#define W6502_A6_PIN	GPIO_PIN_10
#define W6502_A7_PIN	GPIO_PIN_5
#define W6502_A8_PIN	GPIO_PIN_4
#define W6502_A9_PIN	GPIO_PIN_10
#define W6502_A10_PIN	GPIO_PIN_8
#define W6502_A11_PIN	GPIO_PIN_9
#define W6502_A12_PIN	GPIO_PIN_7
#define W6502_A13_PIN	GPIO_PIN_6
#define W6502_A14_PIN	GPIO_PIN_7
#define W6502_A15_PIN	GPIO_PIN_6

//Data bus
#define W6502_D0_PORT	GPIOA
#define W6502_D1_PORT	GPIOA
#define W6502_D2_PORT	GPIOB
#define W6502_D3_PORT	GPIOB
#define W6502_D4_PORT	GPIOB
#define W6502_D5_PORT	GPIOB
#define W6502_D6_PORT	GPIOB
#define W6502_D7_PORT	GPIOB

#define W6502_D0_PIN	GPIO_PIN_12
#define W6502_D1_PIN	GPIO_PIN_11
#define W6502_D2_PIN	GPIO_PIN_12
#define W6502_D3_PIN	GPIO_PIN_2
#define W6502_D4_PIN	GPIO_PIN_1
#define W6502_D5_PIN	GPIO_PIN_15
#define W6502_D6_PIN	GPIO_PIN_14
#define W6502_D7_PIN	GPIO_PIN_13

//Read_Write Bit
#define W6502_RW_PORT	GPIOC
#define W6502_RW_PIN	GPIO_PIN_6

#define W6502_TIMER_PORT	GPIOA
#define W6502_TIMER_PIN		GPIO_PIN_5

//Function Prototypes
uint16_t read_address(void);
uint8_t read_data_bus(void);
uint32_t ms_to_ticks(uint32_t ms_in);
void int_to_binstring(uint16_t int_in, char *str_out, int str_len);
void int_to_hexstring(uint16_t int_in, char *str_out, int hex_len);

#endif /* INC_AUX_FUNCTIONS_H_ */
