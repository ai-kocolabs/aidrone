const int fan_pin = 23;

void setup() {
	pinMode(fan_pin, OUTPUT);
}

unsigned int howMany = 5;
void loop() {
	if(howMany>0) {
		howMany--;

		digitalWrite(fan_pin, HIGH);
		delay(100);
		digitalWrite(fan_pin, LOW);
		delay(900);
	}
}