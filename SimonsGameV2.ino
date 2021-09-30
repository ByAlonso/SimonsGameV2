#include "globals.h"
#include "games.h"
#include "outputs.h"

void setup() {
  // put your setup code here, to run once:

  pinMode(redColor, OUTPUT);
  pinMode(greenColor, OUTPUT);
  pinMode(blueColor, OUTPUT);
  pinMode(yellowColor, OUTPUT);

  pinMode(redColorButton, INPUT);
  pinMode(greenColorButton, INPUT);
  pinMode(blueColorButton, INPUT);
  pinMode(yellowColorButton, INPUT);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void resetAll() {
  counter = 0;
  digitalWrite(redColor, LOW);
  digitalWrite(greenColor, LOW);
  digitalWrite(blueColor, LOW);
  digitalWrite(yellowColor, LOW);
}

void loop() {
  int gameMode = selectGamemode();
  delay(1000);
  int level = selectLevel();
  delay(1000);
  if (gameMode != 0 && level != 0)
    startGame(gameMode, level); 
  delay(5000);
  resetAll();
}
