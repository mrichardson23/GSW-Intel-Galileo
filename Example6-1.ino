void setup() {
	Serial.begin(9600);
}

void loop() {
	if (Serial.available()) {
		Serial.read();
		system("curl http://makezine.com &> /dev/ttyGS0");
	}
}