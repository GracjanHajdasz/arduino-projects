#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 7
#define DHTTYPE DHT11
#define MOTORPIN 9

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  pinMode(MOTORPIN, OUTPUT);
  analogWrite(MOTORPIN, 0);
}

void loop() {
  lcd.setCursor(0, 1);
  delay(2000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    lcd.print(F("Blad czujnika DHT!"));
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print(F("Wilg: "));
  lcd.print(humidity, 1);
  lcd.print(F("%"));

  lcd.setCursor(0, 1);
  lcd.print(F("Temp: "));
  lcd.print(temperature, 1);
  lcd.print((char)223);
  lcd.print(F("C"));

  if (temperature >= 25.0) {
    analogWrite(MOTORPIN, 150);
  } else {
    analogWrite(MOTORPIN, 0);
  }
}