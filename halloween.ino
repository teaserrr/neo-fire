
#include <Adafruit_NeoPixel.h>

#define PIN      8
#define N_LEDS  100

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_RGB + NEO_KHZ800);

unsigned long timeToRun = 6 * 3600000;
unsigned long timeToSleep = 24 * 3600000 - timeToRun;
unsigned long startTime;

void setup()
{
    strip.begin();
    startTime = millis();
}

void loop() {
    if (millis() - startTime > timeToRun) {
        turnAllOff();
        delay(timeToSleep);
        startTime = millis();
    }
    effect();
    delay(10+random(50));
}

void effect() {
    for (int i = 0; i < N_LEDS; i++) {
        uint8_t brightness = 100+random(100);
        uint8_t red = brightness;
        uint8_t green = (uint8_t)(brightness * 0.3);
        uint8_t blue = (uint8_t)(brightness * 0.05);
        setPixel(i, red, green, blue);
    }
    strip.show();
}

void turnAllOff() {
    for (int i = 0; i < N_LEDS; i++) {
        setPixel(i, 0, 0, 0);
    }
    strip.show();
}

void setPixel(int pixel, byte red, byte green, byte blue) {
   strip.setPixelColor(pixel, strip.Color(red, green, blue));
}
