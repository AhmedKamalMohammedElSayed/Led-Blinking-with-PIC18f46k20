/* 
 * File:   hal_gpio.h
 * Author: Ahmed
 *
 * Created on 19 ??????, 2024, 07:20 ?
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* Section : Includes */
//#include "../proc/pic18f4620.h"
#include <xc.h>
#include "../../MCAL_Layer/mcal_std_types.h"
#include "../../MCAL_Layer/device_config.h"
#include "hal_gpio_cfg.h"

/* Section Macro Declarations */
#define BIT_MASK (uint8)1
#define PORT_PIN_MAX 8
#define PORT_MAX_NUMBER 5

/* Section Macro Functions Declarations */
#define HWREG8(_x) (*((volatile uint8 *)(_x)))
#define SET_BIT(_REG_ADDR, _BIT_POSN) (_REG_ADDR |=  (1 << _BIT_POSN))
#define CLEAR_BIT(_REG_ADDR , _BIT_POSN) (_REG_ADDR &= ~(1 << _BIT_POSN))
#define TOGGLE_BIT(_REG_ADDR , _BIT_POSN) (_REG_ADDR ^=  (1 << _BIT_POSN))
#define READ_BIT(_REG_ADDR , _BIT_POSN) ((_REG_ADDR >> _BIT_POSN) & BIT_MASK)

//#define TOGGLE_PORT(_REG_ADDR) ()


/* Section Data Type Declarations */
typedef enum {
    LOW,
    HIGH
}logic_t;

typedef enum{
    GPIO_DIRECTION_OUTPUT,
    GPIO_DIRECTION_INPUT
}direction_t;
typedef enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;
typedef enum{
    PORTA_INDEX,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;
typedef struct{
    uint8 port       : 3;   /*     @ref port_index_t    */
    uint8 pin        : 3;   /*     @ref pin_index_t     */
    uint8 direction  : 1;   /*     @ref direction_t     */
    uint8 logic      : 1;   /*     @ref logic_t         */

}pin_config_t;
/* Section Function Declaration */
// pins
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t* _pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* _pin_config ,direction_t *direction_status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t* _pin_config ,logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t* _pin_config,logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* _pin_config);
Std_ReturnType gpio_pin_initialize(const pin_config_t* _pin_config);
//ports
Std_ReturnType gpio_port_direction_initialize(port_index_t _port ,uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t _port ,uint8 *direction_status);
Std_ReturnType gpio_port_pin_write_logic(port_index_t _port ,uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index_t _port,uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t _port);

#endif	/* HAL_GPIO_H */

