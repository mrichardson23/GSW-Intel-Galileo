#define FSR_PIN 0

void setup() {
	Serial.begin(9600);
}

void loop() {
	int sensorReading = analogRead(FSR_PIN);
	if (sensorReading < 10) {
		Serial.println("I don't feel much at all!");
	}
	else if (sensorReading < 600) {
		Serial.println("Thanks for the squeeze!");
	}
	else {
		Serial.println("Ouch!");
	}
	delay(1000);
}