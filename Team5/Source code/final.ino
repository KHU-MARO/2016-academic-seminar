int Maindoor   = 4;   int Road1  = 20;   int Road17 = 37;
int Gong       = 5;   int Road2  = 21;   int Road18 = 38;
int Woo        = 6;   int Road3  = 22;   int Road19 = 39;
int Chadae     = 7;   int Road4  = 23;   int Road20 = 40;  
int Wahdae     = 8;   int Road5  = 24;   int Road21 = 41;  
int Multi      = 9;   int Road6  = 25;   int Road22 = 36;  
int Global     = 10;  int Road7  = 26;   int Road23 = 42;  
int Woman      = 11;  int Road8  = 27;   int Road24 = 43;  
int Man        = 12;  int Road9  = 28;   int Road25 = 44;  
int Doyae      = 13;  int Road10 = 29;   int motor1_A = 45;
int Sang       = 14;  int Road11 = 30;   int motor1_B = 46;
int Hawk       = 15;  int Road12 = 31;   int motor1_C = 2;
int Libr       = 16;  int Road13 = 32;   
int Yae        = 17;  int Road14 = 33;   
int Ja         = 18;  int Road15 = 34;  
int Gook       = 19;  int Road16 = 35;

void maindoor();        void bye_light();
void gong();            void setmotor1_go();
void woo();             
void chadae();          void setmotor1_stop();
void wahdae();          
void multi();           void setmotor1_back();
void global();         
void woman();
void man();
void doyae();
void sang();
void hawk();
void libr();
void yae();
void ja();
void gook();

void setup() 
{
    for(int i=2; i<60 ; i++)      pinMode(i,OUTPUT);
    Serial.begin(9600);
}

void loop() 
{
 
    char data = Serial.read();
    switch (data) 
    {
      case 'z':             // Button1
        digitalWrite(Maindoor,HIGH);  digitalWrite(Global,HIGH);   digitalWrite(Libr,HIGH);
        digitalWrite(Gong,HIGH);      digitalWrite(Woman,HIGH);    digitalWrite(Yae,HIGH);
        digitalWrite(Woo,HIGH);       digitalWrite(Man,HIGH);      digitalWrite(Ja,HIGH);
        digitalWrite(Chadae,HIGH);    digitalWrite(Doyae,HIGH);    digitalWrite(Gook,HIGH);
        digitalWrite(Wahdae,HIGH);    digitalWrite(Sang,HIGH);    
        digitalWrite(Multi,HIGH);     digitalWrite(Hawk,HIGH);   
        break;
     /*
      case '1':
        digitalWrite(Maindoor,HIGH);
        break;
      case '2':
        digitalWrite(Gong,HIGH); 
        break;
      case '3':
        digitalWrite(Woo,HIGH);
        break;
      case '4':
        digitalWrite(Chadae,HIGH);
        break;
      case '5':
        digitalWrite(Wahdae,HIGH);
        break;
      case '6':
        digitalWrite(Multi,HIGH);
        break;
      case '7':
        digitalWrite(Global,HIGH);
        break;
      case '8':
        digitalWrite(Woman,HIGH);
        break;
      case '9':
        digitalWrite(Man,HIGH);
        break;
      case '!':
        digitalWrite(Doyae,HIGH);
        break;
      case '@':
        digitalWrite(Sang,HIGH);
        break;
      case '#':
        digitalWrite(Hawk,HIGH);
        break;
      case '$':
        digitalWrite(Libr,HIGH);
        break;
      case '%':
        digitalWrite(Yae,HIGH);
        break;
      case '^':
        digitalWrite(Ja,HIGH);
        break;
      case '&':
        digitalWrite(Gook,HIGH);
        break;
     */ 
      case 'a':
        maindoor();     
        break;
      case 'b':
        gong();       
        break;
      case 'c':
        woo();     
        break;
      case 'd':
        chadae();        
        break;
      case 'e':
        wahdae();      
        break;
      case 'f':
        multi();  
        break;
      case 'g':
        global();      
        break;
      case 'h':
        woman();         
        break;
      case 'i':
        man(); 
        break;
      case 'j':
        doyae();       
        break;
      case 'k':
        sang();   
        break;
      case 'l':
        hawk();     
        break;
      case 'm':
        libr();      
        break;
      case 'n':
        yae();     
        break;       
      case 'o':
        ja();
        break;
      case 'p':
        gook();
        break;
      case '-':
        bye_light();
        break;
    }

}

void setMotor1_go()
{
  analogWrite (motor1_C, 180);
  digitalWrite(motor1_A, HIGH);
  digitalWrite(motor1_B, LOW);
}

void setMotor1_back()
{
  analogWrite (motor1_C, 180);
  digitalWrite(motor1_A, LOW);
  digitalWrite(motor1_B, HIGH);
}


void setMotor1_stop()
{
  analogWrite (motor1_C, 0);
  digitalWrite(motor1_A, HIGH);
  digitalWrite(motor1_B, HIGH);
}

void bye_light()
{
  for(int i=2; i< 60; i++)   digitalWrite(i,LOW);
}

void maindoor()
{
  delay(700);
  digitalWrite(Maindoor,HIGH);
  delay(12000);
  
  bye_light();
}

void gong()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road3,HIGH);
  digitalWrite(Road5,HIGH);
  delay(700);
  digitalWrite(Gong,HIGH);
  delay(12000);
  
  bye_light();  
}

void woo()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road4,HIGH);
  delay(700);     
  digitalWrite(Woo,HIGH);
  delay(12000);
  
  bye_light();
}

void chadae()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road2,HIGH);
  delay(700);     
  digitalWrite(Road10,HIGH);
  delay(700);
  digitalWrite(Chadae,HIGH);
  delay(12000);
  
  bye_light();
}
     
void wahdae()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road2,HIGH);
  delay(700);     
  digitalWrite(Wahdae,HIGH);
  delay(12000);
  
  bye_light();
} 
     
void multi()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road2,HIGH);
  delay(700);     
  digitalWrite(Road6,HIGH);
  delay(700); 
  digitalWrite(Road7,HIGH);
  delay(700); 
  digitalWrite(Multi,HIGH);
  delay(12000);
  
  bye_light();
}  
  
void global()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road2,HIGH);
  delay(700);     
  digitalWrite(Road6,HIGH);
  delay(700); 
  digitalWrite(Road7,HIGH);
  delay(700); 
  digitalWrite(Road8,HIGH);
  delay(700);   
  digitalWrite(Global,HIGH);
  delay(12000);
  
  bye_light();
} 
     
void woman()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road2,HIGH);
  delay(700);     
  digitalWrite(Road6,HIGH);
  delay(700); 
  digitalWrite(Road7,HIGH);
  delay(700); 
  digitalWrite(Road8,HIGH);
  delay(700);
  digitalWrite(Woman,HIGH);
  delay(12000);
  
  bye_light();
}  
  
void man()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road2,HIGH);
  delay(700);     
  digitalWrite(Road6,HIGH);
  delay(700); 
  digitalWrite(Road7,HIGH);
  delay(700); 
  digitalWrite(Road8,HIGH);
  delay(700);
  digitalWrite(Road9,HIGH);
  delay(700);   
  digitalWrite(Man,HIGH);
  delay(12000);
  
  bye_light();
} 
      
void doyae()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road2,HIGH);
  delay(700);
  /* 모터1*/ 
  setMotor1_go();
  delay(3000);
  setMotor1_stop();
  delay(700);
  
  digitalWrite(Road11,HIGH);
  delay(700);
  digitalWrite(Doyae,HIGH);
  delay(12000);
  
  bye_light();
  setMotor1_back();
  delay(3000);
  setMotor1_stop();
  
       
}  
       
void sang()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road2,HIGH);
  delay(700);
  
  /* 모터1 */
  setMotor1_go();
  delay(3000);
  setMotor1_stop();
  delay(700);  
  
  digitalWrite(Road12,HIGH);
  delay(700);
  digitalWrite(Sang,HIGH);
  delay(12000);

  bye_light();
  /**/
  setMotor1_back();
  delay(3000);
  setMotor1_stop();
  
 }  
  
void hawk()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road2,HIGH);
  delay(700);
  
  /* 모터2 */
  setMotor1_go();
  delay(8000);
  setMotor1_stop();
  delay(700);
  
  
  delay(700);
  digitalWrite(Road13,HIGH);
  delay(700);  
  digitalWrite(Road14,HIGH);
  delay(700);
  digitalWrite(Road15,HIGH);
  delay(700); 
  digitalWrite(Hawk,HIGH);
  delay(12000);

  bye_light();
  /**/setMotor1_back();
  delay(8000);
  setMotor1_stop();
}   
  
void libr()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road2,HIGH);
  delay(700);
  
  /* 모터2*/ 
  setMotor1_go();
  delay(8000);
  setMotor1_stop();
  delay(700);
  
  digitalWrite(Road18,HIGH);
  delay(700);
  digitalWrite(Road13,HIGH);
  digitalWrite(Road17,HIGH);
  delay(700);  
  digitalWrite(Road14,HIGH);
  digitalWrite(Road22,HIGH); 
  delay(700);
  digitalWrite(Road16,HIGH);
  delay(700); 
  digitalWrite(Libr,HIGH);
  delay(12000);
  
  bye_light();
  /* */setMotor1_back();
  delay(8000);
  setMotor1_stop();    
} 
    
void yae()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road2,HIGH);
  delay(700);
  
  delay(700);
  /* 모터2 */
  setMotor1_go();
  delay(8000);
  setMotor1_stop();
  delay(700);
  
  digitalWrite(Road20,HIGH); 
  delay(700);
  digitalWrite(Road19,HIGH);
  delay(700);  
  digitalWrite(Road21,HIGH);  
  delay(700);
  digitalWrite(Yae,HIGH);
  delay(12000);

  bye_light();
  /**/setMotor1_back();
  delay(8000);
  setMotor1_stop();
}   
      
void ja()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road2,HIGH);
  delay(700);
 
  /* 모터2 */
  setMotor1_go();
  delay(8000);
  setMotor1_stop();
  delay(700);

  digitalWrite(Road23,HIGH);
  delay(700);
  digitalWrite(Road25,HIGH);
   delay(700);  
  digitalWrite(Ja,HIGH);
  delay(12000);

  bye_light();
  /**/setMotor1_back();
  delay(8000);
  setMotor1_stop();

}       

void gook()
{
  delay(700);
  digitalWrite(Road1,HIGH);
  delay(700);
  digitalWrite(Road2,HIGH);
  delay(700);
 
  /* 모터2*/  
  setMotor1_go();
  delay(8000);
  setMotor1_stop();
  
  delay(700);
  digitalWrite(Road23,HIGH);
  delay(700);
  digitalWrite(Road24,HIGH);
   delay(700);  
  digitalWrite(Gook,HIGH);
  delay(12000);

  bye_light();
  setMotor1_back();
  delay(8000);
  setMotor1_stop();
  
}  




