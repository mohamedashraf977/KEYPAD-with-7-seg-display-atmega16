/*
 * main.c
 *
 * Created: 20-Nov-21 5:22:30 PM
 *  Author: Mohamed Ashraf
 */ 

#include <xc.h>
#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"
uint8 i;
uint8 result=0;
int main(void)
{
	/* PORTA config I/P of keypad rows*/
	DDRA&=0xF0;			//Input pins
	PORTA|=0x0F;		//internal pull up resistors
	
	/* PORTA config O/P of keypad colomns*/
	DDRA|=0xF0;			//Output pins
	PORTA&=0xFF;		//initally zeros
	SET_BIT(PORTA,6);
	
	/*PORTC config O/P of 7-seg*/
	DDRC|=0x0F;
	PORTC=0x00;
	
	
    while(1)
    {
			for (i=4;i<=6;i++)
			{
				CLEAR_BIT(PORTA,i);
				
				if(BIT_IS_CLEAR(PINA,0))
				{
					if (i==4)
						result=1;
					if(i==5)
						result=2;
					if(i==6)
						result=3;
						
					PORTC=result;
					_delay_ms(200);

				}
				
				if(BIT_IS_CLEAR(PINA,1))
				{
							
					if (i==4)
					result=4;
					if(i==5)
					result=5;
					if(i==6)
					result=6;
					
					PORTC=result;
					_delay_ms(200);
				}
						
				if(BIT_IS_CLEAR(PINA,2))
				{
									
					if (i==4)
					result=7;
					if(i==5)
					result=8;
					if(i==6)
					result=9;
					
					PORTC=result;
					_delay_ms(200);
				}
				if(BIT_IS_CLEAR(PINA,3))
				{
									
					if(i==5)
					{
						result=0;
					}
					
					PORTC=result;
					_delay_ms(200);
				}

							SET_BIT(PORTA,i);
			}

    }
}