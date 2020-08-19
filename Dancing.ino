#include <Adafruit_NeoPixel.h>

float I;
float X;
float P;
float G;
byte Phase;
float RGB[3];

#define LEDs 144  // How many NeoPixels are attached to the Arduino?
#define Pi 3.14159

Adafruit_NeoPixel pixels(LEDs, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.setBrightness(255);
}

void loop() {
  for (G = 2; G <= 8; G++) {
    for (I = 1; I < LEDs; I = I + .125) {
      for (X = 1; X <= G; X++) {
        P = (LEDs / 4) + (LEDs / 4) * sin(2 * (Pi / LEDs) * I + (X * (2 / G) * Pi));
        P = P + ((LEDs / 4) + (LEDs / 4) * sin(8 * (Pi / LEDs) * I + (X * (2 / G) * Pi)));
        for (Phase = 0; Phase <= 2; ++Phase) {
          RGB[Phase] = 63.5 + (2 * 192.2 / Pi) * asin(cos(2 * (Pi / 60) * (X * (60 / G)) + ((Phase / 1.5)) * Pi));
          RGB[Phase] = max(RGB[Phase], 0);
        }
        pixels.setPixelColor(P, RGB[0], RGB[1], RGB[2]);
      }
    pixels.show();   
    delay(1);
    pixels.clear();
    }
  }
}
