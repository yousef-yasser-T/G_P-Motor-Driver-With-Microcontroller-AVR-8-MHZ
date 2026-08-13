/*
 * PB.c
 *
 *  Created on: Aug 4, 2026
 *      Author: Mohammed Ramadan
 */
#include "../../LIB/BitMath.h"
#include "../../LIB/STd_Types.h"

#include "../../MCAL/DIO/DIO.h"

#include "PB.h"
#include <util/delay.h>

void HPB_voidInit (A_u8PbPort , A_u8PbPin)
{
	MDIO_voidInitPin(A_u8PbPort, A_u8PbPin, DIO_INPUT) ;
	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin, DIO_HIGH) ;
}
u8   HPB_u8GetStatues (A_u8PbPort , A_u8PbPin)
{
	u8 L_u8PbStaus ;
	L_u8PbStaus =  MDIO_u8ReadPinValue(A_u8PbPort, A_u8PbPin) ;
	if (L_u8PbStaus == PB_PRESSED)
	{
		_delay_ms(20) ;
		//if (MDIO_u8ReadPinValue(A_u8PbPort, A_u8PbPin) == PB_PRESSED)
		//{
			L_u8PbStaus = PB_PRESSED ;

			_delay_ms(20) ;

		//}
	}else
		{
			L_u8PbStaus = PB_NOT_PRESSED ;
		}

	return L_u8PbStaus ;
}
void HState_voidStateCar(u8 A_u8PbPort, u8 A_u8PbPin, u8 A_u8PbPin1, u8 A_u8PbPin2, u8 A_u8PbPin3, u8 A_u8PbPin4){


	MDIO_voidInitPin(A_u8PbPort, A_u8PbPin1 , DIO_OUTPUT);
	MDIO_voidInitPin(A_u8PbPort, A_u8PbPin2 , DIO_OUTPUT);
	MDIO_voidInitPin(A_u8PbPort, A_u8PbPin3 , DIO_OUTPUT);
	MDIO_voidInitPin(A_u8PbPort, A_u8PbPin4 , DIO_OUTPUT);


	switch(A_u8PbPin){
	    case Forward :
	    	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin1, DIO_HIGH);
			MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin2, DIO_LOW);
			MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin3, DIO_HIGH);
			MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin4, DIO_LOW);
		break;

	    case Backward :
	    	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin1, DIO_LOW);
	    	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin2, DIO_HIGH);
	    	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin3, DIO_LOW);
	    	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin4, DIO_HIGH);
	    break;
	    case Left :
	    	 MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin1, DIO_HIGH);
	    	 MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin2, DIO_LOW);
	    	 MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin3, DIO_LOW);
	    	 MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin4, DIO_HIGH);
	    break;

	    case Right :
	    	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin1, DIO_LOW);
	    	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin2, DIO_HIGH);
	    	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin3, DIO_HIGH);
	    	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin4, DIO_LOW);
	    break;

	    case Stop :
	    	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin1, DIO_LOW);
	    	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin2, DIO_LOW);
	    	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin3, DIO_LOW);
	    	MDIO_voidSetPinValue(A_u8PbPort, A_u8PbPin4, DIO_LOW);
	    break;

	}
}
