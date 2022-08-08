#include <MKRWAN_v2.h>

LoRaModem modem;

#include "arduino_secrets.h"
String appEui = SECRET_APP_EUI;
String appKey = SECRET_APP_KEY;

//#define _DEBUG_

void setup() {
  #ifdef _DEBUG_
    Serial.begin(9600);
    while (!Serial);
  #endif
  
  Serial1.begin(9600);
  while (!Serial1);
  
  if (!modem.begin(AS923)) {
    while (1) {}
  };

  #ifdef _DEBUG_
    Serial.print("Your module version is: ");
    Serial.println(modem.version());
    Serial.print("Your device EUI is: ");
    Serial.println(modem.deviceEUI());
  #endif

  if (!modem.joinOTAA(appEui, appKey)) {
    while (1) {}
  }

  modem.minPollInterval(60);
}

void loop() {
  modem.setPort(1);
  modem.beginPacket();
  modem.print("hello");
  err = modem.endPacket(true);
  if (err <= 0) {
    #ifdef _DEBUG_
      Serial.println("Send failed..");
    #endif
  } else {
    #ifdef _DEBUG_
      Serial.println("Send Success!");
    #endif
  }
  delay(1000);
}
