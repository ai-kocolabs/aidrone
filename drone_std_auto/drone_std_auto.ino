#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

void setup() {
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); 
  
  auto_setup();

  drone_setup();
    
}

void loop() {

  drone_loop();
  
}
