void setup() {
	system("telnetd -l /bin/sh");
}

void loop() {
	system("ifconfig eth0 > /dev/ttyGS0");
	delay(5000);
}