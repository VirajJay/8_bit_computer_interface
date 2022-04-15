/*
 * aux_functions.c
 *
 *  Created on: Mar 27, 2022
 *      Author: viraj
 */
#include "aux_functions.h"

uint16_t read_address(void){
	uint16_t out_int = 0;
	out_int = (uint16_t) HAL_GPIO_ReadPin(W6502_A0_PORT, W6502_A0_PIN);
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A1_PORT, W6502_A1_PIN) << 1 );
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A2_PORT, W6502_A2_PIN) << 2 );
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A3_PORT, W6502_A3_PIN) << 3 );
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A4_PORT, W6502_A4_PIN) << 4 );
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A5_PORT, W6502_A5_PIN) << 5 );
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A6_PORT, W6502_A6_PIN) << 6 );
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A7_PORT, W6502_A7_PIN) << 7 );
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A8_PORT, W6502_A8_PIN) << 8 );
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A9_PORT, W6502_A9_PIN) << 9 );
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A10_PORT, W6502_A10_PIN) << 10 );
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A11_PORT, W6502_A11_PIN) << 11 );
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A12_PORT, W6502_A12_PIN) << 12 );
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A13_PORT, W6502_A13_PIN) << 13 );
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A14_PORT, W6502_A14_PIN) << 14 );
	out_int = out_int | ( (uint16_t) HAL_GPIO_ReadPin(W6502_A15_PORT, W6502_A15_PIN) << 15 );

	return out_int;
}

uint8_t read_data_bus(void){
	uint8_t out_int = 0;
	out_int = (uint8_t) HAL_GPIO_ReadPin(W6502_D0_PORT, W6502_D0_PIN);
	out_int = out_int | ( (uint8_t) HAL_GPIO_ReadPin(W6502_D1_PORT, W6502_D1_PIN) << 1 );
	out_int = out_int | ( (uint8_t) HAL_GPIO_ReadPin(W6502_D2_PORT, W6502_D2_PIN) << 2 );
	out_int = out_int | ( (uint8_t) HAL_GPIO_ReadPin(W6502_D3_PORT, W6502_D3_PIN) << 3 );
	out_int = out_int | ( (uint8_t) HAL_GPIO_ReadPin(W6502_D4_PORT, W6502_D4_PIN) << 4 );
	out_int = out_int | ( (uint8_t) HAL_GPIO_ReadPin(W6502_D5_PORT, W6502_D5_PIN) << 5 );
	out_int = out_int | ( (uint8_t) HAL_GPIO_ReadPin(W6502_D6_PORT, W6502_D6_PIN) << 6 );
	out_int = out_int | ( (uint8_t) HAL_GPIO_ReadPin(W6502_D7_PORT, W6502_D7_PIN) << 7 );

	return out_int;
}

char get_read_write(void){
	if( HAL_GPIO_ReadPin(W6502_RW_PORT, W6502_RW_PIN) == GPIO_PIN_SET ){ // high-state -> reading
		return 'r';
	}else{ // low-state -> writing
		return 'w';
	}
}

uint32_t ms_to_ticks(uint32_t ms_in){
	uint32_t out_ticks;

	//divide by 1000 to convert to ms since frequency is calculated in Hz
	out_ticks = ms_in*(osKernelGetTickFreq()/1000);

	return out_ticks;

}

void int_to_binstring(uint16_t int_in, char *str_out, int str_len){

    uint16_t in_int =  int_in;
    int i=str_len;
    while(in_int!=0){
        if(in_int%2){
            str_out[i] = '1';
        }else{
            str_out[i] = '0';
        }
        in_int = in_int/2;
        i--;
    }
    for(int j=i;j>-1;j--){
        str_out[j] = '0';
    }

}

void int_to_hexstring(uint16_t int_in, char *str_out, int hex_len){

    uint16_t in_int =  int_in;
    int i=hex_len;

    uint16_t tmp_int;

    while(in_int!=0){
        tmp_int = in_int%16;
        switch(tmp_int){
            case 0:
                str_out[i] = '0';
                break;
            case 1:
                str_out[i] = '1';
                break;
            case 2:
                str_out[i] = '2';
                break;
            case 3:
                str_out[i] = '3';
                break;
            case 4:
                str_out[i] = '4';
                break;
            case 5:
                str_out[i] = '5';
                break;
            case 6:
                str_out[i] = '6';
                break;
            case 7:
                str_out[i] = '7';
                break;
            case 8:
                str_out[i] = '8';
                break;
            case 9:
                str_out[i] = '9';
                break;
            case 10:
                str_out[i] = 'A';
                break;
            case 11:
                str_out[i] = 'B';
                break;
            case 12:
                str_out[i] = 'C';
                break;
            case 13:
                str_out[i] = 'D';
                break;
            case 14:
                str_out[i] = 'E';
                break;
            case 15:
                str_out[i] = 'F';
                break;
            default:
                str_out[i] = 'Z';
                break;
        }

        in_int = in_int/16;
        i--;
    }

    for(int j=i;j>-1;j--){
        str_out[j] = '0';
    }

}





