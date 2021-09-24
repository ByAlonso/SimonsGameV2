#include "globals.h"

void generateSound(int frecuency, int duration){
  tone(buzzer,frecuency,duration);
  noTone(buzzer);
}

void playColor(int colorPin){
  digitalWrite(colorPin,HIGH);
  delay(150);
  digitalWrite(colorPin,LOW);
  delay(50);
}

void playSequence(int arraySequence[], int endPosition){
  for(int i = 0; i <= endPosition; i++){
        playColor(arraySequence[i]);
    Serial.println(arraySequence[i]);
  }
  Serial.println("----------------");

}
