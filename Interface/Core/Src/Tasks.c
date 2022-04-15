/*
 * Tasks.c
 *
 *  Created on: Mar 27, 2022
 *      Author: viraj
 */

#include "Tasks.h"

void Start_Timer(void *argument)
{
  for(;;)
  {

	#ifdef TIMER_AUTO

	  if ( timer_tog.state == 1 ){
		  HAL_GPIO_WritePin(W6502_TIMER_PORT, W6502_TIMER_PIN, GPIO_PIN_RESET);
		  timer_tog.state = 0;
	  }else{
		  HAL_GPIO_WritePin(W6502_TIMER_PORT, W6502_TIMER_PIN, GPIO_PIN_SET);
		  timer_tog.state = 1;
	  }

	  osDelay( ms_to_ticks( 100 ) );
	  pack_send_uart();

	#else

	  if( timer_tog.state ){
		  HAL_GPIO_WritePin(W6502_TIMER_PORT, W6502_TIMER_PIN, GPIO_PIN_SET);
		  osDelay( ms_to_ticks( 10 ) );

		  if( timer_tog.send_data == 1 ){
			  pack_send_uart();
			  timer_tog.send_data = 0;
		  }
	  }else{
		  HAL_GPIO_WritePin(W6502_TIMER_PORT, W6502_TIMER_PIN, GPIO_PIN_RESET);
	  }

	#endif


  }
}

void Start_Pub_Pin_Read(void *argument)
{

  for(;;)
  {

	  osDelay( ms_to_ticks( 100 ) );
  }
}

void pack_send_uart(void){
	uint16_t pin_reads_addr = 0;
	uint16_t pin_reads_data = 0;

	char new_line = '\n';
	char space_line = ' ';
	char carriage_return = '\r';

	char str_bin_addr[19];
	char str_bin_data[11];
	char str_hex_addr[9];
	char str_hex_data[7];
	char read_or_write[4];

	pin_reads_addr = read_address();
	pin_reads_data = read_data_bus();
	read_or_write[0] = get_read_write();
	read_or_write[1] = ' ';
	read_or_write[2] = ' ';
	read_or_write[3] = '\0';

	//TODO: print out to UART
	int_to_binstring(pin_reads_addr, str_bin_addr, 15);
	int_to_hexstring(pin_reads_addr, str_hex_addr, 5);

	int_to_binstring(pin_reads_data, str_bin_data, 7);
	int_to_hexstring(pin_reads_data, str_hex_data, 3);

	str_bin_addr[16] = '  ';
	str_bin_addr[17] = '  ';
	str_bin_addr[18] = '\0';

	str_bin_data[8] = ' ';
	str_bin_data[9] = ' ';
	str_bin_data[10] = '\0';

	str_hex_addr[6] = ' ';
	str_hex_addr[7] = ' ';
	str_hex_addr[8] = '\0';
	str_hex_addr[1] = 'x';

	str_hex_data[4] = '\r';
	str_hex_data[5] = '\n';
	str_hex_data[6] = '\0';
	str_hex_data[1] = 'x';

	//                                           DONE           DONE           DONE          DONE           DONE
	//sprintf(str_out, "%s\t%s\t%s\t%c\t%s\r\n", str_bin_addr, str_bin_data, str_hex_addr, read_or_write, str_hex_data);
	HAL_UART_Transmit(&huart2, str_bin_addr, strlen(str_bin_addr), HAL_MAX_DELAY);

	HAL_UART_Transmit(&huart2, str_bin_data, strlen(str_bin_data), HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart2, str_hex_addr, strlen(str_hex_addr), HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart2, read_or_write, strlen(read_or_write), HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart2, str_hex_data, strlen(str_hex_data), HAL_MAX_DELAY);

	//HAL_UART_Transmit(&huart2, str_out, strlen(str_out), HAL_MAX_DELAY);


}

