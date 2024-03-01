/* 
 * File:   hal_gpio.c
 * Author: Ahmed kamal
 *
 * Created on 15 , 2024, 02:53 ?
 */
#include"hal_gpio.h"
// tris register (pin initialization input or output)
volatile uint8 *tris_registers[] = {&TRISA ,&TRISB ,&TRISC ,&TRISD ,&TRISE};
// lat register  (write high or low on a pin)
volatile uint8 *lat_registers[]  = {&LATA ,&LATB ,&LATC ,&LATD ,&LATE};
// port register (read the logic 0 or 1)
volatile uint8 *port_registers[] = {&PORTA ,&PORTB ,&PORTC ,&PORTD ,&PORTE};

/**
 * @brief Initialize the direction of specific pin @ref direction_t
 * @param _pin_config pointer to the configuration @ref pin_config_t
 * @return Status of the function
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function has issue to perform this action
 */
#if PORT_PIN_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t* _pin_config){
    Std_ReturnType ret = E_OK ;
    if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX-1){
        ret = E_Not_Ok ;
    }
    else{
        switch(_pin_config->direction){
            case GPIO_DIRECTION_OUTPUT :
                CLEAR_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
                break;
            case GPIO_DIRECTION_INPUT :
                SET_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
                break;
            default:
                ret = E_Not_Ok;    
        }
    }
    return ret;
}
#endif

/**
 * @brief Initialize the pin direction and write logic low
 * @param _pin_config pointer to the configuration @ref pin_config_t
 * @return Status of the function
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function has issue to perform this action
 */
#if PORT_PIN_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_initialize(const pin_config_t* _pin_config){
    Std_ReturnType ret = E_OK ;
    if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX-1){
        ret = E_Not_Ok ;
    }
    else{
        gpio_pin_direction_initialize(_pin_config);
        gpio_pin_write_logic(_pin_config, _pin_config->logic);  
    }
    return ret;
}
#endif



/**
 * @brief get the direction status of a pin
 * @param _pin_config pointer to the configuration @ref pin_config_t
 * @param direction_status
 * @return Status of the function
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function has issue to perform this action */
#if PORT_PIN_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* _pin_config ,direction_t *direction_status){
    Std_ReturnType ret = E_OK ;
    if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX-1){
        ret = E_Not_Ok ;
    }
    else{
       *direction_status = READ_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
}
#endif
  

/**
 * @brief write logic (0 or 1) on a specific pin
 * @param _pin_config pointer to the configuration @ref pin_config_t
 * @param logic
 * @return Status of the function
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function has issue to perform this action */
#if PORT_PIN_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t* _pin_config ,logic_t logic){
    Std_ReturnType ret = E_OK ;
    if(NULL ==_pin_config || _pin_config->pin > PORT_PIN_MAX-1){
        ret = E_Not_Ok ;
    }
    else{
        switch(logic){
            case LOW :
                CLEAR_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
                break;
            case HIGH :
                SET_BIT(*lat_registers[_pin_config->port], _pin_config->pin);
                break;
            default:
                ret = E_Not_Ok;    
        }
    }
    return ret ;
}
#endif


/**
 * @brief read logic(0 or 1) from a specific pin
 * @param _pin_config pointer to the configuration @ref pin_config_t
 * @param logic
 * @return  * @return Status of the function
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function has issue to perform this action
 */
#if PORT_PIN_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t* _pin_config,logic_t *logic){
    Std_ReturnType ret = E_OK ;
    if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX-1){
        ret = E_Not_Ok ;
    }
    else{
        *logic = READ_BIT(*port_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
}
#endif

/**
 * @brief toggle a specific bit
 * @param _pin_config pointer to the configuration @ref pin_config_t
 * @return Status of the function
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function has issue to perform this action */
#if PORT_PIN_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* _pin_config){
    Std_ReturnType ret = E_OK ;
    if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX-1){
        ret = E_Not_Ok ;
    }
    else{
    TOGGLE_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
    }
    return ret;
}
#endif



//ports
/**
 * @brief initialize a specific port
 * @param _port @ref port_index_t
 * @param direction
 * @return Status of the function
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function has issue to perform this action */
#if PORT_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_port_direction_initialize(port_index_t _port ,uint8 direction){
Std_ReturnType ret = E_OK;
if (_port > PORT_MAX_NUMBER-1){
    ret = E_Not_Ok ;
}
else{
    *tris_registers[_port] = direction;
}
return ret;
}
#endif


/**
 * @brief get the direction status of a specific port
 * @param _port @ref port_index_t
 * @param direction_status
 * @return Status of the function
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function has issue to perform this action */
#if PORT_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_status(port_index_t _port ,uint8 *direction_status){
    Std_ReturnType ret = E_OK;
    if(_port>PORT_MAX_NUMBER-1 || (NULL == direction_status)){
    Std_ReturnType ret = E_Not_Ok;        
    }
    else{
        *direction_status = *tris_registers[_port];
    }
    return ret;
}
#endif


/**
 * @brief write logic (0 or 1) on a specific port
 * @param _port @ref port_index_t
 * @param logic
 * @return Status of the function
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function has issue to perform this action */
#if PORT_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_port_pin_write_logic(port_index_t _port ,uint8 logic){
    Std_ReturnType ret = E_OK;
    if(_port>PORT_MAX_NUMBER-1 ){
    Std_ReturnType ret = E_Not_Ok;        
    }
    else{
        *lat_registers[_port] = logic ;
    }
    return ret;
}
#endif

/**
 * @brief read logic (0 or 1) from a specific port
 * @param _port @ref port_index_t
 * @param logic
 * @return Status of the function
 *          (E_OK) : the function done successfully
 *          (E_NOT_OK) : the function has issue to perform this action */
#if PORT_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(port_index_t _port,uint8 *logic){
    Std_ReturnType ret = E_OK;
    if(_port>PORT_MAX_NUMBER-1 || (logic == NULL)){
    Std_ReturnType ret = E_Not_Ok;        
    }
    else{
        *logic = *lat_registers[_port];
    }
    return ret;
}
#endif

#if PORT_CONFIGRATION == CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(port_index_t _port){
    Std_ReturnType ret = E_OK;
    if(_port>PORT_MAX_NUMBER-1){
    Std_ReturnType ret = E_Not_Ok;        
    }
    else{
        *lat_registers[_port] ^= 0xff;
    }
    return ret;
}
#endif