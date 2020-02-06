/*
 * Lights for a 4 Way Intersection
 * 
 * Controls the stop lights (R/Y/G) for a 4 way intersection
 * 
 * Conditions:
 * Ensure that both directions are red for at least 1 second before changing one direction to Green
 * When one direction is Green, the other cannot be Green or Yellow
 * Yellow light must stay for 3 seconds
 * 
 */

// constants used to hold pin numbers
const int horizontalGreen = 13;
const int horizontalYellow = 12;
const int horizontalRed = 11;
const int verticalGreen = 8;
const int verticalYellow = 9;
const int verticalRed = 10;

// variable used to track direction of traffic
int trafficDirection = 0;         // 0 - Horizontal flow. 1 - Vertical flow

void setup() {
  // initialize digital pins as output
  pinMode(horizontalGreen, OUTPUT);
  pinMode(horizontalYellow, OUTPUT);
  pinMode(horizontalRed, OUTPUT);
  pinMode(verticalGreen, OUTPUT);
  pinMode(verticalYellow, OUTPUT);
  pinMode(verticalRed, OUTPUT);

  //initialize all directions to Red
  digitalWrite(horizontalGreen, LOW);
  digitalWrite(horizontalYellow, LOW);
  digitalWrite(horizontalRed, HIGH);
  digitalWrite(verticalGreen, LOW);
  digitalWrite(verticalYellow, LOW);
  digitalWrite(verticalRed, HIGH);
}

void loop() {
  delay(1000);
  if (trafficDirection == 0){
    digitalWrite(horizontalGreen, HIGH);
    digitalWrite(horizontalYellow, LOW);
    digitalWrite(horizontalRed,LOW);
    digitalWrite(verticalGreen, LOW);
    digitalWrite(verticalYellow, LOW);
    digitalWrite(verticalRed, HIGH);
    delay(2000);
    digitalWrite(horizontalGreen, LOW);
    digitalWrite(horizontalYellow, HIGH);
    digitalWrite(horizontalRed,LOW);
    digitalWrite(verticalGreen, LOW);
    digitalWrite(verticalYellow, LOW);
    digitalWrite(verticalRed, HIGH);
    delay(3000);
    digitalWrite(horizontalGreen, LOW);
    digitalWrite(horizontalYellow, LOW);
    digitalWrite(horizontalRed,HIGH);
    digitalWrite(verticalGreen, LOW);
    digitalWrite(verticalYellow, LOW);
    digitalWrite(verticalRed, HIGH);
    trafficDirection = 1;
  }
  else if (trafficDirection == 1){
    digitalWrite(horizontalGreen, LOW);
    digitalWrite(horizontalYellow, LOW);
    digitalWrite(horizontalRed,HIGH);
    digitalWrite(verticalGreen, HIGH);
    digitalWrite(verticalYellow, LOW);
    digitalWrite(verticalRed, LOW);
    delay(2000);
    digitalWrite(horizontalGreen, LOW);
    digitalWrite(horizontalYellow, LOW);
    digitalWrite(horizontalRed,HIGH);
    digitalWrite(verticalGreen, LOW);
    digitalWrite(verticalYellow, HIGH);
    digitalWrite(verticalRed, LOW);
    delay(3000);
    digitalWrite(horizontalGreen, LOW);
    digitalWrite(horizontalYellow, LOW);
    digitalWrite(horizontalRed,HIGH);
    digitalWrite(verticalGreen, LOW);
    digitalWrite(verticalYellow, LOW);
    digitalWrite(verticalRed, HIGH);
    trafficDirection = 0;
  }
}
