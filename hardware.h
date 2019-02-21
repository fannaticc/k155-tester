/* 
 * File:   hardware.h
 * Author: Raphael
 *
 * Created on 9 de Setembro de 2017, 17:17
 */

#ifndef HARDWARE_H
#define	HARDWARE_H

#include "config.h"

// Display
#define BCD_A PORTCbits.RC0
#define BCD_B PORTCbits.RC2
#define BCD_C PORTBbits.RB4
#define BCD_D PORTCbits.RC1

#define PILOT PORTAbits.RA2

#define NUM_0() {BCD_A = 0; BCD_B = 0; BCD_C = 0; BCD_D = 0;}
#define NUM_1() {BCD_A = 1; BCD_B = 0; BCD_C = 0; BCD_D = 0;}
#define NUM_2() {BCD_A = 0; BCD_B = 1; BCD_C = 0; BCD_D = 0;}
#define NUM_3() {BCD_A = 1; BCD_B = 1; BCD_C = 0; BCD_D = 0;}
#define NUM_4() {BCD_A = 0; BCD_B = 0; BCD_C = 1; BCD_D = 0;}
#define NUM_5() {BCD_A = 1; BCD_B = 0; BCD_C = 1; BCD_D = 0;}
#define NUM_6() {BCD_A = 0; BCD_B = 1; BCD_C = 1; BCD_D = 0;}
#define NUM_7() {BCD_A = 1; BCD_B = 1; BCD_C = 1; BCD_D = 0;}
#define NUM_8() {BCD_A = 0; BCD_B = 0; BCD_C = 0; BCD_D = 1;}
#define NUM_9() {BCD_A = 1; BCD_B = 0; BCD_C = 0; BCD_D = 1;}
#define NUM_N() {BCD_A = 1; BCD_B = 1; BCD_C = 1; BCD_D = 1;}

/*#define NUM_0() {BCD_A = 0; BCD_B = 0; BCD_C = 0; BCD_D = 0;}
#define NUM_1() {BCD_A = 0; BCD_B = 0; BCD_C = 0; BCD_D = 1;}
#define NUM_2() {BCD_A = 0; BCD_B = 0; BCD_C = 1; BCD_D = 0;}
#define NUM_3() {BCD_A = 0; BCD_B = 0; BCD_C = 1; BCD_D = 1;}
#define NUM_4() {BCD_A = 0; BCD_B = 1; BCD_C = 0; BCD_D = 0;}
#define NUM_5() {BCD_A = 0; BCD_B = 1; BCD_C = 0; BCD_D = 1;}
#define NUM_6() {BCD_A = 0; BCD_B = 1; BCD_C = 1; BCD_D = 0;}
#define NUM_7() {BCD_A = 0; BCD_B = 1; BCD_C = 1; BCD_D = 1;}
#define NUM_8() {BCD_A = 1; BCD_B = 0; BCD_C = 0; BCD_D = 0;}
#define NUM_9() {BCD_A = 1; BCD_B = 0; BCD_C = 0; BCD_D = 1;}
#define NUM_N() {BCD_A = 1; BCD_B = 1; BCD_C = 1; BCD_D = 1;}*/

// Human interface
#define BUTTON1 PORTAbits.RA5

// High voltage controller
#define PWM PORTCbits.RC5
#define AN0 PORTBbits.RB5

// Serial interface (Not used)
#define TX PORTBbits.RB7
#define RX PORTBbits.RB5

#endif	/* HARDWARE_H */

