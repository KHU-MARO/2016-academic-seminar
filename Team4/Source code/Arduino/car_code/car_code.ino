//car
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(5, 3); //tx, rx 확인
//조이스틱
int X = A4;
int Y = A5;
float dir;

//초음파
int trigPin = 4;   
int echoPin = 7;
int trigPin1 = 2;   
int echoPin1 = 6;

//모터
int ENB=10;
int IN3=8;
int IN4=9;
int ENA = 11;
int IN1 = 12;
int IN2 = 13;

void setup() 
{
  
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  pinMode(X, INPUT);
  pinMode(Y, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);


}

void goF(char ch)
{   digitalWrite(IN1,HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("goF");
    
        if (ch =='g'){
        int g = 80;
        //while(g<=120){
        analogWrite(ENA, g);
        analogWrite(ENB, g);
        //g++;
        delay(100);
        //}
    }
        
    else if(ch=='h'){
        int h = 120;
        //while(h<=160){
        analogWrite(ENA, h);
        analogWrite(ENB, h);
       //h++;
        delay(100);
        //}
    }
    else if(ch=='i'){
        int i=160;
        //while(i<=200){
          analogWrite(ENA,i);
          analogWrite(ENB,i);
          //i++;
          delay(100);
        //}
    }
    
  }
void turnL(char ch)
{   digitalWrite(IN1,HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4, LOW);
    Serial.println(" turnL");

        if (ch =='a'){
        int a = 100;
        //while(a<=120){
        analogWrite(ENA, a);
        analogWrite(ENB, a-70);
        //a++;
        delay(100);
        //}
    }
        
    else if(ch=='b'){
        int b = 120;
        //while(b<=160){
        analogWrite(ENA, b);
        analogWrite(ENB, b-70);
        //b++;
        delay(100);
        //}
    }
    else if(ch=='c'){
        int c=160;
        //while(c<=200){
          analogWrite(ENA,c);
          analogWrite(ENB,c-70);
          //c++;
          delay(100);
        //}
    }

    }

void turnR(char ch)
{   digitalWrite(IN1,HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("turnR");

    if (ch =='d'){
        int d = 100;
        //while(d<=120){
        analogWrite(ENA, d-70);
        analogWrite(ENB, d);
        //d++;
        delay(100);
        //}
    }
        
    else if(ch=='e'){
        int e = 120;
        //while(e<=160){
        analogWrite(ENA, e-70);
        analogWrite(ENB, e);
        //e++;
        delay(100);
        //}
    }
    else if(ch=='f'){
        int f=160;
        //while(f<=200){
          analogWrite(ENA,f-70);
          analogWrite(ENB,f);
          //f++;
          delay(100);
        //}
   }

 }
void stopF()
{   digitalWrite(IN1,LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    Serial.println("stopF");
    }
void backF(char ch)
{   digitalWrite(IN1,LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4, HIGH);
    Serial.println("backF");
    
    if (ch =='j'){
        int j = 80;
        //while(j<=120){
        analogWrite(ENA, j);
        analogWrite(ENB, j);
        //j++;
        delay(100);
        //}
    }
        
    else if(ch=='k'){
        int k = 120;
        //while(k<=160){
        analogWrite(ENA, k);
        analogWrite(ENB, k);
        //k++;
        delay(100);
        //}
    }
    else if(ch=='l'){
        int l=160;
        //while(l<=200){
          analogWrite(ENA,l);
          analogWrite(ENB,l);
          //l++;
          delay(100);
        //}
    }

    }    
void getSignal()
{
  if(bluetooth.available())
  {
    char data = bluetooth.read();
    switch(data)
    {
      case 'a':
      
      turnL(data);
      delay(50);
      break;

      case 'b':
      
      turnL(data);
      delay(50);
      break;

      case 'c':
      
      turnL(data);
      delay(50);
      break;

      case 'd':
      
      turnR(data);
      delay(50);
      break;  
          
      case 'e':
      
      turnR(data);
      delay(50);
      break;

      case 'f':
      
      turnR(data);
      delay(50);
      break;
      
      case 'g':
      
      goF(data);
      delay(50);
      break; 

      case 'h':
      
      goF(data);
      delay(50);
      break; 

      case 'i':
      
      goF(data);
      delay(50);
      break;

      case 'j':
      
      backF(data);
      delay(50);
      break; 

      case 'k':
      
      backF(data);
      delay(50);
      break;

      case 'l':
      
      backF(data);
      delay(50);
      break; 

      case 'x':
      
      stopF();
      delay(50);
      break; 
      }
    
    }

  }

void loop() 
{
float duration, distance, duration1, distance1;
 digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  duration = pulseIn(echoPin, HIGH); 
distance = ((float)(340 * duration) / 10000) / 2;  
//distance = 20;
digitalWrite(trigPin1, HIGH);
  delay(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH); 
distance1 = ((float)(340 * duration1) / 10000) / 2;
//distance1=40;
//while(distance>0){

 if((distance<40)||(distance1<40))
  {
  digitalWrite(IN1, LOW);//일정힘 이하면 브레이크 활성화
  digitalWrite(IN2, LOW);//일정힘 이하면 브레이크 활성화
  digitalWrite(IN3, LOW);//일정힘 이하면 브레이크 활성화
  digitalWrite(IN4, LOW);//일정힘 이하면 브레이크 활성화
   analogWrite(ENA, 0);
   analogWrite(ENB, 0);
   delay(100);
  }
  else {
  if(bluetooth.available()){

  if((distance>=15&&distance<=50)&&distance1>50)
  {
    bluetooth.write('a');
    delay(100);
    }
  if((distance1>=15&&distance1<=50)&&distance>50)
  {
    bluetooth.write('b');
    delay(100);
    }
  if((distance1>=15&&distance1<=50)&&(distance>=15&&distance<=50))
  {
    bluetooth.write('c');
    delay(100);
    }
  }

getSignal();

  }   //else
//}//while
delay(50);
}
