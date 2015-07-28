#include "stm32f30x.h"                  // Device header
/*Led PB13, Button PC13*/

void delay_ms(int delay_time);
void led_init(void);
void led_output(int ledStatus);

int main(){
	led_init();
	while(1){
		led_output(1);
		delay_ms(500);
		led_output(0);
		delay_ms(500);
	}
}


void led_init(void){
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB,ENABLE);
	GPIO_InitTypeDef myGPIO;
	GPIO_StructInit(&myGPIO);
	myGPIO.GPIO_Pin=GPIO_Pin_13;
	myGPIO.GPIO_Mode=GPIO_Mode_OUT;
	myGPIO.GPIO_OType=GPIO_OType_PP;
	myGPIO.GPIO_PuPd=GPIO_PuPd_NOPULL;
	myGPIO.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOB,&myGPIO);
	GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_RESET);
}

void led_output(int ledStatus){
	GPIO_WriteBit(GPIOB,GPIO_Pin_13,ledStatus?Bit_SET:Bit_RESET);
}

void delay_ms(int delay_time){
	for(int i=0; i<(delay_time*2000); i++);
}
