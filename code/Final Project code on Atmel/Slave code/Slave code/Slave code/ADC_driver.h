/*
 * ADC_driver.h
 *
 * @brief  ADC driver interface for AVR microcontrollers.
 *
 * @details This header file provides function prototypes for the ADC driver,
 *          including initialization and reading ADC values.
 *
 * @author Romany Sobhy
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "STD_Types.h"

/**
 * @name    ADC_vinit
 * @brief   Initialize the ADC.
 */
void ADC_vinit(void);

/**
 * @name    ADC_u16Read
 * @brief   Read the value converted by the ADC.
 * @return  The converted ADC value.
 */
uint16 ADC_u16Read(void);

#endif /* ADC_DRIVER_H_ */
