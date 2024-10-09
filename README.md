# MT8816_ESP Library

## Overview
The MT8816_ESP library is designed to interface the MT8816 analog crosspoint switch with an ESP32 microcontroller. This library allows for control of the MT8816 chip, enabling the user to configure connections between different channels (X and Y pins) using the ESP32. The library is intended to simplify managing the MT8816 from the ESP32 platform by providing functions for resetting the chip, setting connections, and broadcasting multiple connections between X and Y pins.

OBS: A part of the logic was taken from DatanoiseTV work, so I basically did this for learning and self improvement.

## Features
1. Reset the MT8816 chip: Easily reset the chip to its initial state.
2. Set individual connections: Establish a connection between specific X and Y pins.
3. Broadcast multiple connections: Connect a series of X and Y pins in a loop.
4. Debugging with Serial output: Displays helpful debug information, including binary representations of pin connections.

# Usage

1. Constructor: Initializing the MT8816 Chip
     
        MT8816::MT8816(int pin_reset, int pin_strobe, int pin_data, int pin_ay0, int pin_ay1, int pin_ay2, int pin_ax0, int pin_ax1, int pin_ax2, int pin_ax3);
        //This constructor initializes the MT8816 chip by defining the ESP32 GPIO pins that will be used to interface with the chip. Each pin parameter corresponds to a specific control or data pin on the MT8816.

2. begin(): Configuring the Pin Modes

        void begin();
        //This function sets the pin modes of the ESP32 GPIOs as OUTPUT, and it ensures the RESET pin is initialized to HIGH, preparing the MT8816 chip for further commands.

3. reset(): Resetting the MT8816

        void reset();
        //Resets the MT8816 chip to its default state. This function sets the RESET pin to HIGH and prints a message to the Serial console indicating the reset process.

4. setConnection(int x, int y): Setting a Connection Between X and Y Pins

        void setConnection(int x, int y);
        //Establishes a connection between the selected X and Y pins on the MT8816 chip. The function accepts two integer values representing the X (0-15) and Y (0-7) pins and converts them to binary. These binary values are written to the appropriate control              //pins of the ESP32 to configure the MT8816.

5. broadcast(const Array& x, const Array& y): Broadcasting Multiple Connections

        void broadcast(const Array& x, const Array& y);
        //This function establishes multiple connections between arrays of X and Y pins, looping through each value of X and Y to connect them sequentially. It also includes a slight delay between each connection to ensure 
        //the chip processes the configuration.
  
