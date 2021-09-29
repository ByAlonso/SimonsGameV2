#include "globals.h"

void generateSound(int frecuency, int duration) {
  tone(buzzer, frecuency, duration);
  noTone(buzzer);
}
void playColorSound(int colorPin) {
  if (colorPin == greenColor) {
    generateSound(NOTE_E5, 6);
  }
  if (colorPin == yellowColor) {
    generateSound(NOTE_B4, 6);
  }
  if (colorPin == redColor) {
    generateSound(NOTE_C5, 6);
  }
  if (colorPin == blueColor) {
    generateSound(NOTE_D5, 6);
  }

}

void playColor(int colorPin) {
  playColorSound(colorPin);
  digitalWrite(colorPin, HIGH);
  delay(150);
  digitalWrite(colorPin, LOW);
  delay(50);
}

void playSequence(int arraySequence[], int endPosition) {
  for (int i = 0; i <= endPosition; i++) {
    playColor(arraySequence[i]);
    Serial.println(arraySequence[i]);
  }
  Serial.println("----------------");

}

void playStartMelody() {
  int melody[] = {
    NOTE_E7, NOTE_E7, 0, NOTE_E7,
    0, NOTE_C7, NOTE_E7, 0,
    NOTE_G7, 0, 0,  0,
    NOTE_G6, 0, 0, 0,
  };

  for (int i = 0; i < 16; i++) {
    generateSound(melody[i], 12);
  }

}

void playGameOverMelody() {
  int melody[] = {
    NOTE_DS4, NOTE_CS4, NOTE_D4,
    NOTE_CS4, NOTE_DS4,
    NOTE_DS4, NOTE_GS3,
    NOTE_G3, NOTE_CS4,
    NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
    NOTE_GS4, NOTE_DS4, NOTE_B3,
    NOTE_AS3, NOTE_A3, NOTE_GS3,
    0, 0, 0
  };
  int tempo[] = {
    18, 18, 18,
    6, 6,
    6, 6,
    6, 6,
    18, 18, 18, 18, 18, 18,
    10, 10, 10,
    10, 10, 10,
    3, 3, 3
  };

  for (int i = 0; i < 24; i++) {
    generateSound(melody[i], tempo[i]);
  }

}

void playWinMelody() {
  int melody[] = {
NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
  NOTE_GS5,2,
  };

  for (int i = 0; i < 8; i += 2) {
    generateSound(melody[i], melody[i + 1]);
  }

}
