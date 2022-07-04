/*
 * ADC_driver.c
 *
 * @brief  ADC driver implementation for AVR microcontrollers.
 *
 * @details This driver provides functions to initialize the ADC module and read ADC values.
 *
 * @authorRomany Sobhy
 */

#include <avr/io.h>
#include "std_macros.h"
#include "STD_Types.h"

/**
 * @name    ADC_vinit
 * @brief   Initializes the ADC module.
 * @details Configures VREF to the internal voltage (2.56V) and enables the ADC.
 *          This function should be called before using the ADC.
 */
void ADC_vinit(void)
{
    /* Configure VREF to the internal voltage (2.56V) */
    SET_BIT(ADMUX, REFS0);
    SET_BIT(ADMUX, REFS1);
    /*************************************/

    SET_BIT(ADCSRA, ADEN); // Enable ADC

    /* Adjust ADC clock by selecting the division factor -----> 64 */
    SET_BIT(ADCSRA, ADPS2);
    SET_BIT(ADCSRA, ADPS1);
    /***********************************/
}

/**
 * @name    ADC_u16Read
 * @brief   Reads the ADC value.
 * @details Starts the ADC conversion and waits for it to complete.
 *          Returns the converted ADC value.
 * @return  The converted ADC value.
 */
uint16 ADC_u16Read(void)
{
    uint16 read_val; // Contains the converted value which will be returned
    SET_BIT(ADCSRA, ADSC); // Start the ADC conversion

    while (IS_BIT_CLR(ADCSRA, ADIF)); // Stay in the loop until ADIF becomes 1 when the conversion is complete
    SET_BIT(ADCSRA, ADIF); // Clear ADIF

    read_val = ADCL; // Read the ADCL register
    read_val |= (ADCH << 8); // Read the whole register

    return read_val; // Return the converted value
}
