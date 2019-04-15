#include <FastLED.h>

#include <SPI.h>
#include <SD.h>

#define DATA_PIN 8
#define CLOCK_PIN 9
#define LED_COUNT 144

const int chipSelect = 10;

// Define the array of leds
CRGB leds[LED_COUNT];

void setup() {
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, LED_COUNT);

  Serial.begin(9600);
  while (!Serial);
  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");
  File dataFile = SD.open("kitten.hex");
  char rgb[6];
  unsigned counter = 0;
  if (dataFile) {
    while (dataFile.available()) {
      for (int i = 0; i < 6; i++)
        rgb[i] = dataFile.read();
      leds[counter] = CRGB((long) strtoul(rgb, 0, 16));
      //Serial.println(leds[counter], HEX);
      counter++;
      if (counter >= LED_COUNT) {
        counter = 0;
        FastLED.show();
        Serial.print(".");
      }
    }
    for (int i = 0; i < LED_COUNT; i++) {
      leds[i] = CRGB::Black;
    }
    FastLED.show();
    dataFile.close();
    Serial.println("");
    Serial.println("finished");
  } else {
    Serial.println("Could not open file");
  }
}

void loop() {
}

