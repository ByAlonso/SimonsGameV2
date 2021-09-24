#include "globals.h"

int getRandomColor(){
  return possibleColors[random(0,4)];
}

int getRandomColorAvailable(int availableColors[]){
  int randomColor = 999;
  while(randomColor == 999){
    randomColor = availableColors[random(0,4)];
  }
  return randomColor;
}


int getArraySize(int level){
  switch(level){
    case 1:
      return LEVEL1;
    case 2:
      return LEVEL2;
    case 3:
      return LEVEL3;
    case 4:
      return LEVEL4;
    default:
      return 0;
  }
}
