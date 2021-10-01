 #include "globals.h"

int redColor = D3;
int greenColor = D1;
int blueColor = D4;
int yellowColor = D2;

int redColorButton = D7;
int greenColorButton = D5;
int blueColorButton = D8;
int yellowColorButton = D6;

int possibleColors[4] = {redColor, greenColor, blueColor, yellowColor};

int buzzer = D0;

int counter = 0;
int maxCounter = 0;

char* SECRET_SSID = "iPhone";
char* SECRET_PSW = "1234abcd";

long unsigned int SECRET_ID = 1523631;
char* SECRET_API_WRITE = "ZCA87LTOULPC5XGM";
char* SECRET_API_READ = "LWWZQ8HSMSYCZDAB";

WiFiClient  client;
