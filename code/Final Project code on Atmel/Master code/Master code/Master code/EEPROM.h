/**
 * @file EEPROM.h
 * @brief Header file for EEPROM functions.
 * @details This file contains the function prototypes for reading and writing data to EEPROM.
 * It defines the functions for reading a byte, reading a block of bytes, writing a byte,
 * and writing a block of bytes to the EEPROM.
 * 
 * @author Romany Sobhy
 */


#ifndef EEPROM_H
#define EEPROM_H

#include <stdint.h>

/*------------------ SW INTERFACES DECLARATIONS -------------------------*/



/**
 * @brief Read a byte from the specified EEPROM address.
 * @param u16Address The address to read from.
 * @return The data byte read from the specified address.
 */
uint8_t EEPROM_ui8ReadByteFromAddress(const uint16_t u16Address);

/**
 * @brief Read a block of bytes from the specified EEPROM address into a buffer.
 * @param uiAddress The starting address to read from.
 * @param dist Pointer to the destination buffer to store the read data.
 * @param size The number of bytes to read.
 */
void EEPROM_vReadBlockFromAddress(const uint16_t uiAddress, uint8_t* dist, const uint16_t size);

/**
 * @brief Write a byte to the specified EEPROM address.
 * @param uiAddress The address to write to.
 * @param uiData The data byte to write.
 */
void EEPROM_vWriteByteToAddress(const uint16_t uiAddress, const uint8_t uiData);

/**
 * @brief Write a block of bytes to the specified EEPROM address.
 * @param uiAddress The starting address to write to.
 * @param uiData Pointer to the source buffer containing the data to write.
 * @param size The number of bytes to write.
 */
void EEPROM_vWriteBlockToAddress(const uint16_t uiAddress, const uint8_t* uiData, const uint16_t size);


/*------------------ SW INTERFACES DECLARATIONS END ---------------------*/

#endif
