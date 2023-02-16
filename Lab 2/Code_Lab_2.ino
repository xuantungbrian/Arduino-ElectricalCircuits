#include <LiquidCrystal.h>

double pot1_speed;
int speed, val=2;
double V, R2, half_V, med;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int checkPush(int val);
void setup()
{
  analogWrite(9 ,40 );
  lcd.begin(16, 2); 
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT); 
  pinMode(7, INPUT);
  pinMode(13, INPUT);
}

void loop()
{
  pot1_speed = analogRead(A0);
  speed = (int) (pot1_speed/1023*255);

  if (digitalRead(7)==0 && digitalRead(13)==0) {    
    val=2;
  }
  else if (digitalRead(7)==0) {
    val=0;
  }
  else if (digitalRead(13)==0) {
    val=1;
  }
  

  if (val==0) {
    analogWrite(6, 0);
    analogWrite(10, speed);
  }
  else if (val==1) {
    analogWrite(6, speed);
    analogWrite(10, 0);
  }
  else if (val==2) {
    analogWrite(6, 0);
    analogWrite(10, 0);
  }
  
  med = analogRead(A1);
  half_V = med/1023*5;
  V = half_V*2;
  R2 = (V - 1.25)*200/1.25;
  if (R2<0) {R2=0;}
  
  
  lcd.setCursor(0, 0);
  lcd.print("V = ");
  lcd.print(V);
  lcd.print(" v");
  lcd.setCursor(0, 1);
  lcd.print("R2 = ");
  lcd.print(R2);
  lcd.print(" ohms"); 
  delay(200);
  lcd.clear();
}

/*int checkPush(int val) {
  int i;
  if (digitalRead(val) == 0) {
    while (i != 1) {
      if (digitalRead(val) == 1) {
        i = 1;
      }
    }
    return 0;
  }
  return 1;
}*/
