#include <Wifi.h>
#include <PubSubClient.h>
// set vars
const int trigPin = 10;
const int echoPin = 11;
long duration;
int distance;
char ssid[] = "Telus5190"
char pass[] = "5qbj5g8mgv"
void setup() {
  
// set io
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(13, OUTPUT);
pinMode(8, OUTPUT);
Serial.begin(9600); 
}
void loop() {
// get distance
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
int distancea = distance;
distance= duration*0.034/2;

//do stuff based on distance
if (distance<200 and (distance-distancea>2 or distance-distancea<-2)){
  digitalWrite(8,HIGH);
  Serial.println("{message: \"Too Close\", distance:"+String(distance)+"}");
  tone(13,2000);
  delay(50);
}else{
  digitalWrite(8,LOW);
  noTone(13);
}

// reset for next loop
noTone(13);
delay(250);
}
