#include <Servo.h>
Servo servo;
const int trigPin = 10;
const int echoPin = 8;
const int led = 3;
int pos = 0;  
long duration;
float distance;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(led, OUTPUT);
  servo.attach(13);
  servo.write(pos);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034*(duration/2);
  
  if (distance < 50){
    servo.write(pos+45);
    digitalWrite(led, HIGH);
    delay(100);
  }
  else {
    digitalWrite(led, LOW);
    servo.write(pos);
  }
  delay(100);
}