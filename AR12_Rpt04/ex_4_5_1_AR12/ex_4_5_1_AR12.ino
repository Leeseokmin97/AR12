

// 0~9까지 LED 표시를 위한 상수
const byte number[10] = { 
  //dot  gfedcba
  B01110111,	//a
  B01111100,	//b
  B00111001,	//c
  B01011110,	//d
  B01111001,	//e
  B01110001,	//f
  
};

// 표시할 숫자 변수
int count = 0;  

void setup()
{
  // 2~9번 핀을 a b c d e f g dot 의 순서로 사용한다.
  // 10~13번 핀을 Digit 1~4 의 순서로 사용한다.
  for(int i =2; i <=9; ++i){
    pinMode(i,OUTPUT);
  };
  
  digitalWrite(9,LOW);

  
}

void loop()
{
  // count 변수값을 FND에 출력한다.
  for(int k=0; k<=9;++k){
  fndDisplay(count);  

  // count 변수값이 0~9의 범위를 갖도록한다.  
  
  
  delay(1000);
} ;
}

// LED 켜는 루틴
void fndDisplay(int displayValue){  
  // bitValue 변수를 선언한다.
  boolean bitValue;

  // 2~9번핀에 모두 LOW 신호를 줘서 소등시킨다.
  for(int i=2; i<=9; ++i){	
    digitalWrite(i, LOW);
  };

  for(int i=0; i<=7; ++i){
  // number 상수의 하나의 비트값을 읽는다.
    bitValue = bitRead(number[displayValue],i);
  // 앞서 읽은 비트값을 2~9번핀에 출력시킨다.
    digitalWrite(i+2,bitValue);
  };
}
