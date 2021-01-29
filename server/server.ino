#include "etherShield.h"
#include "ETHER_28J60.h"
 
static uint8_t mac[6] = {0x54, 0x55, 0x58, 0x10, 0x00, 0x24};   
static uint8_t ip[4] = {192, 168, 1, 63};                      
static uint16_t port = 80;
//#define SENSOR A5
const int LED = 3;
boolean key = false;
                                    
 
ETHER_28J60 ethernet;
 
void setup()
{ 
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  ethernet.setup(mac, ip, port);  
}


void loop()
{
  char* param;
  if (param = ethernet.serviceRequest())
   // int val = analogRead(SENSOR);
    if (strcmp(param, "1") == 0) {
      key = !key;
      switcher(key);
      //ethernet.print(param);
      ethernet.print(key);
    ethernet.respond();
  }
  delay(50);
}


void switcher(boolean key) {
  if (key) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
