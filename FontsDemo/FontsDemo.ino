
#include <SPI.h>
#include <Wire.h>
#include "include/Adafruit_GFX.h"
#include "include/Adafruit_SSD1306_STM32.h"

#include "Fonts/FreeMono/FreeMono9pt7b.h"
#include "Fonts/FreeMono/FreeMonoBold9pt7b.h"
#include "Fonts/FreeMono/FreeMonoOblique9pt7b.h"

#include "Fonts/FreeSerif/FreeSerif9pt7b.h"
#include "Fonts/FreeSerif/FreeSerifBold9pt7b.h"
#include "Fonts/FreeSerif/FreeSerifItalic9pt7b.h"

#include "Fonts/FreeSans/FreeSans9pt7b.h"
#include "Fonts/FreeSans/FreeSansBold9pt7b.h"
#include "Fonts/FreeSans/FreeSansOblique9pt7b.h"

#include "Fonts/Roboto/Roboto-Regular-9.h"
#include "Fonts/Roboto/Roboto-Regular-8.h"

#include "Fonts/Roboto/Roboto-Light-9.h"
#include "Fonts/Roboto/Roboto-Light-8.h"

#include "Fonts/Satisfy/Satisfy-Regular-9.h"
#include "Fonts/Satisfy/Satisfy-Regular-8.h"

#include "Fonts/Cousine/Cousine-Regular-9.h"
#include "Fonts/Cousine/Cousine-Regular-8.h"

// If using software SPI (the default case):
#define OLED_MOSI  PA4
#define OLED_CLK   PA3
#define OLED_DC    PA6
#define OLED_CS    PA7
#define OLED_RESET PA5
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

const GFXfont fonts[] = {
  Roboto_Regular9pt7b,
  Roboto_Regular8pt7b,
  Roboto_Light9pt8b,
  Roboto_Light8pt7b,
  Satisfy_Regular9pt7b,
  Satisfy_Regular8pt7b,
  Cousine_Regular9pt7b,
  Cousine_Regular8pt7b,
  FreeMono9pt7b,
  FreeSerif9pt7b,
  FreeSans9pt7b
};

const int fontsSize = sizeof(fonts) / sizeof(fonts[0]);

int fontIndex = 0;

void setup()   {
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  // init done

  // prepare buffer
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}


void loop() {

  if (fontIndex >= fontsSize) {
    fontIndex = 0;
  }

  GFXfont font = fonts[fontIndex];
  display.clearDisplay();
  display.setCursor(0, 30);
  display.setFont(&font);
  display.println("Hello World!");
  display.display();
  delay(2000);
  fontIndex ++;
}
