/*
 * Timer1.c
 *
 *  Created on: Aug 11, 2026
 *      Author: Mohammed Ramadan
 */
#include "../../LIB/BitMath.h"
#include "../../LIB/STd_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "Timer1.h"
u32 G_u32Counter ;
u32 G_u32Prescaller ;
void (*Timer1_ptr)(void) ;

void MTimer1_voidInit (u16 A_u16Prescaller , u8 A_u8Mode)
{
	G_u32Prescaller = A_u16Prescaller ;
	switch (A_u16Prescaller)
	{
	case  TIMER1_PRESCALLER_1    :
		SET_BIT(TCCR1B , 0) ;
		CLR_BIT(TCCR1B , 1) ;
		CLR_BIT(TCCR1B , 2) ;
		break ;
	case  TIMER1_PRESCALLER_8    :
		CLR_BIT(TCCR1B , 0) ;
		SET_BIT(TCCR1B , 1) ;
		CLR_BIT(TCCR1B , 2) ;
		break ;
	case  TIMER1_PRESCALLER_64   :
		SET_BIT(TCCR1B , 0) ;
		SET_BIT(TCCR1B , 1) ;
		CLR_BIT(TCCR1B , 2) ;
		break ;
	case  TIMER1_PRESCALLER_256  :
		CLR_BIT(TCCR1B , 0) ;
		CLR_BIT(TCCR1B , 1) ;
		SET_BIT(TCCR1B , 2) ;
		break ;
	case  TIMER1_PRESCALLER_1024 :
		SET_BIT(TCCR1B , 0) ;
		CLR_BIT(TCCR1B , 1) ;
		SET_BIT(TCCR1B , 2) ;
		break ;
	}

	switch (A_u8Mode)
	{
	case  TIMER1_OVF                         :
		CLR_BIT(TCCR1A , 0) ;
		CLR_BIT(TCCR1A , 1) ;
		CLR_BIT(TCCR1B , 3) ;
		CLR_BIT(TCCR1B , 4) ;

		SET_BIT(SREG , 7) ;
		SET_BIT(TIMSK , 2) ;
		break ;
	case  TIMER1_PWM_PHASE_CORRECT_8BIT      :
		SET_BIT(TCCR1A , 0) ;
		CLR_BIT(TCCR1A , 1) ;
		CLR_BIT(TCCR1B , 3) ;
		CLR_BIT(TCCR1B , 4) ;

		MDIO_voidInitPin(DIO_PORTD, DIO_PIN4, DIO_OUTPUT) ;
		MDIO_voidInitPin(DIO_PORTD, DIO_PIN5, DIO_OUTPUT) ;
		CLR_BIT(TCCR1A , 4) ;
		SET_BIT(TCCR1A , 5) ;
		CLR_BIT(TCCR1A , 6) ;
		SET_BIT(TCCR1A , 7) ;
		break ;
	case  TIMER1_PWM_PHASE_CORRECT_9BIT      :
		CLR_BIT(TCCR1A , 0) ;
		SET_BIT(TCCR1A , 1) ;
		CLR_BIT(TCCR1B , 3) ;
		CLR_BIT(TCCR1B , 4) ;

		MDIO_voidInitPin(DIO_PORTD, DIO_PIN4, DIO_OUTPUT) ;
		MDIO_voidInitPin(DIO_PORTD, DIO_PIN5, DIO_OUTPUT) ;
		CLR_BIT(TCCR1A , 4) ;
		SET_BIT(TCCR1A , 5) ;
		CLR_BIT(TCCR1A , 6) ;
		SET_BIT(TCCR1A , 7) ;
		break ;
	case  TIMER1_PWM_PHASE_CORRECT_10BIT     :
		SET_BIT(TCCR1A , 0) ;
		SET_BIT(TCCR1A , 1) ;
		CLR_BIT(TCCR1B , 3) ;
		CLR_BIT(TCCR1B , 4) ;

		MDIO_voidInitPin(DIO_PORTD, DIO_PIN4, DIO_OUTPUT) ;
		MDIO_voidInitPin(DIO_PORTD, DIO_PIN5, DIO_OUTPUT) ;
		CLR_BIT(TCCR1A , 4) ;
		SET_BIT(TCCR1A , 5) ;
		CLR_BIT(TCCR1A , 6) ;
		SET_BIT(TCCR1A , 7) ;
		break ;
	case  TIMER1_CTC_OCR1A_TOP               :
		CLR_BIT(TCCR1A , 0) ;
		CLR_BIT(TCCR1A , 1) ;
		SET_BIT(TCCR1B , 3) ;
		CLR_BIT(TCCR1B , 4) ;
		break ;
	case  TIMER1_PWM_FAST_8BIT               :
		SET_BIT(TCCR1A , 0) ;
		CLR_BIT(TCCR1A , 1) ;
		SET_BIT(TCCR1B , 3) ;
		CLR_BIT(TCCR1B , 4) ;

		MDIO_voidInitPin(DIO_PORTD, DIO_PIN4, DIO_OUTPUT) ;
		MDIO_voidInitPin(DIO_PORTD, DIO_PIN5, DIO_OUTPUT) ;
		CLR_BIT(TCCR1A , 4) ;
		SET_BIT(TCCR1A , 5) ;
		CLR_BIT(TCCR1A , 6) ;
		SET_BIT(TCCR1A , 7) ;
		break ;
	case  TIMER1_PWM_FAST_9BIT               :
		CLR_BIT(TCCR1A , 0) ;
		SET_BIT(TCCR1A , 1) ;
		SET_BIT(TCCR1B , 3) ;
		CLR_BIT(TCCR1B , 4) ;

		MDIO_voidInitPin(DIO_PORTD, DIO_PIN4, DIO_OUTPUT) ;
		MDIO_voidInitPin(DIO_PORTD, DIO_PIN5, DIO_OUTPUT) ;
		CLR_BIT(TCCR1A , 4) ;
		SET_BIT(TCCR1A , 5) ;
		CLR_BIT(TCCR1A , 6) ;
		SET_BIT(TCCR1A , 7) ;
		break ;
	case  TIMER1_PWM_FAST_10BIT              :
		SET_BIT(TCCR1A , 0) ;
		SET_BIT(TCCR1A , 1) ;
		SET_BIT(TCCR1B , 3) ;
		CLR_BIT(TCCR1B , 4) ;

		MDIO_voidInitPin(DIO_PORTD, DIO_PIN4, DIO_OUTPUT) ;
		MDIO_voidInitPin(DIO_PORTD, DIO_PIN5, DIO_OUTPUT) ;
		CLR_BIT(TCCR1A , 4) ;
		SET_BIT(TCCR1A , 5) ;
		CLR_BIT(TCCR1A , 6) ;
		SET_BIT(TCCR1A , 7) ;
		break ;
	case  TIMER1_FREQUANCY_CORRECT_ICR1_TOP  :
		CLR_BIT(TCCR1A , 0) ;
		CLR_BIT(TCCR1A , 1) ;
		CLR_BIT(TCCR1B , 3) ;
		SET_BIT(TCCR1B , 4) ;

		MDIO_voidInitPin(DIO_PORTD, DIO_PIN4, DIO_OUTPUT) ;
		MDIO_voidInitPin(DIO_PORTD, DIO_PIN5, DIO_OUTPUT) ;
		CLR_BIT(TCCR1A , 4) ;
		SET_BIT(TCCR1A , 5) ;
		CLR_BIT(TCCR1A , 6) ;
		SET_BIT(TCCR1A , 7) ;
		break ;
	case  TIMER1_FREQUANCY_CORRECT_OCR1A_TOP :
		SET_BIT(TCCR1A , 0) ;
		CLR_BIT(TCCR1A , 1) ;
		CLR_BIT(TCCR1B , 3) ;
		SET_BIT(TCCR1B , 4) ;

		MDIO_voidInitPin(DIO_PORTD, DIO_PIN4, DIO_OUTPUT) ;
		MDIO_voidInitPin(DIO_PORTD, DIO_PIN5, DIO_OUTPUT) ;
		CLR_BIT(TCCR1A , 4) ;
		SET_BIT(TCCR1A , 5) ;
		CLR_BIT(TCCR1A , 6) ;
		SET_BIT(TCCR1A , 7) ;
		break ;
	case  TIMER1_PHASE_CORRECT_ICR1_TOP      :
		CLR_BIT(TCCR1A , 0) ;
		SET_BIT(TCCR1A , 1) ;
		CLR_BIT(TCCR1B , 3) ;
		SET_BIT(TCCR1B , 4) ;

		MDIO_voidInitPin(DIO_PORTD, DIO_PIN4, DIO_OUTPUT) ;
		MDIO_voidInitPin(DIO_PORTD, DIO_PIN5, DIO_OUTPUT) ;
		CLR_BIT(TCCR1A , 4) ;
		SET_BIT(TCCR1A , 5) ;
		CLR_BIT(TCCR1A , 6) ;
		SET_BIT(TCCR1A , 7) ;
		break ;
	case  TIMER1_PHASE_CORRECT_OCR1A_TOP     :
		SET_BIT(TCCR1A , 0) ;
		SET_BIT(TCCR1A , 1) ;
		CLR_BIT(TCCR1B , 3) ;
		SET_BIT(TCCR1B , 4) ;

		MDIO_voidInitPin(DIO_PORTD, DIO_PIN4, DIO_OUTPUT) ;
		MDIO_voidInitPin(DIO_PORTD, DIO_PIN5, DIO_OUTPUT) ;
		CLR_BIT(TCCR1A , 4) ;
		SET_BIT(TCCR1A , 5) ;
		CLR_BIT(TCCR1A , 6) ;
		SET_BIT(TCCR1A , 7) ;
		break ;
	case  TIMER1_CTC_ICR1_TOP                :
		CLR_BIT(TCCR1A , 0) ;
		CLR_BIT(TCCR1A , 1) ;
		SET_BIT(TCCR1B , 3) ;
		SET_BIT(TCCR1B , 4) ;
		break ;
	case  TIMER1_FAST_ICR1_TOP               :
		CLR_BIT(TCCR1A , 0) ;
		SET_BIT(TCCR1A , 1) ;
		SET_BIT(TCCR1B , 3) ;
		SET_BIT(TCCR1B , 4) ;

		MDIO_voidInitPin(DIO_PORTD, DIO_PIN4, DIO_OUTPUT) ;
		MDIO_voidInitPin(DIO_PORTD, DIO_PIN5, DIO_OUTPUT) ;
		CLR_BIT(TCCR1A , 4) ;
		SET_BIT(TCCR1A , 5) ;
		CLR_BIT(TCCR1A , 6) ;
		SET_BIT(TCCR1A , 7) ;
		break ;
	case  TIMER1_FAST_OCR1A_TOP              :
		SET_BIT(TCCR1A , 0) ;
		SET_BIT(TCCR1A , 1) ;
		SET_BIT(TCCR1B , 3) ;
		SET_BIT(TCCR1B , 4) ;

		MDIO_voidInitPin(DIO_PORTD, DIO_PIN4, DIO_OUTPUT) ;
		MDIO_voidInitPin(DIO_PORTD, DIO_PIN5, DIO_OUTPUT) ;
		CLR_BIT(TCCR1A , 4) ;
		SET_BIT(TCCR1A , 5) ;
		CLR_BIT(TCCR1A , 6) ;
		SET_BIT(TCCR1A , 7) ;
		break ;
	}

}
void MTimer1_voidSetDesiredTime (u32 A_u32DisiredTimeInMicro , void (*fptr)(void))
{
	u32 L_u32OverFlowTime = 8192 * G_u32Prescaller ;
	f32 L_f32DesiredOvfCounts =A_u32DisiredTimeInMicro / L_u32OverFlowTime ;
	u32 L_u32PreloadValue ;
	Timer1_ptr = fptr ;
	if (L_f32DesiredOvfCounts < 1.0)
	{
		G_u32Counter = 1 ;
		L_u32PreloadValue = 65535 - 65535*L_f32DesiredOvfCounts ;
		TCNT1 = L_u32PreloadValue ;
	}
	else if (L_f32DesiredOvfCounts == 1.0)
	{
		G_u32Counter = 1 ;
	}
	else if (L_f32DesiredOvfCounts > 1.0)
	{
		G_u32Counter = L_f32DesiredOvfCounts ;
		if ((L_f32DesiredOvfCounts - (u32)L_f32DesiredOvfCounts) != 0)
		{
			G_u32Counter ++ ;
			L_u32PreloadValue = 65535 - 65535*((L_f32DesiredOvfCounts - (u32)L_f32DesiredOvfCounts)) ;
			TCNT1 = L_u32PreloadValue ;
		}
	}
}
void MTimer1_voidGenetatePWMA (u8 A_u8CompareValue)
{
	OCR1A = A_u8CompareValue ;
}
void MTimer1_voidGenetatePWMB (u8 A_u8CompareValue)
{
	OCR1B = A_u8CompareValue ;
}
u32 MTimer1_u32CalcTonCounts (void)
{
	u32 L_u32CountsForFirstRising ;
	u32 L_u32CountsForFirstFailling ;
	u32 L_u32CountsForTon ;
	SET_BIT(TCCR1B , 7) ;
	SET_BIT(TCCR1B , 6) ;
	while (READ_BIT(TIFR , 5) == 0) ;
	SET_BIT(TIFR , 5) ;
	L_u32CountsForFirstRising = ICR1 ;

	SET_BIT(TCCR1B , 7) ;
	CLR_BIT(TCCR1B , 6) ;
	while (READ_BIT(TIFR , 5) == 0) ;
	SET_BIT(TIFR , 5) ;
	L_u32CountsForFirstFailling = ICR1 ;
	L_u32CountsForTon = L_u32CountsForFirstFailling - L_u32CountsForFirstRising ;
	return L_u32CountsForTon ;
}
u32 MTimer1_u32CalcToffCounts (void)
{
	u32 L_u32CountsForFirstRising ;
	u32 L_u32CountsForFirstFailling ;
	u32 L_u32CountsForToff ;
	SET_BIT(TCCR1B , 7) ;
	CLR_BIT(TCCR1B , 6) ;
	while (READ_BIT(TIFR , 5) == 0) ;
	SET_BIT(TIFR , 5) ;
	L_u32CountsForFirstFailling = ICR1 ;

	SET_BIT(TCCR1B , 7) ;
	SET_BIT(TCCR1B , 6) ;
	while (READ_BIT(TIFR , 5) == 0) ;
	SET_BIT(TIFR , 5) ;
	L_u32CountsForFirstRising = ICR1 ;
	L_u32CountsForToff = L_u32CountsForFirstRising - L_u32CountsForFirstFailling ;
	return L_u32CountsForToff ;
}
void __vector_9 (void)__attribute__((signal)) ;
void __vector_9 (void)
{
	static u32 L_u32Counter = 0 ;
	L_u32Counter ++ ;
	if (L_u32Counter == G_u32Counter)
	{
		Timer1_ptr () ;
		L_u32Counter = 0 ;
	}
}
