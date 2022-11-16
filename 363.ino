TaskHandle_t TaskCore_0;

void setup() {

	Serial.begin(115200); 

	xTaskCreatePinnedToCore(
	t0_main,   /* Task function. */
	"TaskCore_0",/* name of task. */
	10000,       /* Stack size of task */
	NULL,        /* parameter of the task */
	1,           /* priority of the task */
	&TaskCore_0, /* Task handle to keep track of created task */
	0);          /* pin task to core 0 */                  

	delay(1000); 

}

void t0_main( void * pvParameters ){

	for(;;){
		
		Serial.print("TaskCore_0 running on core ");
		Serial.println(xPortGetCoreID());
		delay(500);
		
	} 
}

void loop() {

	Serial.print("loop() running on core ");
	Serial.println(xPortGetCoreID()); 
	delay(1000);

}