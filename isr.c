/* 
 * File:   isr.h
 * Author: Raphael
 *
 * Created on 11 de Setembro de 2017, 18:51
 */

#include "isr.h"
#include "config.h"
#include "main.h"
#include "adc.h"
#include "pwm.h"

void interrupt interrupt_handler()
{
    if(PIR1bits.ADIF && PIE1bits.ADIE)
    {
        // Check the output voltage.
        if(ADCON0bits.GO == 0)
        {
            adc_result = ((readadraw()) - OFFSET);
        
            if(adc_result < DESIRED_ADC_RESULT && pwm_value < MAX_PWM_LEVEL)
            {
                pwm_value++;
                set_pwm1_duty(pwm_value);
            }
            else if(adc_result > DESIRED_ADC_RESULT && pwm_value > MIN_PWM_LEVEL)
            {
                pwm_value--;
                set_pwm1_duty(pwm_value);
            }
            PIR1bits.ADIF = 0;
            ADCON0bits.GO = 1;
        }
    }
}