const int fan_pin = 23;

void setup() {
	pinMode(fan_pin, OUTPUT);
}

unsigned int howMany = 50;
void loop() {
	if(howMany>0) {
		howMany--;

		digitalWrite(fan_pin, HIGH);
		delay(10);
		digitalWrite(fan_pin, LOW);
		delay(90);
	}
}