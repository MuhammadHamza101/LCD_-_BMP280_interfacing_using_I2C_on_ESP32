/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_BMP280.h>
LiquidCrystal_I2C lcd(0x27,20,4);

Adafruit_BMP280 bmp; // I2C
float Temperature, Pressure, Altitude;
void setup()
{
  lcd.begin();
  bmp.begin(0x76);
  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Hello World :)");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Finally it's me");
  delay(1000);
  lcd.setCursor(0, 2);
  lcd.print("Muhammad Hamza ");
  delay(1000);
  lcd.setCursor(0, 3);
  lcd.print("The Magician!");
  delay(3000);
}


void loop()
{
    Temperature = bmp.readTemperature();
    Pressure = bmp.readPressure();
    Altitude = bmp.readAltitude(1013.25); /* Adjusted to local forecast! */
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" -Weather Station-");
    delay(100);
    lcd.setCursor(0, 1);
    char stringVal[10]; // Create a character array to store the value
    dtostrf(Temperature, 4, 2, stringVal); // Convert float to string
    lcd.print("Temperature: ");
    lcd.print(stringVal);
    lcd.print("*C");
    delay(100);
    lcd.setCursor(0, 2);
    lcd.print("Pressure: ");
    dtostrf(Pressure, 4, 2, stringVal); // Convert float to string
    lcd.print(stringVal);
    lcd.print("Pa");
    delay(100);
    lcd.setCursor(0, 3);
    lcd.print("Altitude: ");
    dtostrf(Altitude, 4, 2, stringVal); // Convert float to string
    lcd.print(stringVal);
    lcd.print("m");
    delay(3000);

}