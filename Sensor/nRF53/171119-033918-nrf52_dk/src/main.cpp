#include <Arduino.h>
#include <SPI.h>
#include <BLEPeripheral.h>

#ifndef UNIT_TEST

BLEPeripheral squeezePeripheral = BLEPeripheral();

BLEService squeezeService = BLEService("19b10000e8f2537e4f6cd104768a1214");
BLEIntCharacteristic squeezeCharacteristic = BLEIntCharacteristic("19b10001e8f2537e4f6cd104768a1214", BLERead);

void setup()
{
  squeezePeripheral.setAdvertisedServiceUuid(squeezeService.uuid());
  squeezePeripheral.addAttribute(squeezeCharacteristic);
  squeezePeripheral.setLocalName("Squeeze Sensor");
  squeezePeripheral.begin();

  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  BLECentral central = squeezePeripheral.central();

  if (central) {
    while (central.connected()) {
      squeezeCharacteristic.setValue(digitalRead(10) + digitalRead(11) + digitalRead(12) + digitalRead(13));
    }
  }

  if(digitalRead(10) > 0)
    digitalWrite(6, HIGH);
  else
    digitalWrite(6, LOW);
  if(digitalRead(11) > 0)
    digitalWrite(7, HIGH);
  else
    digitalWrite(7, LOW);
  if(digitalRead(12) > 0)
    digitalWrite(8, HIGH);
  else
    digitalWrite(8, LOW);
  if(digitalRead(13) > 0)
    digitalWrite(9, HIGH);
  else
    digitalWrite(9, LOW);
}

#endif