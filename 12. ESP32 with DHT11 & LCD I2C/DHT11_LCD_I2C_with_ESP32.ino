// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4
#define TAMPIL_SERIAL true

#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 20, 4); // Alamat I2C, jumlah kolom, jumlah baris
DHT dht(DHTPIN, DHTTYPE);

const byte KARAKTER_DERAJAT = 0;
byte derajat[] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
int hum = 0, temp = 0;

void setup() {
#if TAMPIL_SERIAL
  Serial.begin(9600);
  Serial.println(F("DHT 11 !"));
#endif

  lcd.init();
  lcd.createChar(KARAKTER_DERAJAT, derajat);
  lcd.backlight();
  lcd.setCursor(5, 0);
  lcd.print("DHT 11");
  lcd.setCursor(0, 1);
  lcd.print("TEMPERATUR :");
  lcd.setCursor(0, 2);
  lcd.print("HUMIDITY   :");

  dht.begin();
}

void loop() {
  delay(2000);  // Delay untuk 
  
  hum = dht.readHumidity();
  temp = dht.readTemperature(); // Baca temperatur dalam celcius (default)

  if (isnan(hum) || isnan(temp)) {
#if TAMPIL_SERIAL
  Serial.println(F("Failed to read from DHT sensor!"));
#endif
    return;
  }

  lcd.setCursor(13, 1);
  lcd.print(temp);
  lcd.setCursor(13, 2);
  lcd.print(hum);

  if(temp < 10){
    lcd.setCursor(14, 1);
  }else{
    lcd.setCursor(15, 1);
  }
  lcd.write(KARAKTER_DERAJAT);

  if(temp < 10){
    lcd.setCursor(15, 1);
  }else{
    lcd.setCursor(16, 1);
  }
  lcd.print("C");

  if(hum < 10){
    lcd.setCursor(14, 2);
  }else{
    lcd.setCursor(15, 2);
  }
  lcd.print("%");
  
#if TAMPIL_SERIAL
  Serial.println("\n================");
  Serial.print(F("Humidity: ")); Serial.print(hum); Serial.println("%");
  Serial.print(F("Temperature: ")); Serial.print(temp); Serial.println(F("°C "));
#endif

}
