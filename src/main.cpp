#include <Arduino.h>
#include <Wire.h>


void setup() {
    Serial.begin(9600);
#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega2560__)
    Wire.begin();
#else
    Wire.begin(2, 14);
#endif

    Serial.println("Begin I2C bus scan ...");
    for (byte i = 8; i < 127; i++) {
        Wire.beginTransmission(i);
        if (Wire.endTransmission() == 0) {
            Serial.print("Found device @ 0x");
            Serial.println(i, HEX);
            delay(1);
        }
    }
    Serial.println("I2C bus scan complete.");
}

void loop() {
}