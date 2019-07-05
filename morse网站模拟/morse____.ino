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
  Serial.begin(9600);}
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

  
