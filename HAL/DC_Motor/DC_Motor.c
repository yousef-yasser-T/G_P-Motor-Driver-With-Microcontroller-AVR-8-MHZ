/*
 * DC_Motor.c
 *
 *  Created on: Aug 6, 2026
 *      Author: Mohammed Ramadan
 */

#include "../../LIB/BitMath.h"
#include "../../LIB/STd_Types.h"

#include "../../MCAL/DIO/DIO.h"
#include "DC_Motor.h"

void HDCM_voidInit (u8 A_u8DCMPort , u8 A_u8Pin1Pin , u8 A_u8Pin2Pin)
{
	MDIO_voidInitPin(A_u8DCMPort, A_u8Pin1Pin, DIO_OUTPUT) ;
	MDIO_voidInitPin(A_u8DCMPort, A_u8Pin2Pin, DIO_OUTPUT) ;
}
void HDCM_voidStop (u8 A_u8DCMPort , u8 A_u8Pin1Pin , u8 A_u8Pin2Pin)
{
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin1Pin, DIO_LOW) ;
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin2Pin, DIO_LOW) ;
}
void HDCM_voidCW   (u8 A_u8DCMPort , u8 A_u8Pin1Pin , u8 A_u8Pin2Pin)
{
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin1Pin, DIO_HIGH) ;
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin2Pin, DIO_LOW) ;
}
void HDCM_voidCCW  (u8 A_u8DCMPort , u8 A_u8Pin1Pin , u8 A_u8Pin2Pin)
{
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin1Pin, DIO_LOW) ;
	MDIO_voidSetPinValue(A_u8DCMPort, A_u8Pin2Pin, DIO_HIGH) ;
}
