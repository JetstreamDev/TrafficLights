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
const int horizontalGreen = 13;           // pin 13 is connected to the horizontal green lights
const int horizontalYellow = 12;          // pin 12 is connected to the horizontal yellow lights
const int horizontalRed = 11;             // pin 11 is connected to the horizontal red lights
const int verticalGreen = 8;              // pin 8 is connected to the veritcal green lights
const int verticalYellow = 9;             // pin 9 is connected to the veritcal yellow lights
const int verticalRed = 10;               // pin 10 is connected to the veritcal red lights

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
    // Horizontal green and veritical red lights are on
    digitalWrite(horizontalGreen, HIGH);
    digitalWrite(horizontalYellow, LOW);
    digitalWrite(horizontalRed,LOW);
    digitalWrite(verticalGreen, LOW);
    digitalWrite(verticalYellow, LOW);
    digitalWrite(verticalRed, HIGH);
    delay(2000);
    // Horizontal yellow and veritical red lights are on
    digitalWrite(horizontalGreen, LOW);
    digitalWrite(horizontalYellow, HIGH);
    digitalWrite(horizontalRed,LOW);
    digitalWrite(verticalGreen, LOW);
    digitalWrite(verticalYellow, LOW);
    digitalWrite(verticalRed, HIGH);
    delay(3000);
    // Horizontal red and veritical red lights are on
    digitalWrite(horizontalGreen, LOW);
    digitalWrite(horizontalYellow, LOW);
    digitalWrite(horizontalRed,HIGH);
    digitalWrite(verticalGreen, LOW);
    digitalWrite(verticalYellow, LOW);
    digitalWrite(verticalRed, HIGH);
    trafficDirection = 1;                 // allow the next direction to go
  }
  else if (trafficDirection == 1){
    // Horizontal red and veritical green lights are on
    digitalWrite(horizontalGreen, LOW);
    digitalWrite(horizontalYellow, LOW);
    digitalWrite(horizontalRed,HIGH);
    digitalWrite(verticalGreen, HIGH);
    digitalWrite(verticalYellow, LOW);
    digitalWrite(verticalRed, LOW);
    delay(2000);
    // Horizontal red and veritical yellow lights are on
    digitalWrite(horizontalGreen, LOW);
    digitalWrite(horizontalYellow, LOW);
    digitalWrite(horizontalRed,HIGH);
    digitalWrite(verticalGreen, LOW);
    digitalWrite(verticalYellow, HIGH);
    digitalWrite(verticalRed, LOW);
    delay(3000);
    // Horizontal red and veritical red lights are on
    digitalWrite(horizontalGreen, LOW);
    digitalWrite(horizontalYellow, LOW);
    digitalWrite(horizontalRed,HIGH);
    digitalWrite(verticalGreen, LOW);
    digitalWrite(verticalYellow, LOW);
    digitalWrite(verticalRed, HIGH);
    trafficDirection = 0;                 // allow the next direction to go
  }
}
