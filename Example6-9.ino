#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
	lcd.init(1,12,255,11,5,4,3,2,0,0,0,0);
	lcd.begin(16, 2);
	lcd.setCursor(3, 0);
	lcd.print("days until");
	lcd.setCursor(0, 1);
	lcd.print("MAKE is here!");
}

void loop() {
	lcd.setCursor(0, 0);
	lcd.print(" ");
	lcd.setCursor(0, 0);
	lcd.print(getDays());
	delay(30*60*1000);
}

int getDays() {
	char output[5];
	FILE *fp;
	fp = popen("python /home/root/json-parse.py", "r");
	if (fp == NULL) {
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