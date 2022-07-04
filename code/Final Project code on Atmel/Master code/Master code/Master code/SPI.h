/**
 * @file SPI.h
 * @brief SPI communication interface.
 * @details This file contains the function prototypes and definitions for SPI communication.
 *@author Romany Sobhy
 */

#ifndef SPI_H_
#define SPI_H_



#include "STD_Types.h"
#include "STD_MESSAGES.h"
#include "std_macros.h"

#define SPI_SCK  7
#define SPI_MISO 6
#define SPI_MOSI 5
#define SPI_SS   4

/**
 * @brief Initialize SPI as a master.
 */
void SPI_vInitMaster(void);

/**
 * @brief Initialize SPI as a slave.
 */
void SPI_vInitSlave(void);

/**
 * @brief Transmit and receive data over SPI.
 * @param data The data to be transmitted.
 * @return The received data.
 */
uint8 SPI_ui8TransmitRecive(uint8 data);

#endif /* SPI_H_ */
