const int TRIG_PIN = 7;
const int ECHO_PIN = 6;
const int BUZZER_PIN = 8;
int buzzer_frequency1 = 1000; // set the first frequency of the buzzer
int buzzer_frequency2 = 1500; // set the second frequency of the buzzer
int buzzer_duration = 100; // set the duration of each frequency in milliseconds

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance_cm = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  if (distance_cm < 100) { // set the threshold distance here
    tone(BUZZER_PIN, buzzer_frequency1, buzzer_duration); // play the first frequency
    delay(buzzer_duration);
    tone(BUZZER_PIN, buzzer_frequency2, buzzer_duration); // play the second frequency
    delay(buzzer_duration);
  } else {
    noTone(BUZZER_PIN); // turn off the buzzer
  }
  
  delay(100);
}
