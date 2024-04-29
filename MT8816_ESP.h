/*
    MT8816_ESP.h - Library for managing the MT8816 chip with an ESP32 microcontroller.
    Created by Victor Alberti, April 28, 2024.
*/

#ifndef MT8816_ESP_H
#define MT8816_ESP_H

#include "Arduino.h"

class Array {
public:
    int* data;
    int size;
    Array(int arr[], int sz) : data(arr), size(sz) {}
};

class MT8816{

    public:
        MT8816(int pin_reset, int pin_strobe, int pin_data, int pin_ay0, int pin_ay1, int pin_ay2, int pin_ax0, int pin_ax1, int pin_ax2, int pin_ax3);
        void begin();
        void reset();
        void setConnection(int x, int y);
        void broadcast(const Array& x, const Array& y);
    private:
        int PIN_RESET;
        int PIN_STROBE;
        int PIN_DATA;
        int PIN_AY0;
        int PIN_AY1;
        int PIN_AY2;
        int PIN_AX0;
        int PIN_AX1;
        int PIN_AX2;
        int PIN_AX3;
};

#endif
