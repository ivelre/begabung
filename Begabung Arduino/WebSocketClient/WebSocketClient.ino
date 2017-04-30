/*
 * WebSocketClient.ino
 *
 *  Created on: 24.05.2015
 *
 */
#define USE_SERIAL Serial
#include<Wire.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsClient.h>
#include <Hash.h>
const int MPU2=0x69,MPU1=0x68;
int16_t AcX1,AcY1,AcZ1,Tmp1,GyX1,GyY1,GyZ1;
int16_t AcX2,AcY2,AcZ2,Tmp2,GyX2,GyY2,Gyz2;
int data;
boolean estado = 0;
unsigned long tiempo_actual = 0;
ESP8266WiFiMulti WiFiMulti;
WebSocketsClient webSocket;

void webSocketEvent(WStype_t type, uint8_t * payload, size_t lenght) {


    switch(type) {
        case WStype_DISCONNECTED:
            USE_SERIAL.printf("[WSc] Disconnected!\n");
            break;
        case WStype_CONNECTED:
            {
                USE_SERIAL.printf("[WSc] Connected to url: %s\n",  payload);
        
          // send message to server when Connected
        webSocket.sendTXT("Connected");
            }
            break;
        case WStype_TEXT:
            USE_SERIAL.printf("[WSc] get text: %s\n", payload);

      // send message to server
      // webSocket.sendTXT("message here");
            break;
        case WStype_BIN:
            USE_SERIAL.printf("[WSc] get binary lenght: %u\n", lenght);
            hexdump(payload, lenght);

            // send data to server
            // webSocket.sendBIN(payload, lenght);
            break;
    }

}

void setup() {
   Wire.begin(0,2);
  Wire.beginTransmission(MPU1);
  Wire.write(0x6B);
  Wire.write(0); //Se le envía 0 para despertar el MPU-6050
    // USE_SERIAL.begin(921600);
    USE_SERIAL.begin(115200);

    //Serial.setDebugOutput(true);
    USE_SERIAL.setDebugOutput(true);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();

      for(uint8_t t = 4; t > 0; t--) {
          USE_SERIAL.printf("[SETUP] BOOT WAIT %d...\n", t);
          USE_SERIAL.flush();
          delay(1000);
      }

    WiFiMulti.addAP("ITESM" ,"");

    //WiFi.disconnect();
    while(WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
    }

    webSocket.begin("10.24.177.12", 1337);
    webSocket.setAuthorization("A01209745", ":3:*xDc:"); // HTTP Basic Authorization
    webSocket.onEvent(webSocketEvent);

}

void getMpuValue(const int MPU){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true);
  AcX1=Wire.read()<<8| Wire.read();
  AcY1=Wire.read()<<8| Wire.read();
  AcZ1=Wire.read()<<8| Wire.read();
  Tmp1=Wire.read()<<8| Wire.read();
  GyX1=Wire.read()<<8| Wire.read();
  GyY1=Wire.read()<<8| Wire.read();
  GyZ1=Wire.read()<<8| Wire.read();
}

void loop() {
    webSocket.loop();
    //webSocket.sendTXT("true");
    unsigned long tiempo = millis();

    if((tiempo - tiempo_actual) > 1000UL) {
      tiempo_actual = tiempo;
    }
  getMpuValue(MPU1);
        webSocket.sendTXT("AcX1");
        webSocket.sendTXT(AcX1);
        webSocket.sendTXT("AcY1");
        webSocket.sendTXT(AcY1);
        webSocket.sendTXT("AcZ1");
        webSocket.sendTXT(AcZ1);
        webSocket.sendTXT("GcX1");
        webSocket.sendTXT(GcX1);
        webSocket.sendTXT("GcY1");
        webSocket.sendTXT(GcY1);
        webSocket.sendTXT("GcZ1");
        webSocket.sendTXT(GcZ1);  
}
