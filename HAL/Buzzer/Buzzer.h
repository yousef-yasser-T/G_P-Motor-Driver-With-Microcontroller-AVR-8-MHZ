/*
 * Buzzer.h
 *
 *  Created on: Aug 4, 2026
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_BUZZER_BUZZER_H_
#define HAL_BUZZER_BUZZER_H_

void HBUZZER_voidInit      (A_u8BuzerPort , A_u8BuzzerPin) ;
void HBUZZER_voidTurnOn    (A_u8BuzerPort , A_u8BuzzerPin) ;
void HBUZZER_voidTurnOff   (A_u8BuzerPort , A_u8BuzzerPin) ;
void HBUZZER_voidTogStatus (A_u8BuzerPort , A_u8BuzzerPin) ;

#endif /* HAL_BUZZER_BUZZER_H_ */
