
#include "getters.h"
#include "outputs.h"

int selectGamemode() {
  digitalWrite(redColor, HIGH);
  digitalWrite(greenColor, HIGH);
  digitalWrite(yellowColor, HIGH);
  playStartMelody();
  while (digitalRead(redColorButton) == LOW && digitalRead(greenColorButton) == LOW && digitalRead(yellowColorButton) == LOW) {
    delay(10);
  }
  digitalWrite(redColor, LOW);
  digitalWrite(greenColor, LOW);
  digitalWrite(yellowColor, LOW);
  Serial.println("GAMEMODE SELECTED");
  if (digitalRead(greenColorButton) == HIGH) {
    playColorSound(greenColor);
    return 1;
  }
  else if (digitalRead(yellowColorButton) == HIGH) {
    playColorSound(yellowColor);
    return 2;
  }
  else if (digitalRead(redColorButton) == HIGH) {
    playColorSound(redColor);
    return 3;
  }
  else
    return 0;
}


int selectLevel() {
  digitalWrite(redColor, HIGH);
  digitalWrite(greenColor, HIGH);
  digitalWrite(yellowColor, HIGH);
  digitalWrite(blueColor, HIGH);
  while (digitalRead(greenColorButton) == LOW && digitalRead(yellowColorButton) == LOW && digitalRead(redColorButton) == LOW && digitalRead(blueColorButton) == LOW) {
    delay(10);
  }
  digitalWrite(redColor, LOW);
  digitalWrite(greenColor, LOW);
  digitalWrite(yellowColor, LOW);
  digitalWrite(blueColor, LOW);
  Serial.println("LEVEL SELECTED");
  if (digitalRead(greenColorButton) == HIGH) {
    playColorSound(greenColor);
    return 1;
  }
  else if (digitalRead(yellowColorButton) == HIGH) {
    playColorSound(yellowColor);
    return 2;
  }
  else if (digitalRead(redColorButton) == HIGH) {
    playColorSound(redColor);
    return 3;
  }
  else if (digitalRead(blueColorButton) == HIGH) {
    playColorSound(blueColor);
    return 4;
  }
  else
    return 0;
}

int selectColor() {
  while (digitalRead(redColorButton) == LOW && digitalRead(greenColorButton) == LOW && digitalRead(blueColorButton) == LOW && digitalRead(yellowColorButton) == LOW) {
    delay(10);
  }
  if (digitalRead(greenColorButton) == HIGH) {
    return greenColor;
  }
  else if (digitalRead(yellowColorButton) == HIGH) {
    return yellowColor;
  }
  else if (digitalRead(redColorButton) == HIGH) {
    return redColor;
  }
  else if (digitalRead(blueColorButton) == HIGH) {
    return blueColor;
  }
  else
    return 0;
}

void gameOver() {
  Serial.println("GAME OVER");
  digitalWrite(greenColor, LOW);
  digitalWrite(yellowColor, LOW);
  digitalWrite(redColor, LOW);
  digitalWrite(blueColor, LOW);
  playGameOverMelody();
}

void gameWin() {
  Serial.println("GAME WIN");
  playWinMelody();
  for (int i = 0; i < 10; i++) {
    digitalWrite(greenColor, HIGH);
    digitalWrite(yellowColor, HIGH);
    digitalWrite(redColor, HIGH);
    digitalWrite(blueColor, HIGH);
    delay(1000);
    digitalWrite(greenColor, LOW);
    digitalWrite(yellowColor, LOW);
    digitalWrite(redColor, LOW);
    digitalWrite(blueColor, LOW);
    delay(500);
  }
}

void game1(int level) {
  int arraySize = getArraySize(level);
  int machineArray[arraySize];
  int userArray[arraySize];
  bool endGame = false;
  for (int i = 0; i < arraySize && !endGame; i++) {
    machineArray[i] = getRandomColor();
    playSequence(machineArray, i);
    for (int j = 0; j <= i && !endGame; j++) {
      userArray[j] = selectColor();
      //userArray[j] = machineArray[j];
      playColor(userArray[j]);
      if (userArray[j] != machineArray[j]){
        playErrorMelody();
        endGame = true;
      }  
    }
    delay(300);
  }
  if (endGame) //If the user loses
    gameOver();
  else //If the user wins
    gameWin();
}


void game2(int level) {
  int arraySize = getArraySize(level);
  int machineArray[arraySize];
  int userArray[arraySize];
  bool endGame = false;
  for (int i = 0; i < arraySize && !endGame; i++) {
    if (i == 0)
      machineArray[i] = getRandomColor();
    else {
      machineArray[i] = selectColor();
      playColor(machineArray[i]);
    }
    playSequence(machineArray, i);
    for (int j = 0; j <= i && !endGame; j++) {
      userArray[j] = selectColor();
      playColor(userArray[j]);
      if (userArray[j] != machineArray[j]){
        playErrorMelody();
        endGame = true;
      }  
    }
    delay(300);
  }
  if (endGame) //If the user loses
    gameOver();
  else //If the user wins
    gameWin();
}


void game3(int level) {
  int arraySize = getArraySize(level);
  int machineArray[arraySize];
  int userArray[arraySize];
  int lives = 3;
  int availableColors[4] = {redColor, greenColor, blueColor, yellowColor};
  for (int i = 0; i < arraySize && lives != 0; i++) {
    machineArray[i] = getRandomColorAvailable(availableColors);
    playSequence(machineArray, i);
    for (int j = 0; j <= i && lives != 0; j++) {
      userArray[j] = selectColor();
      playColor(userArray[j]);
      if (userArray[j] != machineArray[j]) {
        //Remove color from color list
        //Should disable the color but idk how to do it
        for (int z = 0; z < 4; z++) {
          if (userArray[j] == availableColors[z])
            availableColors[z] = 999;
        }
        lives--;
        playErrorMelody();
        i = -1;
      }
    }
    delay(300);
  }

  playWinMelody();
  for (int j = 0; j < 8; j++)
  {
    if (availableColors[0] != 999) {
      digitalWrite(availableColors[0], HIGH);
    }
    if (availableColors[1] != 999) {
      digitalWrite(availableColors[1], HIGH);
    }
    if (availableColors[2] != 999) {
      digitalWrite(availableColors[2], HIGH);
    }
    if (availableColors[3] != 999) {
      digitalWrite(availableColors[3], HIGH);
    }
    delay(1000);
    digitalWrite(availableColors[0], LOW);
    digitalWrite(availableColors[1], LOW);
    digitalWrite(availableColors[2], LOW);
    digitalWrite(availableColors[3], LOW);
    delay(1000);
  }
}

void startGame(int gameMode, int level) {
  switch (gameMode) {
    case 1:
      game1(level);
      break;
    case 2:
      game2(level);
      break;
    case 3:
      game3(level);
      break;
  }
}
