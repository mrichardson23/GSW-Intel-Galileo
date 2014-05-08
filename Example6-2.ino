void setup() {
	Serial.begin(9600);
}

void loop() {
	system("ifconfig &> /dev/ttyGS0");
	delay(3000);
}
