#include <Ethernet.h>
int buttonPin = 2;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

EthernetServer server(80);

void setup() {
	Serial.begin(9600);
	Ethernet.begin(mac);
	server.begin();
	Serial.print("server is at ");
	Serial.println(Ethernet.localIP());
	pinMode(buttonPin, INPUT);
}

void loop() {
	EthernetClient client = server.available();
	if (client) {
		Serial.println("new client");
		boolean currentLineIsBlank = true;
		while (client.connected()) {
			if (client.available()) {
				char c = client.read();
				Serial.write(c);
				if (c == '\n' && currentLineIsBlank) {
					client.println("HTTP/1.1 200 OK");
					client.println("Content-Type: text/html");
					client.println("Connection: close");
					client.println();
					client.println("<!DOCTYPE HTML>");
					client.println("<html>");
					if (digitalRead(buttonPin)) {
						client.println("<h1>The button is pressed!</h1>");
					}
					else {
						client.println("<h1>The button is not pressed!</h1>");
					}
					client.println("</html>");
					break;
				}
				if (c == '\n') {
					currentLineIsBlank = true;
				}
				else if (c != '\r') {
					currentLineIsBlank = false;
				}
			}
		}
		delay(1);
		client.stop();
		Serial.println("client disconnected");
	}
}