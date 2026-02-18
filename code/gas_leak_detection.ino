// Gas Leak Detection System using MQ-2 Sensor

int gasSensor = A0;   // MQ-2 analog pin
int buzzer = 8;       // Buzzer pin
int led = 9;          // LED pin

int threshold = 300;  // Gas level threshold (adjust if needed)

void setup() {
  Serial.begin(9600);
  
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  
  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);

  Serial.println("Gas Leak Detection System Started");
}

void loop() {
  int gasValue = analogRead(gasSensor);

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  // If gas level exceeds threshold
  if (gasValue > threshold) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);
    Serial.println("Gas Leak Detected!");
  } 
  else {
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
  }

  delay(1000);
}

