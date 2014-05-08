const int potentiometerPin = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
	int sensorReading = analogRead(potentiometerPin);
	int displayValue = map(sensorReading, 0, 1023, 0, 100);
	Serial.print("Potentiometer is at ");
	Serial.print(displayValue);
	Serial.println("%.");
	delay(500);
}