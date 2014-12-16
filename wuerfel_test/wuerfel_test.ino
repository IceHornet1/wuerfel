/********************************************************************
*
*   Wuerfel V1.0
*   Florian Ulmschneider
*   16.12.2014
*
********************************************************************/


#include <Entropy.h>
#include <avr/power.h>

const byte led1 = 0;
const byte led2 = 3;
const byte led3 = 4;
const byte led4 = 1;
const byte swPin = 2;
const byte emptyPin = 5;
byte randNum;
byte prevNum;

void setup() {
  Entropy.initialize();
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(swPin, INPUT_PULLUP);
  pinMode(emptyPin, INPUT);
	
  power_adc_disable();
  power_usi_disable();
  
  for(byte i=0; i<50; i++) {
    digitalWrite(led1, HIGH);
    delay(1);
    digitalWrite(led1, LOW);
    
    digitalWrite(led2, HIGH);
    delay(1);
    digitalWrite(led2, LOW);
    
    digitalWrite(led3, HIGH);
    delay(1);
    digitalWrite(led3, LOW);
    
    digitalWrite(led4, HIGH);
    delay(1);
    digitalWrite(led4, LOW);
  }
}

void loop() {
  if (digitalRead(swPin) == LOW) {
    do {
      do {
      
        randNum=random(0,6);
        
      } while(randNum == prevNum);
    
      disp(randNum);
      
      prevNum = randNum;
      delay(100);
      
    } while(digitalRead(swPin) == LOW);
    
    for(byte i=1; i<6; i++) {
      
      do {
      
        randNum=Entropy.random(0,6);
        
      } while(randNum == prevNum);
    
      disp(randNum);
      
      prevNum = randNum;
      delay((i*50)+100);
    }
  }
}

void disp(byte x) {
  switch(x) { 
    case 0:
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
    break;
    
    case 1:
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
    break;
    
    case 2:
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
    break;
    
    case 3:
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
    break;
    
    case 4:
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
    break;
    
    case 5:
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
    break;
  }
}