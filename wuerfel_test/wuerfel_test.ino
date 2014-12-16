#include <Entropy.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>

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
  pinMode(emptyPin, INPUT_PULLUP);
	
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
    
    for(byte i=1; i<7; i++) {
    
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      
      do {
      
        randNum=Entropy.random(0,6);
        
      } while(randNum == prevNum);
    
      disp(randNum);
      
      prevNum = randNum;
      delay(i*50);
    }
  }
  sleepNow();
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
void sleepNow(void) {
  attachInterrupt(swPin, pinInterrupt, LOW);
  delay(100);

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);

  sleep_enable();

  sleep_mode();

  sleep_disable();
}

void pinInterrupt(void) {
  detachInterrupt(swPin);
}
