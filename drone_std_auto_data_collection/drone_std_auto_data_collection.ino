void setup() {
  
  Serial.begin(115200);
  
  auto_setup();

  drone_setup();
    
}

void loop() {
    
  drone_loop();

}
