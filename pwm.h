/* 
 * File:   pwm.h
 * Author: Raphael
 *
 * Created on 24 de Fevereiro de 2016, 16:33
 */

#ifndef PWM_H
#define	PWM_H

#define CCP_PWM 0b00001111
#define CCP_OFF 0b00000000


union PWMDC
{
    unsigned int lpwm;
    char bpwm[2];
};


//////////////////////////////////////////////////////////////////////
//                                                                  //
//		Function Prototypes                                         // 
//////////////////////////////////////////////////////////////////////
void setup_ccp1();
void Config_pwm1();
void set_pwm1_duty(unsigned int duty_ratio);

#endif	/* PWM_H */

