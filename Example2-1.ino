/*
Everything here is ignored by Arduino's compiler.
*/

int led = 13;

void setup() {
	// This is also ignored.
	pinMode(led, OUTPUT);
}

void loop () {
	digitalWrite(led, HIGH); // This text is ignored as well.
	delay(1000);
	digitalWrite(led, LOW);
	delay(1000);
}