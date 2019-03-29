/****************************************************
*  3SG board - iCub Facility - 2019                 *
*  Si705x configuration                             *
*                                                   *
*  Written by Andrea Mura                           *
*  <andrea.mura@iit.it>                             *
****************************************************/

// IIT-EXT
#if defined(USE_STM32HAL)
    #include "stm32hal.h"
#else
#include "stm32l4xx_hal.h"
#endif


#ifndef Si705x_H
#define Si705x_H

extern const uint8_t Si705x_I2C_ADDRESS;
extern uint8_t Si705x_I2C3_RxBuffer[2];
extern uint16_t Temperature_code;
extern uint16_t Temperature_board;
extern uint16_t Temperature_code_prev;
extern uint8_t *MPU9250_SensorValue;

void Si705x_init(void);
void Si705x_deinit(void);
void Si705x_ReadTemperature(void);

#endif
