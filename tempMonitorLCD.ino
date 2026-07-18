#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  Serial.begin(9600);
  dht.begin();

  lcd.begin(16, 2);
  lcd.print("Env Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {
  delay(2000);

  float humidity = dht.readHumidity();
  float tempF = dht.readTemperature(true);

  if (isnan(humidity) || isnan(tempF)) {
    Serial.println("Sensor read failed");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor error");
    lcd.setCursor(0, 1);
    lcd.print("Check wiring");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity, 1);
  Serial.print("%  Temp: ");
  Serial.print(tempF, 1);
  Serial.println(" F");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempF, 1);
  lcd.print((char)223);
  lcd.print("F");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidity, 1);
  lcd.print("%");
}