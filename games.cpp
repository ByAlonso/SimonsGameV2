
#include "getters.h"
#include "outputs.h"

int selectGamemode(){
 while(digitalRead(redColorButton) == LOW && digitalRead(greenColorButton) == LOW && digitalRead(yellowColorButton) == LOW){
  delay(10);
 }
 Serial.println("GAMEMODE SELECTED");
 //generateSound(44,4);
 if(digitalRead(greenColorButton) == HIGH)
  return 1;
 else if(digitalRead(yellowColorButton) == HIGH)
  return 2;
 else if(digitalRead(redColorButton) == HIGH)
  return 3;
 else
  return 0;
}


int selectLevel(){

 while(digitalRead(greenColorButton) == LOW && digitalRead(yellowColorButton) == LOW && digitalRead(redColorButton) == LOW && digitalRead(blueColorButton) == LOW){
  delay(10);
  }
 Serial.println("LEVEL SELECTED");
 generateSound(44,4);
 if(digitalRead(greenColorButton) == HIGH)
  return 1;
 else if(digitalRead(yellowColorButton) == HIGH)
  return 2;
 else if(digitalRead(redColorButton) == HIGH)
  return 3;
 else if(digitalRead(blueColorButton) == HIGH)
  return 4;
 else
  return 0;
}

int selectColor(){
 while(digitalRead(redColorButton) == LOW && digitalRead(greenColorButton) == LOW && digitalRead(blueColorButton) == LOW && digitalRead(yellowColorButton) == LOW){
  delay(10);
 }
 generateSound(44,4);
 if(digitalRead(redColorButton) == HIGH)
  return redColor;
 else if(digitalRead(greenColorButton) == HIGH)
  return greenColor;
 else if(digitalRead(blueColorButton) == HIGH)
  return blueColor;
 else if(digitalRead(yellowColorButton) == HIGH)
  return yellowColor;
 else
  return 0;
}

void gameOver(){
  Serial.println("GAME OVER");
}

void gameWin(){
  Serial.println("GAME WIN");
}

void game1(int level){
  int arraySize = getArraySize(level);
  int machineArray[arraySize];
  int userArray[arraySize];
  bool endGame = false;
  for(int i = 0; i < arraySize && !endGame; i++){
    machineArray[i] = getRandomColor();
    playSequence(machineArray,i);
    for(int j = 0; j <= i && !endGame; j++){
      userArray[j] = selectColor();
      //userArray[j] = machineArray[j];
      playColor(userArray[j]);
      if(userArray[j] != machineArray[j])
        endGame = true;
    }
  }
  if(endGame) //If the user loses
    gameOver();
  else //If the user wins
    gameWin();
}


void game2(int level){
  int arraySize = getArraySize(level);
  int machineArray[arraySize];
  int userArray[arraySize];
  bool endGame = false;
  for(int i = 0; i < arraySize && !endGame; i++){
    if(i == 0)
      machineArray[i] = getRandomColor();
    else{
      machineArray[i] = selectColor();
      playColor(userArray[i]);
    }
    playSequence(machineArray,i);
    for(int j = 0; j <= i && !endGame; j++){
      userArray[j] = selectColor();
      playColor(userArray[j]);
      if(userArray[j] != machineArray[j])
        endGame = true;
    }
  }
  if(endGame) //If the user loses
    gameOver();
  else //If the user wins
    gameWin();
}


void game3(int level){
  int arraySize = getArraySize(level);
  int machineArray[arraySize];
  int userArray[arraySize];
  int lives = 3;
  int availableColors[4] = {redColor,greenColor,blueColor,yellowColor};
  for(int i = 0; i < arraySize && lives != 0; i++){
    machineArray[i] = getRandomColorAvailable(availableColors);
    playSequence(machineArray,i);
    for(int j = 0; j <= i && lives != 0; j++){
      userArray[j] = selectColor();
      playColor(userArray[j]);
      if(userArray[j] != machineArray[j]){
        //Borrar un color de la lista de colores
        for(int z = 0; z < 4; z++){
          if(userArray[j] == availableColors[z])
            availableColors[z] = 999;
        }
        lives--;
        i = 0;
      }
    }
  }
  //COLOR WINNER FOR THIS GAME
  for(int i = 0; i < 4; i++){
    if(availableColors[i] != 0){
      digitalWrite(availableColors[i],HIGH);
    }
  } 
}

void startGame(int gameMode, int level){
  switch(gameMode){
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
