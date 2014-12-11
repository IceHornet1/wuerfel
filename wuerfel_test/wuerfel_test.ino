#include <Entropy.h>

const byte led1 = 0;
const byte led2 = 3;
const byte led3 = 4;
const byte led4 = 1;
const byte swPin = 2;
//const int analogPin =0;
byte randNum;
byte prevNum;

void setup() {
  //Serial.begin(9600);
  Entropy.initialize();
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(swPin, INPUT_PULLUP);
  
  //randomSeed(analogRead(analogPin));
  
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
    
    for(byte i=1; i<7; i++) {
      
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      
      do {
        randNum=Entropy.random(0,6);
        //Serial.print(randNum);
      } while(randNum == prevNum);
      //Serial.println(randNum);
    
      disp(randNum);
      
      prevNum = randNum;
      delay(i*50);
    }
  }
}

void disp(byte x) {
  switch(x) { 
        case 0:
          digitalWrite(led4, HIGH);
        break;
        
        case 1:
          digitalWrite(led3, HIGH);
        break;
        
        case 2:
          digitalWrite(led3, HIGH);
          digitalWrite(led4, HIGH);
        break;
        
        case 3:
          digitalWrite(led1, HIGH);
          digitalWrite(led3, HIGH);
        break;
        
        case 4:
          digitalWrite(led1, HIGH);
          digitalWrite(led3, HIGH);
          digitalWrite(led4, HIGH);
        break;
        
        case 5:
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, HIGH);
        break;
      }
}
