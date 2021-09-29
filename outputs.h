#include "globals.h"
//Game melodies should be asynchronous but idk how to do it :)
void generateSound(int frecuency, int duration = MINIMAL_DURATION);
void playSequence(int arraySequence[], int endPosition);
void playColor(int colorPin);
void playStartMelody();
void playGameOverMelody();
void playWinMelody();
void playColorSound(int colorPin);
