/*CODIGO ESCRITO POR: ADRIAN LARA
EMAIL: kamikazelara@gmail.com
*******************************************************************************/

#include <LiquidCrystal_I2C.h> 
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int inches = 0;
int ENPin = 5;
int val = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT); //ENA
  pinMode(5, OUTPUT); //IN1
  pinMode(6, OUTPUT); //IN2
  pinMode(10, OUTPUT); //IN3
  pinMode(11, OUTPUT); //IN4
  pinMode(12, OUTPUT); //ENB
  
  lcd.init();
  lcd.setBacklight(HIGH);
 
}

void loop()
{

  double inputValue = analogRead(A0);
  double a = inputValue/1023*255;
  int convertedValue = map(inputValue,0,1023,0,255);
  analogWrite(ENPin, 0);

  lcd.setCursor(0,0);
  lcd.print("Vel.Impresion ");
  lcd.setCursor(1,1);
  lcd.print("Valor : ");
  lcd.print(a);  
  
  {
        digitalWrite(4, HIGH);//ENA
        digitalWrite(5, LOW);//IN1
        analogWrite(6, a);//IN2
        digitalWrite(10, HIGH);//IN3
        digitalWrite(11, LOW);//IN4
        analogWrite(12, a);//ENB
        Serial.println("on");
  }
  
}
