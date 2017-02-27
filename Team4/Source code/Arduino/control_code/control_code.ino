//control
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(5, 3); //Tx, Rx 확인
//조이스틱
int X = A4;
int Y = A5;
float dir;

//압력센서
int P=A3;
int a;

//진동
const int motorPin = 7;
const int motorPin1 = 4;

//초음파
int distance;
int distance1;
void setup() 
{
  
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  
}

void joystick();

void loop() 
{
  char vib;
  vib = bluetooth.read();
  switch(vib)
  {
    case 'a':
    digitalWrite(motorPin, HIGH);
    delay(200);
    digitalWrite(motorPin, LOW);
    Serial.println("left");
  break;

  case 'b':

    digitalWrite(motorPin1, HIGH);
    delay(200);
    digitalWrite(motorPin1, LOW);
    Serial.println("right");  
  break;

  case 'c':
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin, HIGH);
    delay(200);
    digitalWrite(motorPin, LOW);
    digitalWrite(motorPin1, LOW);
    Serial.println("both");
    break;
  
  }//진동 모터

float x,y,s;
a=map(analogRead(P),0,300,1,100);
Serial.print("pressure = ");
Serial.println(a);
x=map(analogRead(X),0,1023,1,100);
y=map(analogRead(Y),0,1023,1,100);
dir = y/x*100;
//  Serial.print("   X =  ");
//  Serial.println(x,DEC);
//  
//  Serial.print("   Y =  ");
//  Serial.println(y,DEC);
//
//  
  Serial.print("   dir =  ");
  Serial.println(dir,DEC);

if(a>=0&&a<5){
  bluetooth.write('x');
  delay(500);
  }
  else
  {
joystick();
delay(500);
  }

delay(500);
}

void joystick()
{
//  if(Serial.available())        //뭔갈 주어야(?)
//  {
if(dir>=100&&dir<106)
{
bluetooth.write('x');
Serial.println("stopF");
delay(1000);
//stopF();
}

else if((dir>=1&&dir<50)&&(a>=10&&a<40))
{
bluetooth.write('a');
Serial.println("turnL");
delay(1000);  
//turnL();
}

else if((dir>=1&&dir<50)&&(a>=40&&a<70))
{
bluetooth.write('b');
Serial.println("turnL");
delay(1000);  
//turnL();
}

else if((dir>=1&&dir<50)&&(a>=70))
{
bluetooth.write('c');
Serial.println("turnL");
delay(1000);  
//turnL();
}

else if((dir>=200&&dir<500)&&(a>=10&&a<40))
{
bluetooth.write('d');
Serial.println("turnR");
delay(1000);  
//turnR();
}

else if((dir>=200&&dir<500)&&(a>=40&&a<70))
{
bluetooth.write('e');
Serial.println("turnR");
delay(1000);  
//turnR();
}

else if((dir>=200&&dir<500)&&(a>=70))
{
bluetooth.write('f');
Serial.println("turnR");
delay(1000);  
//turnR();
}

else if((dir>=50&&dir<90)&&(a>=10&&a<40))
{
bluetooth.write('g');
Serial.println("goF");
delay(1000);  
//goF();
}

else if((dir>=50&&dir<90)&&(a>=40&&a<70))
{
bluetooth.write('h');
Serial.println("goF");
delay(1000);  
//goF();
}

else if((dir>=50&&dir<90)&&(a>=70))
{
bluetooth.write('i');
Serial.println("goF");
delay(1000);  
//goF();
}

else if((dir>=4000&&dir<5200)&&(a>=10&&a<40))
{
bluetooth.write('j');
Serial.println("back");
delay(1000);  
//backF();
}
else if((dir>=4000&&dir<5200)&&(a>=40&&a<70))
{
bluetooth.write('k');
Serial.println("back");
delay(1000);  
//backF();
}

else if((dir>=4000&&dir<5200)&&(a>=70))
{
bluetooth.write('l');
Serial.println("back");
delay(1000);  
//backF();
}

//  }
}
