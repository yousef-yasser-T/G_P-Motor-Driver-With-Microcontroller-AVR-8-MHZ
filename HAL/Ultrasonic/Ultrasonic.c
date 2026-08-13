/*
 * Ultrasonic.c
 *
 *  Created on: Aug 12, 2026
 *      Author: Mohammed Ramadan
 */
#include "../../LIB/BitMath.h"
#include "../../LIB/STd_Types.h"

#include "../../MCAL/Timer1/Timer1.h"
#include "../../MCAL/DIO/DIO.h"

#include "Ultrasonic.h"
#include <util/delay.h>
void HUltrasonic_voidInit (void)
{
	MDIO_voidInitPin(TRIG_PORT, TRIG_PIN, DIO_OUTPUT) ;
	MTimer1_voidInit(TIMER1_PRESCALLER_8, TIMER1_OVF) ;
}
u32  HUltrasonic_u32CalcDistance (void)
{
	u32 L_u32Distance ;
	MDIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, DIO_HIGH) ;
	_delay_us(60) ;
	MDIO_voidSetPinValue(TRIG_PORT, TRIG_PIN, DIO_LOW) ;
	L_u32Distance = (17300 * MTimer1_u32CalcTonCounts())/1000000.0 ;
	return L_u32Distance ;
}

