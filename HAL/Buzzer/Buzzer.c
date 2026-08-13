/*
 * Buzzer.c
 *
 *  Created on: Aug 4, 2026
 *      Author: Mohammed Ramadan
 */
#include "../../LIB/BitMath.h"
#include "../../LIB/STd_Types.h"

#include "../../MCAL/DIO/DIO.h"
#include "Buzzer.h"


void HBUZZER_voidInit   (A_u8BuzzerPort , A_u8BuzzerPin)
{
	MDIO_voidInitPin(A_u8BuzzerPort, A_u8BuzzerPin, DIO_OUTPUT) ;
}
void HBUZZER_voidTurnOn    (A_u8BuzzerPort , A_u8BuzzerPin)
{
	MDIO_voidSetPinValue(A_u8BuzzerPort, A_u8BuzzerPin, DIO_HIGH) ;
}
void HBUZZER_voidTurnOff   (A_u8BuzzerPort , A_u8BuzzerPin)
{
	MDIO_voidSetPinValue(A_u8BuzzerPort, A_u8BuzzerPin, DIO_LOW) ;
}
void HBUZZER_voidTogStatus (A_u8BuzzerPort , A_u8BuzzerPin)
{
	MDIO_voidTogPinValue (A_u8BuzzerPort , A_u8BuzzerPin) ;
}

