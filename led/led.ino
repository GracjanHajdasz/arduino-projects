int buttonPin = 12;
int lastButtonState = HIGH;
int numOfClicks = 0;
//----------------
int redLedPin = 2;
int redLedState = LOW;
//-----------------
int yellowLedPin = 3;
int yellowLedState = LOW;
//-----------------
int greenLedPin = 4;
int greenLedState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(greenLedPin, HIGH);
  int buttonState = digitalRead(buttonPin);
  if( lastButtonState == HIGH && buttonState == LOW ) {
    numOfClicks += 1;
    if (numOfClicks == 4) {
      numOfClicks = 0;
    }
    delay(500);
  }
  lastButtonState = buttonState;

  if(numOfClicks == 0) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
  }
  if(numOfClicks == 1) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
  }
  if(numOfClicks == 2) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
  }
  if(numOfClicks == 3) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(greenLedPin, HIGH);
  }
}
