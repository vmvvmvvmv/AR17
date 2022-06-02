/*
 예제 7.1
 스텝모터 구동
 */
const int cw_cw = 2;
const int cw_stop = 3;
const int cw_ccw = 4;
 
// 스텝 모터 신호핀 설정
int motorPin1 = 8;
int motorPin2 = 9;
int motorPin3 = 10;
int motorPin4 = 11;

boolean cwcw = false;
boolean cwstop = false;
boolean cwccw = true;
// 포텐쇼미터 핀 설정
int potentioMeterPin = 0;

// stop 구간 폭 설정
int stopRange = 100;

// 모터 속도 관련 변수 설정
int motorSpeed; // 스텝 사이의 지연시간으로서 4500~1000의 범위를 갖는다. 
int motorSpeedPercent; // 속도를 0~100%로 나타낸다.

// 스텝 모터의 스텝 설정
// 0~7은 동작 신호, 8번째는 모터 정지 신호
int steps[] = {B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001, B0000};

void setup() {
  //모터 신호핀을 출력으로 설정
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  pinMode(cw_cw, INPUT_PULLUP);
  pinMode(cw_stop, INPUT_PULLUP);
  pinMode(cw_ccw, INPUT_PULLUP);
  // 시리얼 통신 설정  
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(cw_cw) == LOW) {
    cwcw = true;
    cwstop = false;
    cwccw = false;
  }
  else if (digitalRead(cw_stop) == LOW) {
    cwcw = false;
    cwstop = true;
    cwccw = false;
  }
  else if (digitalRead(cw_ccw) == LOW) {
    cwcw = false;
    cwstop = false;
    cwccw = true;
  }


if (cwcw == true) {
  clockwise();
}
else if cwstop == true {
  motorstop();
}
else if cwccw == true {
  countClockwise();
}

void counterClockwise(){
  // 0~7 번째 신호를 순차적으로 출력시킨다.
  for(int i = 0; i < 8; i++)
  {
    motorSignalOutput(i);
    delayMicroseconds(motorSpeed);
  }
}
}

void clockwise(){
  // 7~0 번째 신호를 순차적으로 출력시킨다.
  for(int i = 7; i >= 0; i--)
  {
    motorSignalOutput(i);
    delayMicroseconds(motorSpeed);
  }
}

void motorStop(){
  // 정지신호를 출력시킨다.
  motorSignalOutput(8); 
}

void motorSignalOutput(int out)
{
  // out 변수에 해당하는 모터 시그날을 출력한다.
  digitalWrite(motorPin1, bitRead(steps[out], 0));
  digitalWrite(motorPin2, bitRead(steps[out], 1));
  digitalWrite(motorPin3, bitRead(steps[out], 2));
  digitalWrite(motorPin4, bitRead(steps[out], 3));
}
