#include <LiquidCrystal.h>
int trigPin = 7;
int echoPin = 8;
int pingTravelTime;
int sec = 0;

//Pines de pantalla led
int rs = 12;
int e = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  //Lectura de onda sonora
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  pingTravelTime = pulseIn(echoPin,HIGH);
  
  //Escritura en pantalla
  
  Serial.println(pingTravelTime);
  for(int i = 5; i>=1; i--){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("T: "+String(pingTravelTime)+"us");
    lcd.setCursor(0,1);
    lcd.print(i);
    delay(200);
    digitalWrite(13,1);
    delay(300); 
    digitalWrite(13,0);
  }

  delay(2);
}
