/*
 * Ultrasonic.h
 *
 *  Created on: Aug 12, 2026
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_


#define TRIG_PORT   DIO_PORTD
#define TRIG_PIN    DIO_PIN1


void HUltrasonic_voidInit (void) ;
u32  HUltrasonic_u32CalcDistance (void) ;

#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */
