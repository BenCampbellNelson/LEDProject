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
int incorrect = 10;
int mole = -1;


void setup() {
  // put your setup code here, to run once:
  pinMode(redOut, OUTPUT); 
  pinMode(greenOut, OUTPUT); 
  pinMode(blueOut, OUTPUT); 
  pinMode(redIn, INPUT); 
  pinMode(greenIn, INPUT); 
  pinMode(blueIn, INPUT); 
}

void displayMole() {
  mole = rand() % 3;
  switch (mole) {
    case 0:
      digitalWrite(redOut, HIGH);
      break;
    case 1:
      digitalWrite(greenOut, HIGH);
      break;
    case 2:
      digitalWrite(blueOut, HIGH);
      break;
    default:
      break;
  }
}


void whackMole() {
  
}

void pause() {
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
