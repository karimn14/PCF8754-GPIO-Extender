#include "Arduino.h"
#include "PCF8574.h"
// Set i2c address
PCF8574 first(0x20); //this is according to your address found on i2c_scanner
PCF8574 second(0x21);

void setup()
{
  Serial.begin(115200);
  delay(1000);
  // Set pinMode to OUTPUT
  first.pinMode(P0, INPUT);
  first.pinMode(P1, OUTPUT);
  second.pinMode(P0, INPUT);
  second.pinMode(P1, OUTPUT);
  
  Serial.print("Init pcf8574...");
  if (first.begin() & second.begin()) {
    Serial.println("OK");
  } else {
    Serial.println("KO");
  }
}
void loop()
{
  bool _bt0 = first.digitalRead(P0);
  bool _bt1 = second.digitalRead(P0);

  if (_bt0) first.digitalWrite(P1, HIGH);
  if (_bt1) second.digitalWrite(P1, HIGH);
}
