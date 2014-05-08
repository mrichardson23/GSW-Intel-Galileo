void setup() {
	Serial.begin(9600);
}

void loop() {
	Serial.println(getHours());
	delay(5000);
}

int getHours() {
	char output[5];
	FILE *fp;
	fp = popen("curl http://nextmakemagazine.appspot.com/simple", "r");
	if(fp == NULL) {
		Serial.println("Couldn't run the curl command.");
		return -1;
	}
	else {
		fgets(output, sizeof(output), fp);
	}
	if (pclose(fp) != 0) {
		Serial.println("The curl command returned an error.");
		return -1;
	}
	return atoi(output);
}