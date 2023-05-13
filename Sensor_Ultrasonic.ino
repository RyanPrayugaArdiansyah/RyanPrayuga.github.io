#include <LiquidCrystal_I2C.h>
#define trig 9
#define echo 10
LiquidCrystal_I2C lcd(0x27, 16, 2); 

int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;
int BUZZER = 8;
int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 1);
  lcd.print("  Ryan, Rizal, Farid, Qorib, Nada  ");
  for (i = 0; i < 18; i++)
  {
  lcd.scrollDisplayLeft();
  delay(300);
  }
  lcd.clear();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration*0.034/2;

  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Level Air ");   
  lcd.setCursor(0,1); 
  lcd.print(distance);
  lcd.print(" cm   ");
  delay(100);
  
  if ( distance <= 10 ){
    digitalWrite(LED1, HIGH);
  }else if (distance > 10){
    digitalWrite(LED1, LOW);
  }

   if ( distance <= 9 ){
    digitalWrite(LED2, HIGH);
  }else if ( distance > 9){
    digitalWrite(LED2, LOW);
  }

   if ( distance <= 8 ){
    digitalWrite(LED3, HIGH);
  }else if ( distance > 8 ){
    digitalWrite(LED3, LOW);
  }

  if ( distance <= 7 ){
    digitalWrite(LED4, HIGH);
  }else if ( distance > 7 ){
    digitalWrite(LED4, LOW);
  }

  if ( distance <= 6 ){
    digitalWrite(LED5, HIGH);
  }else if ( distance > 6 ){
    digitalWrite(LED5, LOW);
  }

  if ( distance <= 4 ){
    digitalWrite(LED6, HIGH);
  }else if ( distance > 4){
    digitalWrite(LED6, LOW);
  }  

  if ( distance <= 4 ){
    digitalWrite(BUZZER, HIGH);
  }else if ( distance > 4){
    digitalWrite(BUZZER, LOW);
  }  
}
 

