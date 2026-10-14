const int triggerPin = 5;
const int echoPin = 4;

const int buzzerPin = 8;
int lastBuzzerState = LOW;
long duration;
int distance;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  //guarantee low state on trigger pin
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  //send impulse
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  //read duration and calculate distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  int buzzerState = LOW;
  if (distance <= 15) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
}