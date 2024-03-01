/* 
 * File:   ecu_led.h
 * Author: Ahmed kamal
 *
 * Created on 15 ??????, 2024, 04:31 ?
 */

#ifndef ECU_LED_H
#define	ECU_LED_H


/* Section : Includes */
#include "../MCAL_Layer/GPIO/hal_gpio.h"
#include "Led/ecu_led_cfg.h"

/* Section Macro Declarations */


/* Section Macro Functions Declarations */

typedef enum{
    LED_OOF,
    LED_ON
}led_status_t;


typedef struct{
    uint8 port_name :4;
    uint8 pin :3;
    uint8 led_status :1;  
}led_t;

/* Section Data Type Declarations */
Std_ReturnType led_initialize(const led_t *led);
Std_ReturnType led_turn_on(const led_t *led);
Std_ReturnType led_turn_off(const led_t *led);
Std_ReturnType led_turn_toggle(const led_t *led);



/* Section Function Declaration */



#endif	/* ECU_LED_H */

