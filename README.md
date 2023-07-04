# Smart Home Project

This repository contains the code and documentation for a smart home project using two Atmega32 microcontrollers as master and slave devices. The master device is connected to a keypad, LED indicators, and communicates with the slave device using SPI. The slave device controls four room LEDs, an air conditioner (AC), and a TV. The master device also features LED indicators for the current status (admin, guest, block).

## Features

- Keypad input for user interaction
- Password authentication for admin and guest privileges
- Resettable EEPROM for storing passwords
- LED indicators for admin, guest, and block status
- Control of room LEDs, AC, and TV through the slave device
- Temperature control for the AC based on a temperature sensor

## Setup and Usage

### Hardware Setup

1. Connect the following hardware components:

   - Master Device:
     - Atmega32 microcontroller
     - Keypad
     - LED indicators

   - Slave Device:
     - Atmega32 microcontroller
     - Four room LEDs
     - Air conditioner (AC)
     - TV

   - SPI Communication:
     - Connect the SPI pins (MISO, MOSI, SCK) between the master and slave devices.

2. Refer to the documentation in the `docs` directory for detailed wiring diagrams and hardware setup instructions.

### Firmware Upload

1. Upload the firmware to the respective microcontrollers:

   - Master Device:
     - Navigate to the `master` directory.
     - Upload the code to the Atmega32 microcontroller.

   - Slave Device:
     - Navigate to the `slave` directory.
     - Upload the code to the Atmega32 microcontroller.

### System Usage

1. Power on the system.

2. Upon the first use, the system will prompt you to set the admin and guest passwords.

3. Subsequently, follow these steps for system usage:

   - Select the desired privilege level (admin or guest).
   - Enter the corresponding password using the keypad.
   - Use the keypad for system navigation and interaction.
   - Monitor the LED indicators for the current status (admin, guest, block).
   - Control the room LEDs, AC, and TV through the slave device based on the system prompts.

4. To reset the passwords, refer to the `eeprom_reset.md` file for instructions on clearing the EEPROM.

## Documentation

- The `docs` directory contains detailed documentation for hardware setup, wiring diagrams, and system architecture.
- Refer to the `README.md` file in each firmware directory (`master` and `slave`) for specific instructions on uploading the code and configuring the microcontrollers.
- The `eeprom_reset.md` file provides instructions for resetting the EEPROM and clearing the passwords.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
