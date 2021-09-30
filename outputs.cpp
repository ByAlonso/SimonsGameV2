#include "globals.h"

void generateSound(int melody[], int notes) {
  int tempo = 144;
  // this calculates the duration of a whole note in ms (60s/tempo)*4 beats
  int wholenote = (60000 * 4) / tempo;

  int divider = 0, noteDuration = 0;


  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}
void playColorSound(int colorPin) {
  if (colorPin == greenColor) {
    int melody[] = {NOTE_E5, 6};
    generateSound(melody, sizeof(melody) / sizeof(melody[0]) / 2);
  }
  if (colorPin == yellowColor) {
    int melody[] = {NOTE_B4, 6};
    generateSound(melody, sizeof(melody) / sizeof(melody[0]) / 2);
  }
  if (colorPin == redColor) {
    int melody[] = {NOTE_C5, 6};
    generateSound(melody, sizeof(melody) / sizeof(melody[0]) / 2);
  }
  if (colorPin == blueColor) {
    int melody[] = {NOTE_D5, 6};
    generateSound(melody, sizeof(melody) / sizeof(melody[0]) / 2);
  }

}

void playColor(int colorPin) {
  digitalWrite(colorPin, HIGH);
  playColorSound(colorPin);
  delay(500);
  digitalWrite(colorPin, LOW);
  delay(500);
}

void playSequence(int arraySequence[], int endPosition) {
  for (int i = 0; i <= endPosition; i++) {
    playColor(arraySequence[i]);
  }
}

void playStartMelody() {
  int melody[] = {
    NOTE_E7, 12, NOTE_E7, 12, 0, 12, NOTE_E7, 12,
    0, 12, NOTE_C7, 12, NOTE_E7, 12, 0, 12,
    NOTE_G7, 12, 0, 12, 0, 12,  0, 12,
    NOTE_G6, 12, 0, 12, 0, 12, 0, 12
  };

  generateSound(melody, sizeof(melody) / sizeof(melody[0]) / 2);

}

void playGameOverMelody() {
  int melody[] = {
    NOTE_DS4, 18, NOTE_CS4, 18, NOTE_D4, 18,
    NOTE_CS4, 6, NOTE_DS4, 6,
    NOTE_DS4, 6, NOTE_GS3, 6,
    NOTE_G3, 6, NOTE_CS4, 6,
    NOTE_C4, 18, NOTE_FS4, 18, NOTE_F4, 18, NOTE_E3, 18, NOTE_AS4, 18, NOTE_A4, 18,
    NOTE_GS4, 10, NOTE_DS4, 10, NOTE_B3, 10,
    NOTE_AS3, 10, NOTE_A3, 10, NOTE_GS3, 10,
    0, 3, 0, 3, 0, 3
  };


  generateSound(melody, sizeof(melody) / sizeof(melody[0]) / 2);

}

void playWinMelody() {
  int melody[] = {
    NOTE_C5, 4,   NOTE_E5, 4,  NOTE_A5, 2,
    NOTE_GS5, 2
  };

  generateSound(melody, sizeof(melody) / sizeof(melody[0]) / 2);

}

void playErrorMelody() {
  int melody[] = {
    NOTE_D3,16, NOTE_D3,16, NOTE_D4,8, NOTE_A3,6
  };

  generateSound(melody, sizeof(melody) / sizeof(melody[0]) / 2);

}
