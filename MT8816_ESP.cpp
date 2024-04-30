/*
    MT8816_ESP.h - Library for managing the MT8816 chip with an ESP32 microcontroller.
    Created by Victor Alberti, April 28, 2024.
*/

#include "MT8816_ESP.h"

// Starting the class and setting the pins:
MT8816::MT8816(int pin_reset, int pin_strobe, int pin_data, int pin_ay0, int pin_ay1, int pin_ay2, int pin_ax0, int pin_ax1, int pin_ax2, int pin_ax3)
{
    if (pin_reset != 0) PIN_RESET = pin_reset;
    if (pin_strobe != 0) PIN_STROBE = pin_strobe;
    if (pin_data != 0) PIN_DATA = pin_data;
    if (pin_ay0 != 0) PIN_AY0 = pin_ay0;
    if (pin_ay1 != 0) PIN_AY1 = pin_ay1;
    if (pin_ay2 != 0) PIN_AY2 = pin_ay2;
    if (pin_ax0 != 0) PIN_AX0 = pin_ax0;
    if (pin_ax1 != 0) PIN_AX1 = pin_ax1;
    if (pin_ax2 != 0) PIN_AX2 = pin_ax2;
    if (pin_ax3 != 0) PIN_AX3 = pin_ax3;
}

void MT8816::begin()
{ // Deffining the pins as output:
    pinMode(PIN_RESET, OUTPUT);
    pinMode(PIN_STROBE, OUTPUT);
    pinMode(PIN_DATA, OUTPUT);
    pinMode(PIN_AY0, OUTPUT);
    pinMode(PIN_AY1, OUTPUT);
    pinMode(PIN_AY2, OUTPUT);
    pinMode(PIN_AX0, OUTPUT);
    pinMode(PIN_AX1, OUTPUT);
    pinMode(PIN_AX2, OUTPUT);
    pinMode(PIN_AX3, OUTPUT);

    digitalWrite(PIN_RESET, 1); // Set the reset pin to HIGH
}

// Reset the MT8816 chip:
void MT8816::reset()
{
    Serial.println("Resetting the MT8816 chip.......");
    digitalWrite(PIN_RESET, 1);
}

// Set the connection between the x and y pins:
void MT8816::setConnection(int x, int y)
{

    if (x > 15 || y > 7)
    { // Check if the values of x and y are in the expected range
        Serial.println("Invalid values for x or y");
        return;
    }

    String binX = String(x, BIN), binY = String(y, BIN); // Declare the string that contain the value of x and y in binary

    char cbinX[4], cbinY[3]; // Create two char arrays to contain the values of the strings

    // Set the array to the values of the strings:
    int binXLength = binX.length();
    int binYLength = binY.length();

    for (int i = 0; i < 4; i++)
    {
        cbinX[i] = i < 4 - binXLength ? '0' : binX[i - (4 - binXLength)];
    }

    for (int j = 0; j < 3; j++)
    {
        cbinY[j] = j < 3 - binYLength ? '0' : binY[j - (3 - binYLength)];
    }

    // Printing the values of x and y in binary:
    Serial.println("--------Connection set to [bin]: ");
    Serial.print("X: ");
    for (int i = 0; i < 4; i++)
    {
        Serial.print(cbinX[i]);
    }
    Serial.println();

    Serial.print("Y: ");
    for (int j = 0; j < 3; j++)
    {
        Serial.print(cbinY[j]);
    }
    Serial.println();

    // Set the connection on the MT8816 chip:
    digitalWrite(PIN_AY0, cbinY[2] - '0');
    digitalWrite(PIN_AY1, cbinY[1] - '0');
    digitalWrite(PIN_AY2, cbinY[0] - '0');

    digitalWrite(PIN_AX0, cbinX[2] - '0');
    digitalWrite(PIN_AX1, cbinX[3] - '0');
    digitalWrite(PIN_AX2, cbinX[1] - '0');
    digitalWrite(PIN_AX3, cbinX[0] - '0');

    // Strobe the data:
    digitalWrite(PIN_RESET, 0);
    digitalWrite(PIN_STROBE, 1);
    digitalWrite(PIN_DATA, 1);
    digitalWrite(PIN_STROBE, 0);
    digitalWrite(PIN_DATA, 0);
}

// Broadcast the connection between the x and y pins:
void MT8816::broadcast(const Array& x, const Array& y) {
    if (x.data != NULL && y.data != NULL) {

        for (int i = 0; i < x.size; i++) {
            for (int j = 0; j < y.size; j++) {
                setConnection(x.data[i], y.data[j]);
                delay(10);
            }
        }
    }
}
