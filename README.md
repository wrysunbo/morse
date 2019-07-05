#            西电开源硬件课程总结
## 课程内容
###  0702
·介绍课程：我们为什么要学,课程基本介绍

·介绍软件：arduino,fritzing,processing

·课后作业：创建github账号，安装arduino,fritzing,processing
### 0703
·课堂教学：arduino编程

·课后作业：morse代码，库函数
#### morse代码
#include <Morse.h>
Morse morse(13);

char MORSE[][4] = 

{
  {'.', '-', '*', '*'}, 
  
  {'-', '.', '.', '.'}, 
  
  {'-', '.', '-', '.'}, 
  
  {'-', '.', '.', '*'}, 
  
  {'.', '*', '*', '*'}, 
  
  {'.', '.', '-', '.'},
  
  {'-', '-', '.', '*'}, 
  
  {'.', '.', '.', '.'}, 
  
  {'.', '.', '*', '*'}, 
  
  {'.', '-', '-', '-'},
  
  {'-', '.', '-', '*'},
  
  {'.', '-', '.', '.'}, 
  
  {'-', '-', '*', '*'}, 
  
  {'-', '.', '*', '*'}, 
  
  {'-', '-', '-', '*'}, 
  
  
  {'.', '-', '-', '.'}, 
  
  {'-', '-', '.', '-'}, 
  
  {'.', '-', '.', '*'},
  
  {'.', '.', '.', '*'}, 
  
  {'-', '*', '*', '*'}, 
  
  {'.', '.', '-', '*'}, 
  
  {'.', '.', '.', '-'}, 
  
  {'.', '-', '-', '*'}, 
  
  {'-', '.', '.', '-'}, 
  
  {'-', '.', '-', '-'}, 
  
  {'-', '-', '.', '.'}  
  
};
void setup() {
Serial.begin(9600);
}

void loop() {
String str = "";  
  String morse_s = "";  
  int i, t , temp = 0;
  int n = 0;  
  while (Serial.available() > 0)
  {

temp = 1;  
    str += char(Serial.read());  
    delay(2);  
    n++;
  }

  if (temp)
  {
    
    for (i = 0; i < n; i++)
    {
      for (t = 0; t < 4; t++)
      {
     
        if (str[i] >= 97 && str[i] <= 122)
        {
          morse_s += char(MORSE[int(str[i] - 97)][t]);
        }
      }
     
      morse_s += ' ';
    }
     Serial.println(morse_s);  
    for (i = 0; morse_s[i]!='\0' ; i++)
    {
      if (morse_s[i] == '.')  morse.dot();
      else if (morse_s[i] == '-')morse.dash();
      else if (morse_s[i] == ' ')morse.w_space();
      if (morse_s[i] != ' ' && str[i] != '*')morse.c_space();
    }
    Serial.println("发送完毕");
    delay(2);
  }
}
#### 库函数
#include "Arduino.h"

#include "Morse.h"

Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
  
	_pin=pin;
  
	_dottime=250;
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
  
	delay(_dottime);
  
	digitalWrite(_pin,LOW);
  
	delay(_dottime);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
  
	delay(_dottime*4);
  
	digitalWrite(_pin,LOW);
  
	delay(_dottime);
}

void Morse::c_space()
{
	digitalWrite(_pin,LOW);
  
	delay(_dottime*3);
}

void Morse::w_space()
{
	digitalWrite(_pin,LOW);
  
	delay(_dottime*7);
}
#ifndef _MORSE_H

#define _MORSE_H

class Morse
{
  public:
  
    Morse(int pin);
    
    void dot();
    
    void dash();
    
    void c_space();
    
    void w_space();
    
  private:
  
    int _pin;
    
    int _dottime;
};

#endif /*_MORSE_H*/

### 0704

·课堂学习：电子元器件的认识和简单操作

·课后作业：小车代码和电路图，数码管代码和电路图

#### 小车

void setup()

{

  pinMode(5, OUTPUT);

  pinMode(6, OUTPUT);

  pinMode(9, OUTPUT);

  pinMode(10, OUTPUT);

  Serial.begin(9600);

}

int income=0;

void loop()

{

  if(Serial.available()>0)

    {

      income=Serial.read();

        switch(income)

        {

          case 'f':

              forward();

              break;

            case 'b':

              backward();

              break;

            case 'l':

              left();

              break;

            case 'r':

              right();

              break;

            case 's':

              stop();

              break;

            default:

              break;

        }

    }

}



void forward()

{

  digitalWrite(5,HIGH);

  digitalWrite(6,LOW);

  digitalWrite(9,HIGH);

  digitalWrite(10,LOW);

}



void backward()

{

  digitalWrite(6,HIGH);

  digitalWrite(5,LOW);

  digitalWrite(10,HIGH);

  digitalWrite(9,LOW);

}



void left()

{

  digitalWrite(5,HIGH);

  digitalWrite(6,LOW);

  digitalWrite(10,HIGH);

  digitalWrite(9,LOW);

}



void right()

{

  digitalWrite(6,HIGH);

  digitalWrite(5,LOW);

  digitalWrite(9,HIGH);

  digitalWrite(10,LOW);

}



void stop()

{

  digitalWrite(5,LOW);

  digitalWrite(6,LOW);

  digitalWrite(9,LOW);

  digitalWrite(10,LOW);

}

#### 数码管
void setup()
{
   pinMode(5, OUTPUT);
   
  pinMode(6, OUTPUT);
  
  pinMode(7, OUTPUT);
  
   pinMode(8, OUTPUT);
   
   pinMode(9, OUTPUT);
   
  Serial.begin(9600);
  
}

void loop()
{
  digitalWrite(5, LOW);
  
   digitalWrite(6, LOW);
   
  digitalWrite(7, LOW);
  
   digitalWrite(8, LOW);
   
   digitalWrite(9, LOW);
  int income;
  if(Serial.available()>0)
  {
    income=Serial.read()-'0';
    
    if((income&1)==1)
    
      digitalWrite(5, HIGH);
    
   if((income>>1&1)==1)
   
      digitalWrite(6, HIGH);
      
    if((income>>2&1)==1)
    
      digitalWrite(7, HIGH);
      
    if((income>>3&1)==1)
    
      digitalWrite(8, HIGH);
      
    if((income>>4&1)==1)
    
      digitalWrite(9, HIGH);
      
    delay(2000);
  
}
}
### 0705
·课程总结

·课后作业morse linkercad 代码
int pin=13;
char MORSE[][4] = {
  {'.', '-', '*', '*'}, 
  
  {'-', '.', '.', '.'}, 
  
  {'-', '.', '-', '.'}, 
  
  {'-', '.', '.', '*'}, 
  
  {'.', '*', '*', '*'}, 
  
  {'.', '.', '-', '.'}, 
  
  {'-', '-', '.', '*'}, 
  
  {'.', '.', '.', '.'}, 
  
  {'.', '.', '*', '*'}, 
  
  {'.', '-', '-', '-'}, 
  
  {'-', '.', '-', '*'}, 
  
  {'.', '-', '.', '.'}, 
  
  {'-', '-', '*', '*'},
  
  {'-', '.', '*', '*'}, 
  
  {'-', '-', '-', '*'}, 
  
  {'.', '-', '-', '.'}, 
  
  {'-', '-', '.', '-'}, 
  
  {'.', '-', '.', '*'}, 
  
  {'.', '.', '.', '*'}, 
  
  {'-', '*', '*', '*'}, 
  
  {'.', '.', '-', '*'}, 
  {'.', '.', '.', '-'}, 
  
  {'.', '-', '-', '*'}, 
  
  {'-', '.', '.', '-'}, 
  
  {'-', '.', '-', '-'}, 
  
  {'-', '-', '.', '.'}  
  
};
void setup()
{
  pinMode(pin,OUTPUT);
  
  Serial.begin(9600);
  }
  
  void loop()
{String str = ""; 

  String morse = "";  
  
  int i,t ,temp = 0;
  
  int n = 0;  
  
  while (Serial.available() > 0)
  {

temp = 1;  

    str += char(Serial.read()); 
    
    delay(2); 
    
    n++;
  }

  if (temp)
  {
    
    for (i = 0; i < n; i++)
    {
      for (t = 0; t < 4; t++)
      {
       
        if (str[i] >= 97 && str[i] <= 122)
        {
          morse += char(MORSE[int(str[i] - 97)][t]);
        }
      }
      
      morse += ' ';
    }
    Serial.println(morse);  
    for (i = 0; morse[i]!='\0' ; i++)
    {
      if (morse[i] == '.') dot();
      else if (morse[i] == '-') dash();
      else if (morse[i] == ' ') w_space();
      if (morse[i] != ' ' && str[i] != '*') c_space();
    }
    Serial.println("发送完毕");
    delay(2);
  }
}
int _dottime=250;

void dot()
{
  digitalWrite(pin,HIGH);
  
  delay(_dottime);
  
  digitalWrite(pin,LOW);
  
  delay(_dottime);
}

void dash()
{
  digitalWrite(pin,HIGH);
  
  delay(_dottime*4);
  
  digitalWrite(pin,LOW);
  
  delay(_dottime);
}

void c_space()
{
  digitalWrite(pin,LOW);
  
  delay(_dottime*3);
}

void w_space()
{
  digitalWrite(pin,LOW);
  
  delay(_dottime*7);
}

  ## 学习心得
  
  通过此次学习我学了 arduino linkercad markdown等软件的使用，对编程和电路知识进一步学习，非常充实，获益匪浅。
