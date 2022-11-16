void setup() {
  
  auto_setup();

  drone_setup();

  dnn_initialize();
    
}

void loop() {

  drone_loop();
  
}
