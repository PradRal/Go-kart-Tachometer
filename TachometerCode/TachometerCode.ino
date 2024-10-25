#include <LiquidCrystal.h>
#define tachPin 2


unsigned long currentMillis;
int myDelay = 1000; 
int pulseCount; 
int RPM; 
unsigned long previousTime;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
lcd.begin(16, 2);
pinMode(tachPin, INPUT);
attachInterrupt(digitalPinToInterrupt(tachPin), tachcount, LOW);
previousTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
currentMillis = millis(); 

if (currentMillis - previousTime >= myDelay) {
 
  RPM = (pulseCount * 60) / (myDelay/1000); 

  Serial.println(RPM);
  lcd.setCursor(0,0);
  lcd.print("RPM: ");
  lcd.print(RPM);
  
  pulseCount = 0; 

  previousTime = currentMillis; 
}


}

void tachcount() {
pulseCount++; 
}
