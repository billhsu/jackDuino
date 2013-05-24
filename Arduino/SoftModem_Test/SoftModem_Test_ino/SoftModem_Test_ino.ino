#include <SoftModem.h>
#include <ctype.h>

SoftModem modem;

void setup()
{
  Serial.begin(57600);
  delay(1000);
  modem.begin();
}

void loop()
{
  while(modem.available()){
    int c = modem.read();
    if(isprint(c)){
      Serial.println((char)c);
    }
    else{
      Serial.print("(");
      Serial.print(c,HEX);
      Serial.println(")");      
    }
  }
  if(Serial.available()){
    modem.write(0xff);
    while(Serial.available()){
      char c = Serial.read();
      modem.write(c);
    }
  }
}

