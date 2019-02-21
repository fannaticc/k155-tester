/* 
 * File:   main.h
 * Author: Raphael
 *
 * Created on March 27, 2017, 7:54 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#define ADC_VREF 5
#define DESIRED_VOUT 100.0
#define DIVIDER_RATIO 40 // O 0.5 A MAIS É DA CALIBRAÇÃO A RELAÇÃO REAL É 1/40
#define DESIRED_ADC_IN_V (DESIRED_VOUT / DIVIDER_RATIO)
#define MAX_PWM_LEVEL 250 // Equivalente a 200V com cargade 6 tubos IN-12 apresentando o numero 8!!!
#define MIN_PWM_LEVEL 1
#define OFFSET 0
#define ADC_RESOLUTION10 1023
#define ADC_RESOLUTION12 4095
#define ADC_RESOLUTION_SELECTED ADC_RESOLUTION10

unsigned int adc_result = 0;
unsigned int pwm_value = 8;
const unsigned int DESIRED_ADC_RESULT = (ADC_RESOLUTION_SELECTED * (DESIRED_ADC_IN_V / ADC_VREF));

void Init_System();

#endif	/* MAIN_H */

