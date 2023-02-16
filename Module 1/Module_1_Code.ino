#include <LiquidCrystal.h>
#include <math.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float T, R, V0, v2, v1, med, v9;

void setup() {
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  analogWrite(6, 75);
  /*pinMode(9, OUTPUT);
  analogWrite(9, 45);*/
}

void loop() {
  v9 = 5.09; //This is the place to change voltage value
  v1 = v9/(9793.0+984.0)*984.0; 
  med = analogRead(A0);
  V0 = med/1023.0*5.0;
  V0 = V0 + V0*0.0105;
  v2 = V0/(1.0+(5530.0+5534.0)/26708.0)+v1; // need check
  v2 = v2 + v2*0.01306;
  R = v2/((5-v2)/9969.0); 

  T = 1/(0.00112714+0.0002346*log(R)+(8.67e-08)*log(R)*log(R)*log(R)) - 273.0 ;

  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("T = ");
  lcd.print(T); 
  lcd.print("degrees ");
  lcd.setCursor(0, 1);
  lcd.print("Celcius ");

  Serial.print("v2 = ");
  Serial.println(v2, 4);
  Serial.print("V0 = ");
  Serial.println(V0, 4);
  Serial.print("T = ");
  Serial.println(T);
  
  delay(50);
 }
