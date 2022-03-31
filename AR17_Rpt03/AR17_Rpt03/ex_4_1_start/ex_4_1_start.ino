/*
 예제 4.1
 LED 점멸
*/

const int ledA   =  3;
const int ledB   =  5;

int number = 1;
boolean flag = true;

void setup()
{
  Serial.begin(9600);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop()
{
  digitalWrite(ledA,HIGH);
  digitalWrite(ledB,LOW);
  delay(100);
  digitalWrite(ledA,LOW);
  digitalWrite(ledB,HIGH);
  delay(100);
}
