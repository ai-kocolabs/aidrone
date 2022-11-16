TaskHandle_t TaskAutoAviHandle;

void auto_setup() {
  xTaskCreatePinnedToCore(
    TaskAutoAviMain,   /* Task function. */
    "TaskAutoAvi",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    &TaskAutoAviHandle, /* Task handle */
    0);          /* pin task to core 0 */

  delay(2000); 
}

extern double tAngleX, tAngleY;
extern int throttle;
int data_sampling_en = 0;
int data_streaming_en = 0;
void TaskAutoAviMain( void * pvParameters ){

  delay(5000);  
  
  data_sampling_en = 1;

  for(int thr = 0; thr < 475; thr++) { // 475*4 = 1900밀리 초간 상승
    throttle = thr;
    delay(4);
  }

  for(int thr = 475; thr > 300; thr--) { // (475-300)*12 = 2100밀리 초간 하강
    throttle = thr;
    delay(12);
  }

  for(int thr = 300; thr > 0; thr--) { // 300*5 = 1500밀리 초간 하강
    throttle = thr;
    delay(5);
  }

  throttle = 0;
  
  data_sampling_en = 0;
  
  data_streaming_en = 1;

  vTaskDelete( TaskAutoAviHandle );
  
}
