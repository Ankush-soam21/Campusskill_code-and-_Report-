// Human Detection Robot with Arduino UNO + PIR Sensor + Buzzer

int pirPin = 2;     // PIR sensor output connected to digital pin 2
int buzzerPin = 8;  // Buzzer connected to digital pin 8
int pirState = LOW; // Start with no motion detected
int val = 0;        // Variable to store PIR sensor status

void setup() {
  pinMode(pirPin, INPUT);       // PIR sensor as input
  pinMode(buzzerPin, OUTPUT);   // Buzzer as output
  Serial.begin(9600);           // For debugging (optional)
}

void loop() {
  val = digitalRead(pirPin);  // Read PIR sensor output

  if (val == HIGH) {          // If motion is detected
    digitalWrite(buzzerPin, HIGH);  // Turn ON buzzer
    if (pirState == LOW) {
      Serial.println("Human Detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(buzzerPin, LOW);   // Turn OFF buzzer
    if (pirState == HIGH) {
      Serial.println("No Human Detected");
      pirState = LOW;
    }
  }
}