#include <LiquidCrystal.h>


LiquidCrystal lcd_1(13, 12, 5, 4, 3, 2);

void setup()
{
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  lcd_1.begin(16, 2); 
  lcd_1.print("A/C is working");
}

void loop()
{
  float pot = analogRead(A1);
  float pot1 = map(pot, 0 , 1023, 0, 255);
  float spid = map(pot, 0, 1023, 0, 10);
  analogWrite(10, pot1);
  analogWrite(11, pot1);
  
  float temp = analogRead(A0)* 5 / 1024.0;                    
  temp = temp - 0.5;                   
  temp = temp * 100;
  
  delay(2000);
  
  if(temp<=20){
    if(temp<= 0){
  	  digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      
      
      lcd_1.clear();
      lcd_1.print("temperature-");
      lcd_1.setCursor(0,1);
      lcd_1.print(temp);
      delay(2000);
      
      lcd_1.clear();
      lcd_1.print("both motors");
      lcd_1.setCursor(0,1);
      lcd_1.print("are spinning");
      delay(2000);
      
      lcd_1.clear();
      lcd_1.print("at speed");
      lcd_1.setCursor(0,1);
      lcd_1.print(spid);
      delay(2000);
    }
    else{
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      
      
      lcd_1.clear();
      lcd_1.print("temperature-");
      lcd_1.setCursor(0,1);
      lcd_1.print(temp);
      delay(2000);
      
      lcd_1.clear();
      lcd_1.print("one motor");
      lcd_1.setCursor(0,1);
      lcd_1.print("is spinning");
      delay(2000);
      
      lcd_1.clear();
      lcd_1.print("at speed");
      lcd_1.setCursor(0,1);
      lcd_1.print(spid);
      delay(2000);
    }
  }
  else{
    if(temp>=40){
  	  digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      
      
      lcd_1.clear();
      lcd_1.print("temperature-");
      lcd_1.setCursor(0,1);
      lcd_1.print(temp);
      delay(2000);
      
      lcd_1.clear();
      lcd_1.print("both motors");
      lcd_1.setCursor(0,1);
      lcd_1.print("are spinning");
      delay(2000);
      
      lcd_1.clear();
      lcd_1.print("at speed");
      lcd_1.setCursor(0,1);
      lcd_1.print(spid);
      delay(2000);
    }
    else{
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      
      
      lcd_1.clear();
      lcd_1.print("temperature-");
      lcd_1.setCursor(0,1);
      lcd_1.print(temp);
      delay(2000);
      
      lcd_1.clear();
      lcd_1.print("one motor");
      lcd_1.setCursor(0,1);
      lcd_1.print("is spinning");
      delay(2000);
      
      lcd_1.clear();
      lcd_1.print("at speed");
      lcd_1.setCursor(0,1);
      lcd_1.print(spid);
      delay(2000);
    }
  }
  
  
  
}
