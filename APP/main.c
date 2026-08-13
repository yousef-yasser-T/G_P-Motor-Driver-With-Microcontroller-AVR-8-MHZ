/*
 * main.c
 *
 *  Created on: Aug 4, 2026
 *      Author: Mohammed Ramadan
 */
#include "../LIB/BitMath.h"
#include "../LIB/STd_Types.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Ultrasonic/Ultrasonic.h"
#include "../HAL/Buzzer/Buzzer.h"
#include "../HAL/DC_Motor/DC_Motor.h"
#include "../HAL/PB/PB.h"


#include <util/delay.h>




void main (void)
{
	u32 L_u32Dis ;
	u8 L_u8Pin1Val;
	u8 L_u8Pin2Val;
	u8 L_u8Pin3Val;
	u8 L_u8Pin4Val;
	HLCD_voidInit() ;
	HUltrasonic_voidInit() ;
	HDCM_voidInit(DIO_PORTC, DIO_PIN4, DIO_PIN5) ;
	HDCM_voidInit(DIO_PORTC, DIO_PIN6, DIO_PIN7) ;
	HBUZZER_voidInit(DIO_PORTD, DIO_PIN5) ;
	HPB_voidInit(DIO_PORTC, DIO_PIN0) ;
	HPB_voidInit(DIO_PORTC, DIO_PIN1) ;
	HPB_voidInit(DIO_PORTC, DIO_PIN2) ;
	HPB_voidInit(DIO_PORTC, DIO_PIN3) ;

	while (1)
	{
		HLCD_voidClrDisplay();
		HLCD_voidMoveCursor(LCD_ROW0, LCD_COL0) ;
		HLCD_voidDisplayStr("Distance=") ;
		L_u32Dis = HUltrasonic_u32CalcDistance() ;
		HLCd_voidSendData((L_u32Dis/10) + '0') ;
		HLCd_voidSendData((L_u32Dis%10) + '0') ;
		HLCD_voidDisplayStr("cm") ;

		L_u8Pin1Val = PB_NOT_PRESSED;
		L_u8Pin2Val = PB_NOT_PRESSED;
		L_u8Pin3Val = PB_NOT_PRESSED;
		L_u8Pin4Val = PB_NOT_PRESSED;


		L_u8Pin1Val = HPB_u8GetStatues(DIO_PORTC, DIO_PIN0) ;
		L_u8Pin2Val = HPB_u8GetStatues(DIO_PORTC, DIO_PIN1) ;
		L_u8Pin3Val = HPB_u8GetStatues(DIO_PORTC, DIO_PIN2) ;
		L_u8Pin4Val = HPB_u8GetStatues(DIO_PORTC, DIO_PIN3) ;



		if(L_u32Dis >= 20){
		if (L_u8Pin1Val == PB_PRESSED){

			        HDCM_voidCW (DIO_PORTC , DIO_PIN4 , DIO_PIN5);
			        HDCM_voidCW (DIO_PORTC , DIO_PIN6 , DIO_PIN7);

			        HLCD_voidMoveCursor(LCD_ROW1, LCD_COL0) ;
			        HLCD_voidDisplayStr("Forward") ;

		}
		else if (L_u8Pin2Val == PB_PRESSED){
			        HDCM_voidCCW (DIO_PORTC , DIO_PIN4 , DIO_PIN5);
			        HDCM_voidCCW (DIO_PORTC , DIO_PIN6 , DIO_PIN7);
					HLCD_voidMoveCursor(LCD_ROW1, LCD_COL0) ;
					HLCD_voidDisplayStr("Backward") ;
				}
		else if (L_u8Pin3Val == PB_PRESSED){
			        HDCM_voidCW (DIO_PORTC , DIO_PIN4 , DIO_PIN5);
			        HDCM_voidStop (DIO_PORTC , DIO_PIN6 , DIO_PIN7) ;
					HLCD_voidMoveCursor(LCD_ROW1, LCD_COL0) ;
					HLCD_voidDisplayStr("Left") ;
				}
		else if (L_u8Pin4Val == PB_PRESSED){
			        HDCM_voidCCW (DIO_PORTC , DIO_PIN6 , DIO_PIN7);
			        HDCM_voidStop (DIO_PORTC , DIO_PIN4 , DIO_PIN5) ;
					HLCD_voidMoveCursor(LCD_ROW1, LCD_COL0) ;
					HLCD_voidDisplayStr("Right") ;
				}
		else{
					        //HBUZZER_voidTogStatus(DIO_PORTD, DIO_PIN5) ;
					        HDCM_voidStop (DIO_PORTC , DIO_PIN4 , DIO_PIN5) ;
					        HDCM_voidStop (DIO_PORTC , DIO_PIN6 , DIO_PIN7) ;
							HLCD_voidMoveCursor(LCD_ROW1, LCD_COL0) ;
							HLCD_voidDisplayStr("Stop") ;
				}

		}else{
			        //HBUZZER_voidTogStatus(DIO_PORTD, DIO_PIN5) ;
			        HDCM_voidStop (DIO_PORTC , DIO_PIN4 , DIO_PIN5) ;
			        HDCM_voidStop (DIO_PORTC , DIO_PIN6 , DIO_PIN7) ;
					HLCD_voidMoveCursor(LCD_ROW1, LCD_COL0) ;
					HLCD_voidDisplayStr("Stop") ;
		}
		if(L_u32Dis <= 20){
			 HBUZZER_voidTurnOn(DIO_PORTD, DIO_PIN5) ;
				}
		else{
			HBUZZER_voidTurnOff(DIO_PORTD, DIO_PIN5) ;
		}
		        _delay_ms(2000) ;
				HLCD_voidClrDisplay() ;

	}
}
