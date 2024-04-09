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
  pinMode(redIn, INPUT); 
  pinMode(greenIn, INPUT); 
  pinMode(blueIn, INPUT);
  pinMode(redOut, OUTPUT); 
  pinMode(greenOut, OUTPUT); 
  pinMode(blueOut, OUTPUT); 

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
  const int inputPins[3] = {redIn, greenIn, blueIn};
  unsigned long end = millis() + 500;
  while (millis() < end) {
    for (int i = 0; i < 3; i++) {
      int inputPin = inputPins[i];
      int toneFrequency = (mole == i) ? 1000 : 100; // High or low pitch tone
      int toneDuration = (mole == i) ? 10 : 300;    // Duration of the tone
      
      if (digitalRead(inputPin) == HIGH) {
        tone(buzzer, toneFrequency, toneDuration);
        delay(toneDuration);
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
