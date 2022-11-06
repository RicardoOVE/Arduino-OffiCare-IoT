#include <Arduino.h>

/***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BMP280 Breakout
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/
// Librerias y definición para la lectura del sensor BMP280
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

// Liberias DHT11/DHT22
//#include "DHT.h"

//#define DHTPIN 4
//#define DHTTYPE DHT22 

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)
// Librerias para display SSD1306

//#include <Adafruit_GFX.h> 
//#include <Adafruit_SSD1306.h> 
//#include <Fonts/FreeMonoBold9pt7b.h>

//#define SCREEN_WIDTH 128 // OLED display width, in pixels 
//#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 & BMP280 display connected to I2C (SDA, SCL pins) 
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_BMP280 bmp; // I2C

//DHT dht(DHTPIN, DHTTYPE);

//Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);

void setup() {
  Serial.begin(9600);
  //Serial.println(F("BMP280 test"));

  /*if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64 
    Serial.println(F("SSD1306 allocation failed")); 
    for(;;); 
  } */

  //dht.begin();
  delay(1500); 
  
//  display.clearDisplay();
//
////  display.setFont(&FreeMonoBold9pt7b); 
//  display.setTextSize(1); 
//  display.setTextColor(WHITE); 
//  display.invertDisplay(true); 
////  display.setCursor(13, 35);
//  display.setCursor(38,10);
//  display.println("OffiCare"); 
//  display.setCursor(35,20);
//  display.println("Temperature");
//  display.setCursor(60,30);
//  display.println("&");  
//  display.setCursor(20,40);
//  display.println("Pressure Station");     
//  display.display();
  delay(2000);

  //if (!bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID)) {
  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    while (1) delay(10);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void loop() {

  //Lectura de variables con sensor BMP280
  float temp = bmp.readTemperature();
  float pres = bmp.readPressure();
  float alt = bmp.readAltitude(1013.25); /* Adjusted to local forecast! */

  //Lectura de variables con sensot DHT11
  //float humid = dht.readHumidity();

  // Impresión en pantalla SSD1306

//    display.clearDisplay(); 
//    display.setFont(); 
//    display.setTextSize(1); 
//    display.setTextColor(WHITE); 
//    display.setCursor(5, 20); 
//    String temperature;
//    temperature += F("Temp (C)= ");
//    temperature += String(temp);
//    display.print(temperature); 
//    display.setCursor(5, 30); 
//    String pressure;
//    pressure += F("Pres (Pa)= ");
//    pressure += String(pres);
//    display.print(pressure);
//    display.setCursor(5, 40);
//    String altitude;
//    altitude += F("Alt  (m)= ");
//    altitude += String(alt);
//    display.print(altitude);  
//    //display.setCursor(5, 50);
//    //String humidity;
//    //humidity += F("Hum (%)= ");
//    //humidity += String(humid);
//    //display.print(humidity);
//    display.display(); 

  // Impresión en consola IDE

    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    /*Serial.print(bmp.readPressure()/101325);
    Serial.println(" atm"); */

    Serial.print(F("Approx altitude = "));
    Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");

    //Serial.print(F("Humidity = "));
    //Serial.print(dht.readHumidity());
    //Serial.println(" %");    

    Serial.println();
    delay(500);
}