#include "led.hpp"

Led led(9, 10, 6);
int R, G, B, statusRGB;

void setup() {
    Serial.begin(115200);
    led.setBrightness(100);
    led.on();
}

void loop() {
    if (Serial.available() == 10) {
        char msg[10];
        Serial.readBytes(msg, sizeof(msg));
        R = (msg[0] - 48) * 100 + (msg[1] - 48) * 10 + (msg[2] - 48);
        G = (msg[3] - 48) * 100 + (msg[4] - 48) * 10 + (msg[5] - 48);
        B = (msg[6] - 48) * 100 + (msg[7] - 48) * 10 + (msg[8] - 48);
        statusRGB = msg[9] - 48;
    }

    if (statusRGB == 1) led.RGB(20);
    else led.setColor(R, G, B);
    led.update();
}