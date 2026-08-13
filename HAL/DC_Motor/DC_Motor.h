/*
 * DC_Motor.h
 *
 *  Created on: Aug 6, 2026
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_H_
#define HAL_DC_MOTOR_DC_MOTOR_H_

void HDCM_voidInit (u8 A_u8DCMPort , u8 A_u8Pin1Pin , u8 A_u8Pin2Pin) ;
void HDCM_voidStop (u8 A_u8DCMPort , u8 A_u8Pin1Pin , u8 A_u8Pin2Pin) ;
void HDCM_voidCW   (u8 A_u8DCMPort , u8 A_u8Pin1Pin , u8 A_u8Pin2Pin) ;
void HDCM_voidCCW  (u8 A_u8DCMPort , u8 A_u8Pin1Pin , u8 A_u8Pin2Pin) ;

#endif /* HAL_DC_MOTOR_DC_MOTOR_H_ */
