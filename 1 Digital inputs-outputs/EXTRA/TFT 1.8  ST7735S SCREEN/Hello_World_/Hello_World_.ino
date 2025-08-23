  #include <Adafruit_GFX.h>    // Core graphics
  #include <Adafruit_ST7735.h> // ST7735 driver
  #include <SPI.h>

  // Pin definitions
  #define CS     10
  #define RST    8
  #define DC     9

  // Create display object
  Adafruit_ST7735 screen = Adafruit_ST7735(CS, DC, RST);

  void setup() 
  {
    Serial.begin(9600);
    Serial.println("ST7735S TFT Test");
    // Initialize TFT
    screen.initR(INITR_BLACKTAB); // INITR_BLACKTAB, INITR_GREENTAB, INITR_REDTAB depending on your screen
    screen.fillScreen(ST77XX_BLACK);
    // Test text
    screen.setTextColor(ST77XX_GREEN);
    screen.setTextSize(1.2);
    screen.println("Hello World!");
    
    screen.setTextColor(ST77XX_YELLOW); 
    screen.println("Yellow");
   
    screen.setTextColor(ST77XX_CYAN);
    screen.println("Cyan");

    screen.setTextColor(ST77XX_WHITE);
    screen.println("White");

    screen.setTextColor(ST77XX_BLUE);
    screen.println("Blue");

    screen.setTextColor(ST77XX_RED);
    screen.println("Red");

    screen.setTextColor(ST77XX_ORANGE);
    screen.println("Orange");

    screen.setTextColor(ST77XX_MAGENTA);
    screen.println("Magenta");

  }

  void loop() 
  {
    
    
  }
