/* 
 * File:   pwm.c
 * Author: Raphael
 *
 * Created on 24 de Fevereiro de 2016, 16:33
 */

#include <xc.h>
#include "pwm.h"
#include "config.h"

void setup_ccp1()
{
    CCP1CON = 0b00001100;
}

void Config_pwm1()
{
    // 10kHz
    //PR2 = 199;
    //T2CON = 0b00000100;
    //CCPR1L = 0b11001000;
    //CCP1CON = 0b00001100;
    
    // 10kHz
    //PR2 = 199;
    //T2CON = 0b00000100;
    //CCPR2L = 0b11001000;
    //CCP2CON = 0b00001100;
    
    // 14kHz
    //PR2 = 142;
    //T2CON = 0b00000100;
    //CCPR2L = 0b01000010;
    //CCP2CON = 0b00001100;
    
    //30kHz
    PR2 = 66;
    T2CON = 0b00000100;
    CCPR1L = 0b00100001;
    CCP1CON = 0b00101100;
    
    //100kHz
    //PR2 = 19;
    //T2CON = 0b00000100;
    //CCPR2L = 0b00001010;
    //CCP2CON = 0b00001100;
}

void set_pwm1_duty(unsigned int duty_ratio)
{
    union PWMDC DCycle;

    DCycle.lpwm = duty_ratio << 6;

    // Write the high byte into CCPR1L
    CCPR1L = DCycle.bpwm[1];

    // Write the low byte into CCP1CON5:4
    CCP1CON = (CCP1CON & 0xCF) | ((DCycle.bpwm[0] >> 2) & 0x30);
}