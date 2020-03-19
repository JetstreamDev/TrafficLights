
/*
 * 4 Way Intersection
 * 
 * Controls the three colors of lights (RED,YELLOW,GREEN) at a four-way intersection.
 * 
 * There can never be an overlap of directions that would cause an accident:
 *    -If there is a GREEN light, the directions that cross it can only be RED
 *    -A light must be YELLOW for a minimum of three seconds before it can pass from GREEN to RED
 */
// Create an array that contains the pin locations for each light in the group
// Groupings must remain the same amount
int pinArrayHorizontal[]={13,12,11};        // 13 - Green, 12 - Yellow, 11 - Red
int pinArrayVertical[]={8,9,10};            // 8 - Green, 9 - Yellow, 10 - Red
int lenArray=sizeof(pinArrayHorizontal)/sizeof(pinArrayHorizontal[0]);    // Number of lights in group
int lightValues[]={0,0,0};                 // Hold high/low values for the channels

// initialize digital pins as output
void setOutputMode(int lenArray)
{
  for(int i = 0; i<=lenArray; ++i)
  {
    pinMode(pinArrayHorizontal[i], OUTPUT);   // Set group of channels to output
    pinMode(pinArrayVertical[i],OUTPUT);
  }
}

// Run through the channel group passed in (Green,Yellow,Red)
void lightControl(int lightPos, int pinArray[], int lenArray)
{
  lightValues[lightPos]=1;                    // The HIGH channel is determined by the light position passed in 
  for(int i = 0; i<lenArray; ++i)
  {
  digitalWrite(pinArray[i], lightValues[i]);  // Sets the HIGH/LOW value in sequence
  }
  lightValues[lightPos]=0;                    // Sets the HIGH channel value back to LOW so the array is default LOW
}

//  Controls delay between light changes and which light is on next
void activateLights(int lightPos, int pinArray[], int lenArray)
{
  for (int i=0;i<lenArray; ++i)
  {
    delay((i*1000)+1000);                             // Variable delay adds 1 sec for each subsequent light in the group
    lightControl(lightPos,pinArray,lenArray);         // Switch location of active lights
    ++lightPos;                                       // Increments to next light position
  }
}

void setup()
{
  Serial.begin(9600); // open the serial port at 9600 bps
  
  int lightPos=2;             // Initial setup must have Red lights for each grouping
  setOutputMode(lenArray);

  //initialize all groupings to Red light
  lightControl(lightPos,pinArrayHorizontal,lenArray);
  lightControl(lightPos,pinArrayVertical,lenArray);
}

void loop()
{
  int lightPos=0;     // Starts with the first position each loop

  activateLights(lightPos,pinArrayHorizontal,lenArray);
  activateLights(lightPos,pinArrayVertical,lenArray);
}
