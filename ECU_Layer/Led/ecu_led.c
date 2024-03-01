/* 
 * File:   ecu_led.h
 * Author: Ahmed kamal
 *
 * Created on 15 ??????, 2024, 04:31 ?
 */


#include"../ecu_led.h"


/**
 * @brief   initialize the assigned pin to be output and turn the led off
 * @param   led : pointer to the led module configurations
 * @return  status of the function
 *          (E_OK)      :the function done successfully
 *          (E_NOT_OK)  :the function has an issue
 */
Std_ReturnType led_initialize(const led_t *led){
    Std_ReturnType ret = E_OK ;
    if(NULL == led ){
        ret = E_Not_Ok ;
    }
    else{
        pin_config_t pin_obj = {.port = led->port_name , .pin = led->pin ,.direction = GPIO_DIRECTION_OUTPUT,.logic = led->led_status};
        ret = gpio_pin_initialize(&pin_obj);        
    }
    return ret;
}


/**
 * @brief   turning on the led
 * @param   led : pointer to the led module configurations
 * @return  status of the function
 *          (E_OK)      :the function done successfully
 *          (E_NOT_OK)  :the function has an issue
 */
Std_ReturnType led_turn_on(const led_t *led){
    Std_ReturnType ret = E_OK ;
    if(NULL == led ){
        ret = E_Not_Ok ;
    }
    else{
        logic_t logic = HIGH;
        pin_config_t pin_obj = {.port = led->port_name , .pin = led->pin ,.direction = GPIO_DIRECTION_OUTPUT,.logic = led->led_status};
        ret = gpio_pin_write_logic(&pin_obj , logic);        
    }
    return ret;
}

/**
 * @brief   turning off the led
 * @param   led : pointer to the led module configurations
 * @return  status of the function
 *          (E_OK)      :the function done successfully
 *          (E_NOT_OK)  :the function has an issue
 */
Std_ReturnType led_turn_off(const led_t *led){
    Std_ReturnType ret = E_OK ;
    if(NULL == led ){
        ret = E_Not_Ok ;
    }
    else{
        logic_t logic = LOW;
        pin_config_t pin_obj = {.port = led->port_name , .pin = led->pin ,.direction = GPIO_DIRECTION_OUTPUT,.logic = led->led_status};
        ret = gpio_pin_write_logic(&pin_obj , logic);        
    }
    return ret;
}
Std_ReturnType led_turn_toggle(const led_t *led){
    Std_ReturnType ret = E_OK ;
    if(NULL == led ){
        ret = E_Not_Ok ;
    }
    else{
        pin_config_t pin_obj = {.port = led->port_name , .pin = led->pin ,.direction = GPIO_DIRECTION_OUTPUT,.logic = led->led_status};
        ret = gpio_pin_toggle_logic(&pin_obj);        
    }
    return ret;
}