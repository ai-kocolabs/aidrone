void setup() {
	Serial.begin(115200);
}

void loop() {
	if(Serial.available()>0) {
		char userInput = Serial.read();
		Serial.print(userInput);
	}  
}