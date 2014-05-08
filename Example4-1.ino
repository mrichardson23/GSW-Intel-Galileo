int switchInputPin = 2;

void setup() {
	pinMode(switchInputPin, INPUT);
	Serial.begin(9600);
}

void loop() {
	int switchState = digitalRead(switchInputPin);
	if (switchState == HIGH) {
		Serial.println("The switch is on!");
	else {
		Serial.println("The switch is off!");
	}
	delay(500);
}