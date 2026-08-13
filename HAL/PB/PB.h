/*
 * PB.h
 *
 *  Created on: Aug 4, 2026
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_PB_PB_H_
#define HAL_PB_PB_H_

#define PB_PRESSED      0
#define PB_NOT_PRESSED  1

#define Forward   DIO_PIN0
#define Backward  DIO_PIN1
#define Left      DIO_PIN2
#define Right     DIO_PIN3
#define Stop      DIO_PIN4

void HPB_voidInit (A_u8PbPort , A_u8PbPin) ;
u8   HPB_u8GetStatues (A_u8PbPort , A_u8PbPin) ;
void HState_voidStateCar(u8 A_u8PbPort, u8 A_u8PbPin, u8 A_u8PbPin1, u8 A_u8PbPin2, u8 A_u8PbPin3, u8 A_u8PbPin4);
#endif /* HAL_PB_PB_H_ */
