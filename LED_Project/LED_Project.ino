int red = 0;
int green = 0;
int blue = 0;
int redIn = 5;
int redOut = 11;
int greenIn = 6;
int greenOut = 12;
int blueIn = 7;
int blueOut = 13;
int buzzer = 10;
int incorrectOut = 10;
int mole = -1;


void setup() {
  // Set pin modes for inputs and outputs
  pinMode(redOut, OUTPUT); 
  pinMode(greenOut, OUTPUT); 
  pinMode(blueOut, OUTPUT); 
  pinMode(redIn, INPUT); 
  pinMode(greenIn, INPUT); 
  pinMode(blueIn, INPUT); 

  // Seed the random number generator
  randomSeed(analogRead(0));
}

// Function to display the mole on a random LED
void displayMole() {
  mole = rand() % 3;  // Randomly select a mole position
  switch (mole) {
    case 0:
      digitalWrite(redOut, HIGH);   // Turn on the red LED
      break;
    case 1:
      digitalWrite(greenOut, HIGH); // Turn on the green LED
      break;
    case 2:
      digitalWrite(blueOut, HIGH);  // Turn on the blue LED
      break;
    default:
      break;
  }
}


void whackMole() {
  unsigned long current;
  unsigned long end;
  current = millis();
  end = millis() + 500;
  while (millis() < end) {
    red = digitalRead(redIn);
    if (red == HIGH) {         // check if the input is pressed
           if (mole == 0) {
            // High pitch tone +++
            tone(buzzer, 1000, 10); //Buzzer,Frequency,Duration
            delay(10);
        } else {
            // Low pitch tone ---
            tone(buzzer, 100, 300); //Buzzer,Frequency,Duration
            delay(300);
            }  
      }
    green = digitalRead(greenIn);  // read input value
      if (green == HIGH) {         // check if the input is pressed
           if (mole == 1) {
            // High pitch tone +++
            tone(buzzer, 1000, 10); //Pin,Frequency,Duration
            delay(10);
        } else {
            // Low pitch tone ---
            tone(buzzer, 100, 300); //Pin,Frequency,Duration
            delay(300);
            }  
      }
    blue = digitalRead(blueIn);  // read input value
      if (blue == HIGH) {         // check if the input is pressed
           if (mole == 2) {
            // High pitch tone +++
            tone(buzzer, 1000, 10); //Pin,Frequency,Duration
            delay(10);
        } else {
            // Low pitch tone ---
            tone(buzzer, 100, 300); //Pin,Frequency,Duration
            delay(300);
            }  
      }    
  } 
 
}

void pause() {
  unsigned long current;
  unsigned long end;
  
  mole = -1;
  digitalWrite(redOut, LOW);
  digitalWrite(greenOut, LOW);
  digitalWrite(blueOut, LOW);

  int pauseDuration = rand() % 500 + 100;
  current = millis();
  end = millis() + pauseDuration;
  while (millis() < end) {
    red = digitalRead(redIn);
    green = digitalRead(greenIn);
    blue = digitalRead(blueIn);
    delay(10); //a small delay to reduce rapid button reading
    if (red == HIGH || green == HIGH || blue == HIGH) {
      tone(buzzer, 100, 300); //Pin,Frequency,Duration
      delay(300);
    }
  }
}

void loop() {
  // Main game loop
  pause();        // Pause before displaying the next mole
  displayMole();  // Display the mole on a random LED
  whackMole();    // Handle player input to hit the mole
}
