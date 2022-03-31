/*
 예제 4.2
 LED 밝기 조절
*/

const int ledA   =  3;	  //LED A를 3번핀에 연결
const int ledB   =  5;
int //LED B를 5번핀에 연결
int brightness = 0;       //밝기를 조절하기 위한 변수
int increment = 1;       //밝기 변수 증감을 위한 변수

void setup()
{
// analogWrite 핀에는 별도의 설정이 불필요하다.
}

void loop()
{
    // LED A 밝기 조절
    // LED B 밝기 조절
analogWrite(ledA,brightness);
analogWrite(ledB,255-brightness);
  	// 밝기 조절
    // 밝기 변수 증감 방향 변경
    brightness = brightness + increment;
    if((brightness>= 255)||(brightness <=0)) increment = -increment;
  delay(10);    // 0.01 초간 지연
}
