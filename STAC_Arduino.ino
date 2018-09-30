#include <SimpleDHT.h>

SimpleDHT11 dht11;
int dhtpin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte temperature = 0;
  byte humidity = 0;
  if(dht11.read(dhtpin, &temperature, &humidity, NULL)){
    Serial.print("DHT Error");
  }
  int to = map(analogRead(0), 1023, 350, 0, 100);
  int t = (int)temperature;
  int h = (int)humidity;
  Serial.print(t);
  Serial.print(",");
  Serial.print(h);
  Serial.print(",");
  Serial.println(to);
  
  delay(1500);
}
