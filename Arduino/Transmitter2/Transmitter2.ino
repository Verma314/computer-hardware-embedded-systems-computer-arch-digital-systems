//simple Tx on pin D12
//Written By : Mohannad Rawashdeh
// 3:00pm , 13/6/2013
//http://www.genotronex.com/
//..................................
#include <VirtualWire.h>
char *controller;
int x;
void setup() {
  Serial.begin(9600); 
  pinMode(13,OUTPUT);
  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(12);
  vw_setup(4000);// speed of data transfer Kbps
}

void loop(){
  x = Serial.parseInt() ;
  Serial.print(x);
  if ( x == 1 ) {
  controller="1"  ;
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,1);
  delay(2000);
  }
  if ( x == 2 ) {
  controller="0"  ;
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(13,0);
  delay(2000);
  }
  
}
