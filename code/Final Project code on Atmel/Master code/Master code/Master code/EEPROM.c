/**
 * @file EEPROM.c
 * @brief Implementation of EEPROM functions.
 * @details This file contains the implementation of functions for reading and writing data to EEPROM.
 * It includes necessary header files and defines functions for reading a byte, reading a block of bytes,
 * writing a byte, and writing a block of bytes to the EEPROM.
 * 
 * @author Romany Sobhy
 */


#include "EEPROM.h"
#include <avr/io.h>

uint8_t EEPROM_ui8ReadByteFromAddress(const uint16_t u16Address)
{
	// Wait for completion of previous write
	while (((EECR & (1 << EEWE)) >> EEWE) == 1)
	;

	// Set up address register
	EEAR = u16Address;

	// Start EEPROM read by writing EERE
	EECR |= (1 << EERE);

	// Return data from data register
	return EEDR;
}

void EEPROM_vReadBlockFromAddress(const uint16_t uiAddress, uint8_t* dist, const uint16_t size)
{
	// Wait for completion of previous write
	while (((EECR & (1 << EEWE)) >> EEWE) == 1)
	;

	uint16_t counter = 0; // The counter of bytes that are read

	while (counter < size) // Loop until move all bytes to the given array
	{
		// Set up address register
		EEAR = uiAddress + counter;

		// Start EEPROM read by writing EERE
		EECR |= (1 << EERE);

		// Move data from data register to the array
		*(dist + counter) = EEDR;

		counter++; // Increase the bytes counter
	}
}

void EEPROM_vWriteByteToAddress(const uint16_t uiAddress, const uint8_t uiData)
{
	// Wait for completion of previous write process
	while ((((EECR & (1 << EEWE))) >> EEWE) == 1)
	;

	// Set up address register
	EEAR = uiAddress;

	// Read the byte in the address of EEAR
	EECR |= (1 << EERE);

	// Compare the value read to the value to be written
	if (EEDR != uiData)
	{
		// If they are not equal then write the data
		EEDR = uiData; // Move the data to EEDR

		// Write logical one to EEMWE
		EECR |= (1 << EEMWE);

		// Start EEPROM write by setting EEWE
		EECR |= (1 << EEWE);
	}
	else
	{
		// Values are equal, no need to write
	}
}

void EEPROM_vWriteBlockToAddress(const uint16_t uiAddress, const uint8_t* uiData, const uint16_t size)
{
	uint16_t counter = 0; // Bytes write counter

	while (counter < size)
	{
		// Wait for completion of previous write process
		while ((((EECR & (1 << EEWE)))) >> EEWE == 1)
		;

		// Set up address register
		EEAR = uiAddress + counter;

		// Read the byte in the address of EEAR
		EECR |= (1 << EERE);

		// Compare the value read to the value to be written
		if (EEDR != (*(uiData + counter)))
		{
			// If they are not equal then write the data
			EEDR = *(uiData + counter); // Move the data to EEDR

			// Write logical one to EEMWE
			EECR |= (1 << EEMWE);

			// Start EEPROM write by setting EEWE
			EECR |= (1 << EEWE);
		}
		else
		{
			// Values are equal, no need to write
		}

		counter++; // Increase bytes counter
	}
}
