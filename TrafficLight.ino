#include <Arduino.h>
int CurrentLedState = 1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, STM32!");
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, CurrentLedState);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000); // this speeds up the simulation
  digitalWrite(LED_BUILTIN, CurrentLedState);
  if (CurrentLedState == HIGH)
  {
    CurrentLedState = LOW;
  }
  else 
  {
    CurrentLedState = HIGH;
  }
}

