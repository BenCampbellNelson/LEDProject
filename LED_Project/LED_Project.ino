int red = 0;
int green = 0;
int blue = 0;
int redButtonPin = 5;
int redOutputPin = 11;
int greenButtonPin = 6;
int greenOutputPin = 12;
int blueButtonPin = 7;
int blueOutputPin = 13;
int buzzer = 10;
int incorrectOut = 10;
int mole = -1;

int RGBred = 2;
int RGBgreen = 3;
int RGBblue = 4;


void setup() {
  // Set pin modes for inputs and outputs
  pinMode(redButtonPin, INPUT); 
  pinMode(greenButtonPin, INPUT); 
  pinMode(blueButtonPin, INPUT);
  pinMode(redOutputPin, OUTPUT); 
  pinMode(greenOutputPin, OUTPUT); 
  pinMode(blueOutputPin, OUTPUT); 

  // Seed the random number generator
  randomSeed(analogRead(0));
}

// Function to display the mole on a random LED
void displayMole() {
  mole = rand() % 3;  // Randomly select a mole position
  switch (mole) {
    case 0:
      digitalWrite(redOutputPin, HIGH);   // Turn on the red LED
      break;
    case 1:
      digitalWrite(greenOutputPin, HIGH); // Turn on the green LED
      break;
    case 2:
      digitalWrite(blueOutputPin, HIGH);  // Turn on the blue LED
      break;
    default:
      break;
  }
}


void whackMole() {
  const int inputPins[3] = {redButtonPin, greenButtonPin, blueButtonPin};
  unsigned long end = millis() + 500;
  while (millis() < end) {
    for (int i = 0; i < 3; i++) {
      int inputPin = inputPins[i];
      int toneFrequency = (mole == i) ? 1000 : 100; // High or low pitch tone
      int toneDuration = (mole == i) ? 10 : 300;    // Duration of the tone
      
      if (digitalRead(inputPin) == HIGH) {
        if (mole == i) {
          // Correct hit
          digitalWrite(RGBgreen, HIGH); // Turn on green on correct hit
          delay(500); 
          digitalWrite(RGBgreen, LOW);  
        } else {
          // Incorrect hit
          digitalWrite(RGBred, HIGH);   // Turn on red on incorrect hit
          delay(500); 
          digitalWrite(RGBred, LOW);    
        }
        tone(buzzer, toneFrequency, toneDuration);
        delay(toneDuration);
      }
    }
  }
}





void pause() {
  mole = -1;  // Reset mole position
  digitalWrite(redOutputPin, LOW);   // Turn off red LED
  digitalWrite(greenOutputPin, LOW); // Turn off green LED
  digitalWrite(blueOutputPin, LOW);  // Turn off blue LED

  // Generate a random pause duration between 100 and 599 milliseconds
  int pauseDuration = random(2000) + 100; //Keep 100 so there is a minimum pause length
  
  // Wait for the pause duration to elapse
  unsigned long pauseStartTime = millis();
  while (millis() - pauseStartTime < pauseDuration) {
    // Check for button press during the pause
    if (digitalRead(redButtonPin) == HIGH || digitalRead(greenButtonPin) == HIGH || digitalRead(blueButtonPin) == HIGH) {
      tone(buzzer, 100, 300); // Play tone for button press
      delay(300);             // Wait for tone to finish
    }
    delay(10); // Small delay to reduce rapid button reading
  }
}


void loop() {
  // Main game loop
  pause();        // Pause before displaying the next mole
  displayMole();  // Display the mole on a random LED
  whackMole();    // Handle player input to hit the mole
}
