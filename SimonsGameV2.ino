#include "globals.h"
#include "games.h"
#include "outputs.h"
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"


void handleGame() {

  int gameMode = selectGamemode();
  delay(1000);
  int level = selectLevel();
  delay(1000);
  if (gameMode != 0 && level != 0)
    startGame(gameMode, level);
  delay(5000);
  resetAll();
}

void resetAll() {
  counter = 0;
  ThingSpeak.setField(1, counter);
  ThingSpeak.setField(2, counter);
  ThingSpeak.writeFields(SECRET_ID, SECRET_API_WRITE);
  digitalWrite(redColor, LOW);
  digitalWrite(greenColor, LOW);
  digitalWrite(blueColor, LOW);
  digitalWrite(yellowColor, LOW);

}

void setup() {
  // put your setup code here, to run once:
  int i = 0;
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
  Serial.print("Attempting to connect to SSID: ");
  Serial.println(SECRET_SSID);
  //It has 10 secs to conect
  WiFi.begin(SECRET_SSID, SECRET_PSW);
    while (WiFi.status() != WL_CONNECTED && i < 20) {
      Serial.print(".");
      delay(500);
      i++;
    }
  ThingSpeak.begin(client);
}

void loop() {
  
  handleGame();

}
