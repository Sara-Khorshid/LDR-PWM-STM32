#include "stm32f4xx_hal.h"
void comm (char c)
{
	HAL_GPIO_WritePin(GPIOA,0x0f<<4,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,(c&0xf0)<<0,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_RESET);
	HAL_Delay(3);
	
	HAL_GPIO_WritePin(GPIOA,0x0f<<4,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,((c&0x0f)<<4),GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_RESET);
	HAL_Delay(3);
}

void datw (char c)
{
	HAL_GPIO_WritePin(GPIOA,0xf<<4,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,(c&0xf0)<<0,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_RESET);
	HAL_Delay(3);
	
	HAL_GPIO_WritePin(GPIOA,0xf<<4,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,((c&0x0f)<<4),GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_RESET);
	HAL_Delay(3);
}

void lcd_clear(void)
{
	comm(0x01);
}
void lcd_gotoxy(unsigned char x,unsigned char y)
{
	if(y==0) comm(0x80+x);
	if(y==1) comm(0xc0+x);
}

void lcd_putchar(char c)
{
	datw(c);
}

// write the string str located in SRAM to the LCD
void lcd_puts(char *str)
{
char i=0;
while (str[i]!=0) {lcd_putchar(str[i]);i++;}
}

void lcd_init(void)
{
	HAL_Delay(20);
	comm(0x33);
	HAL_Delay(5);
	comm(0x32);
	comm(0x28);
	comm(0x08);
	comm(0x01);
	comm(0x06);
	comm(0x0f);
}
