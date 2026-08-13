/*
 * Timer1.h
 *
 *  Created on: Aug 11, 2026
 *      Author: Mohammed Ramadan
 */

#ifndef MCAL_TIMER1_TIMER1_H_
#define MCAL_TIMER1_TIMER1_H_

#define TIMER1_PRESCALLER_1      1
#define TIMER1_PRESCALLER_8      8
#define TIMER1_PRESCALLER_64     64
#define TIMER1_PRESCALLER_256    256
#define TIMER1_PRESCALLER_1024   1024


#define TIMER1_OVF                           0
#define TIMER1_PWM_PHASE_CORRECT_8BIT        1
#define TIMER1_PWM_PHASE_CORRECT_9BIT        2
#define TIMER1_PWM_PHASE_CORRECT_10BIT       3
#define TIMER1_CTC_OCR1A_TOP                 4
#define TIMER1_PWM_FAST_8BIT                 5
#define TIMER1_PWM_FAST_9BIT                 6
#define TIMER1_PWM_FAST_10BIT                7
#define TIMER1_FREQUANCY_CORRECT_ICR1_TOP    8
#define TIMER1_FREQUANCY_CORRECT_OCR1A_TOP   9
#define TIMER1_PHASE_CORRECT_ICR1_TOP        10
#define TIMER1_PHASE_CORRECT_OCR1A_TOP       11
#define TIMER1_CTC_ICR1_TOP                  12
#define TIMER1_FAST_ICR1_TOP                 13
#define TIMER1_FAST_OCR1A_TOP                14

#define TCCR1A   (*(volatile u8*)(0x4F))
#define TCCR1B   (*(volatile u8*)(0x4E))
#define TCNT1    (*(volatile u16*)(0x4C))
#define OCR1A    (*(volatile u16*)(0x4A))
#define OCR1B    (*(volatile u16*)(0x48))
#define ICR1     (*(volatile u16*)(0x46))
#define TIMSK    (*(volatile u8*)(0x59))
#define TIFR     (*(volatile u8*)(0x58))
#define SREG     (*(volatile u8*)(0x5f))

void MTimer1_voidInit (u16 A_u16Prescaller , u8 A_u8Mode) ;
void MTimer1_voidSetDesiredTime (u32 A_u32DisiredTimeInMicro , void (*fptr)(void)) ;
void MTimer1_voidGenetatePWMA (u8 A_u8CompareValue) ;
void MTimer1_voidGenetatePWMB (u8 A_u8CompareValue) ;
u32 MTimer1_u32CalcTonCounts (void) ;
u32 MTimer1_u32CalcToffCounts (void) ;
#endif /* MCAL_TIMER1_TIMER1_H_ */
