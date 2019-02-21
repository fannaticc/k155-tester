/* 
 * File:   main.c
 * Author: raphael.pereira
 *
 * Created on 13 de Março de 2018, 08:21
 */
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "config.h"
#include "pwm.h"
#include "adc.h"
#include "my_delays.h"
#include "hardware.h"

/*
    Main application
 */
void main(void)
{
    static bit flag_button;

    Init_System(); //Init the system, and peripherals.
    
    PILOT = 1;
    //NUM_0();
    
    while(1)
    {
        NUM_8();
        Delay_ms(50);
        NUM_9();
        Delay_ms(50);
        NUM_0();
        Delay_ms(50);
        NUM_1();
        Delay_ms(50);
        NUM_5();
        Delay_ms(50);
        NUM_4();
        Delay_ms(50);
        NUM_6();
        Delay_ms(50);
        NUM_7();
        Delay_ms(50);
        NUM_3();
        Delay_ms(50);
        NUM_2();
        Delay_ms(50);
    }
}

void Init_System()
{
    OSCCON = 0b01110001; // Set the internal oscillator to 8MHz.
    
    TRISA = 0b00101000;
    TRISB = 0b00100000;
    TRISC = 0b00000000;

    PORTA = 0b00000000;
    PORTB = 0b00000000;
    PORTC = 0b00000000;

    ANSEL = 0b00000000; // All pins as digital.
    ANSELH = 0b00001000; // Set AN11 as analog input.
    ADCON0 = 0b10101101; // Right, Vdd Ref, Select AN11.
    ADCON1 = 0b01010000; // fosc/16.
    
    CM1CON0 = 0b00000000; // Disable the comparator 1.
    CM2CON0 = 0b00000000; // Disable the comparator 2.
    
    setup_ccp1(); // Configure the PWM.
    Config_pwm1();
    set_pwm1_duty(2); // Init PWM with a value, to optimise the timing.
    
    //while(1);
    
    // Timer 1 interrupt enable
    //PIR1bits.TMR1IF = 0;
    //PIE1bits.TMR1IE = 1;
    
    // AD interrupt enable
    PIR1bits.ADIF = 0;
    PIE1bits.ADIE = 1;
    ADCON0bits.GO = 1; // Initiete the first conversion.
    
    INTCON = 0b11100000; // Enable interrupts
}