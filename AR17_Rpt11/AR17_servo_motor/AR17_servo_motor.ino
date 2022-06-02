/*
 예제 7.2
 서보모터 구동
*/
 
// 서보모터 라이브러리 불러오기
#include <Servo.h> 

// 서보모터 이름 설정
Servo motor1; 

// 서보 모터 신호핀 설정
int servoMotorPin = 9;

// 포텐쇼미터 핀 설정
int potentioMeterPin = 0;

const int left = 2;
const int right = 3;

// 모터 각도 변수 설정
int motorAngle;
int motorAngleOld;
void setup() {
  
  // 서보모터 설정. 0.6ms 부터 2.4ms 범위로 설정
  motor1. attach(servoMotorPin, 600, 2400);

  pinMode(left,INPUT_PULLUP);
  pinMode(right,INPUT_PULLUP);
  // 시리얼 통신 설정  
  Serial.begin(9600);
  
}


void loop(){
 if(digitalRead(left) == LOW) {
    motor1.write(0);
    delay(1000);
  }

  if(digitalRead(right) == LOW) {
  motor1.write(360);
  delay(1000);
  
  }
  delay(20);

}
