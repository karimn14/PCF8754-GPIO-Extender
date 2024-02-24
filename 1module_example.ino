#include "Arduino.h"
#include "PCF8574.h"
// Set i2c address
PCF8574 pcf8574(0x27); //this is according to your address found on i2c_scanner
void setup()
{
  Serial.begin(115200);
  delay(1000);
  // Set pinMode to OUTPUT
  pcf8574.pinMode(P0, OUTPUT);
  pcf8574.pinMode(P3, OUTPUT);
  pcf8574.pinMode(P5, OUTPUT);
  Serial.print("Init pcf8574...");
  if (pcf8574.begin()) {
    Serial.println("OK");
  } else {
    Serial.println("KO");
  }
}
void loop()
{
  pcf8574.digitalWrite(P0, HIGH);
  delay(500);
  pcf8574.digitalWrite(P0, LOW);
  delay(500);
  pcf8574.digitalWrite(P3, HIGH);
  delay(500);
  pcf8574.digitalWrite(P3, LOW);
  delay(500);
  pcf8574.digitalWrite(P5, HIGH);
  delay(500);
  pcf8574.digitalWrite(P5, LOW);
  delay(500);
}
