#include <SPI.h>
#include <nRF24L01p.h>

nRF24L01p receiver(7, 8); //CSN,CE

String message;

void setup() {
  delay(150);
  message = "";
  Serial.begin(9600);
  Serial.println("RX baglanti saglandi");
  SPI.begin();
  delay(10);
  SPI.setBitOrder(MSBFIRST);
  delay(10);
  receiver.channel(90);
  delay(10);
  receiver.RXaddress("Artur");
  delay(10);
  receiver.init();
  delay(10);
  
}



void loop() {
  if (receiver.available()) {
    receiver.read();
    receiver.rxPL(message);
    if (message.length() > 0)
    {
      Serial.print(message);
      message = "";
    }
  }


}
