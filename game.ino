/*
  Alexander Freyr Lúðvíksson
  Helga Eyþórsdóttir
  Íris Ósk Óttardóttir
  Jóhann Kjartansson
*/

const int rightButton = 1;
const int leftButton = 0;

const int rightRed = 13;
const int rightGreen = 12;
const int leftGreen = 10;
const int leftRed = 11;

int A = 3;
int B = 2;
int C = 4;
int D = 5;
int DP = 7;
int E = 6;
int F = 9;
int G = 8;

void setup()
{
  // Buttons
  pinMode(rightButton, INPUT);
  pinMode(leftButton, INPUT);

  // LED's
  pinMode(rightRed, OUTPUT);
  pinMode(rightGreen, OUTPUT);
  pinMode(leftRed, OUTPUT);
  pinMode(leftGreen, OUTPUT);

  // Display
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);

  Serial.begin(9600);
  waitForStart();
}

int displayCounter = 9;
void loop()
{ 
  // Check if game is over
  if(isOver())
  {
    // Update the display
    changeNumber(displayCounter);
  
    if(displayCounter == 0)
    {
      // Making sure the counter doesn't go below 0
      changeNumber(0);
    }
    else
    {
      // To make sure the counter doesn't decrement way to fast for the
      // players, we wait a few seconds to update the display again.
      int starttime = millis();
      int endtime = starttime;
      while((endtime - starttime) <= 500)
      {
        // If players press the button too early, they should lose, so we
        // still have to check for button presses while we are waiting for the
        // display to update.
        checkPress();  
        endtime = millis();
      }
      displayCounter--;
    }
    checkPress();
  }else{
    delay(5000); // Wait 5 seconds before starting again.
    waitForStart();
  }
}

/*
  Check if the game is over by checking if any lightbulbs are on.
*/
bool isOver()
{
  if(digitalRead(leftGreen)  == LOW && 
     digitalRead(leftRed)    == LOW && 
     digitalRead(rightGreen) == LOW &&
     digitalRead(rightRed)   == LOW)
  {
    return true;
  }
  return false;
}

/*
  The program will wait for user input to start,
  when either of the two buttons are pressed the game will
  start.
*/
void waitForStart()
{
  // Reset variables
  digitalWrite(leftGreen, LOW);
  digitalWrite(leftRed, LOW);
  digitalWrite(rightGreen, LOW);
  digitalWrite(rightRed, LOW);
  displayCounter = 9;

  // Wait for input
  bool running = true;

  int animCounter = 0;
  while(running)
  {
    if(animCounter % 6 == 0)
    {
      animCounter = 0;
    }
    animation(animCounter);
    animCounter++;
    int leftButtonState = digitalRead(leftButton);
    int rightButtonState = digitalRead(rightButton);

    if(leftButtonState == LOW || rightButtonState == LOW)
    {
      running = false;
    }
  }
  delay(500);
}

/*
  Animates the display to go in circles.
*/
void animation(int number)
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  switch(number)
  {
    case 0:
      digitalWrite(B, LOW);
      break; 
    case 1:
      digitalWrite(C, LOW);
      break;
    case 2:
      digitalWrite(D, LOW);
      break;
    case 3:
      digitalWrite(E, LOW);
      break;
    case 4:
      digitalWrite(F, LOW);
      break;
    case 5:
      digitalWrite(A, LOW); 
      break;
  }
  delay(100);
}

/*
Function checks if a button is pressed.

If a button is pressed the function will light the LED lights,
with a winner (green) and a loser (red).
*/
void checkPress()
{
  int leftButtonState = digitalRead(leftButton);
  int rightButtonState = digitalRead(rightButton);
  
  // If any lightbulbs are on, the game is over and no more buttons can be pressed.
  if(isOver())
  {
    // If left button is pressed.
    if(leftButtonState == LOW)
    {
      if(displayCounter == 0)
      {
        digitalWrite(leftGreen, HIGH);
        digitalWrite(rightRed, HIGH);
      }
      else
      {
        digitalWrite(leftRed, HIGH);
        digitalWrite(rightGreen, HIGH);
      }
    } 

    // If right button is pressed.
    if(rightButtonState == LOW)
    {
      if(displayCounter == 0)
      {
        digitalWrite(rightGreen, HIGH);
        digitalWrite(leftRed, HIGH);
      }
      else
      {
        digitalWrite(rightRed, HIGH);
        digitalWrite(leftGreen, HIGH);
      }
    } 
  }
}

//The method that displays the numbers 
void changeNumber(int buttonPress)
{
  switch (buttonPress)
  {
    //number 0
    case 0:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      break;
    //number 1
    case 1:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    //number 2
    case 2:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;
    //number 3
    case 3:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;
    //number 4
    case 4:
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    //number 5
    case 5:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    //number 6
    case 6:
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    //number 7
    case 7:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    //number 8
    case 8:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    //number 9
    case 9:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
  }
}
