#include <SPI.h>
#include <nRF24L01p.h>

nRF24L01p transmitter(9, 10); //CSN,CE

String message;

void setup() {
  delay(150);
  Serial.begin(9600);
  Serial.println("TX baglanti saglandi");
  SPI.begin();
  SPI.setBitOrder(LSBFIRST);
  transmitter.channel(90);
  transmitter.TXaddress("Artur");
  transmitter.init();
}

void loop() {
  if (Serial.available() > 0) {
    char character = Serial.read();
    //Serial.println(character);
    if (character == 'g') {

      transmitter.txPL(message);
      boolean  state = transmitter.send(SLOW);
      delay(10);
      Serial.print("Mesaj : '");
      Serial.print(message);
      if (state == true)
        Serial.println(" gonderildi");
      else
        Serial.println(" gonderilemedi");

      message = "";
    }
    else {
      message += character;
    }
  }
}
