/* 
 * File:   application.c
 * Author: AhmedKamal
 *
 * Created on 15 , 2024, 02:53 
 */

#include <stdint.h>
#include "application.h"
#include <xc.h>

#define _XTAL_FREQ 800000

led_t led1 = {.port_name = PORTC_INDEX,.pin = PIN0,.led_status = LOW};
led_t led2 = {.port_name = PORTC_INDEX,.pin = PIN1,.led_status = LOW};
led_t led3 = {.port_name = PORTC_INDEX,.pin = PIN2,.led_status = LOW};
led_t led4 = {.port_name = PORTC_INDEX,.pin = PIN3,.led_status = LOW};
led_t led5 = {.port_name = PORTC_INDEX,.pin = PIN4,.led_status = LOW};
led_t led6 = {.port_name = PORTC_INDEX,.pin = PIN5,.led_status = LOW};
led_t led7 = {.port_name = PORTC_INDEX,.pin = PIN6,.led_status = LOW};
led_t led8 = {.port_name = PORTC_INDEX,.pin = PIN7,.led_status = LOW};

int main() {

    
    application_initialize();
    while(1){
        led_turn_on(&led1);
        led_turn_on(&led2);
        led_turn_on(&led3);
        led_turn_on(&led4);
        led_turn_on(&led5);
        led_turn_on(&led6);
        led_turn_on(&led7);
        led_turn_on(&led8);
        __delay_ms(1000);
        led_turn_off(&led1);
        led_turn_off(&led2);
        led_turn_off(&led3);
        led_turn_off(&led4);
        led_turn_off(&led5);
        led_turn_off(&led6);
        led_turn_off(&led7);
        led_turn_off(&led8);
        __delay_ms(1000);
    }
    return (EXIT_SUCCESS);
}

void application_initialize(void){
    Std_ReturnType ret = E_Not_Ok;
    ret = led_initialize(&led1);
    ret = led_initialize(&led2);
    ret = led_initialize(&led3);
    ret = led_initialize(&led4);
    ret = led_initialize(&led5);
    ret = led_initialize(&led6);
    ret = led_initialize(&led7);
    ret = led_initialize(&led8);
}

