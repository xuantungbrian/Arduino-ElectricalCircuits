#include <LiquidCrystal.h>

double V0, R, med;
int brightness;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//void LCD_print(double R);

void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(10,OUTPUT);
  lcd.begin(16, 2);
  analogWrite(9,50);
}

void loop()
{
  med = analogRead(A0);
  V0 = med/1023*5;
  R = 5*10/V0-10;
  brightness = R/20*255;
  if (brightness>255) {brightness = 255;}
  if (R <= 0) {
    Serial.println("Something is wrong");
  }
  else if (R > 0 && R <= 1.1) {
    Serial.print("Resistance = ");
    Serial.print(R);
    Serial.println(" k ohm (Bright)");
  }
  else if (R > 1.1 && R <= 3) {
    Serial.print("Resistance = ");
    Serial.print(R);
    Serial.println(" k ohm (Normal)");
  }
  else {
    Serial.print("Resistance = ");
    Serial.print(R);
    Serial.println(" k ohm (Dark)"); 
  }

  analogWrite(10,brightness); 
  lcd.clear();
  lcd.print("R = ");
  lcd.print(R);
  lcd.print(" k ohm");
}

/*void LCD_print(double R) {
  double r = R;
  lcd.clear();
  char first[5] = "R = ";
  char last[7] = " k ohm";
  lcd.print(first);
  lcd.print(r);
  lcd.print(last);
}*/
