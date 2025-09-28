#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// TFT pins
#define TFT_CS     10
#define TFT_RST    8
#define TFT_DC     9

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

int eyeRadius = 20;
int pupilRadius = 8;

// Eye positions
int eyeLX = 40;
int eyeLY = 64;
int eyeRX = 88;
int eyeRY = 64;

int pupilOffsetX = 0;
int pupilOffsetY = 0;

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.fillScreen(ST77XX_BLACK);
}

void loop() {
  // Clear background
  tft.fillScreen(ST77XX_BLACK);

  // Draw eyeballs
  tft.fillCircle(eyeLX, eyeLY, eyeRadius, ST77XX_WHITE);
  tft.fillCircle(eyeRX, eyeRY, eyeRadius, ST77XX_WHITE);

  // Random eye movement
  pupilOffsetX = random(-6, 6);
  pupilOffsetY = random(-4, 4);

  // Pupils
  tft.fillCircle(eyeLX + pupilOffsetX, eyeLY + pupilOffsetY, pupilRadius, ST77XX_BLACK);
  tft.fillCircle(eyeRX + pupilOffsetX, eyeRY + pupilOffsetY, pupilRadius, ST77XX_BLACK);

  // Sometimes blink
  if (random(0, 15) == 0) {
    blink();
  }

  delay(500);
}

void blink() {
  for (int i = 0; i < eyeRadius * 2; i += 4) {
    // Closing eyelids
    tft.fillRect(eyeLX - eyeRadius, eyeLY - eyeRadius, eyeRadius * 2, i, ST77XX_BLACK);
    tft.fillRect(eyeRX - eyeRadius, eyeRY - eyeRadius, eyeRadius * 2, i, ST77XX_BLACK);
    delay(25);
  }
  delay(150); // closed
  for (int i = eyeRadius * 2; i >= 0; i -= 4) {
    // Opening eyelids
    tft.fillRect(eyeLX - eyeRadius, eyeLY - eyeRadius, eyeRadius * 2, i, ST77XX_BLACK);
    tft.fillRect(eyeRX - eyeRadius, eyeRY - eyeRadius, eyeRadius * 2, i, ST77XX_BLACK);
    delay(25);
  }
}
