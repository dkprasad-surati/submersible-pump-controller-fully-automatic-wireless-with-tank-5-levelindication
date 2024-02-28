#include <VirtualWire.h>
 char msg1;
void setup () {
  // Initialise the IO and ISR
  vw_setup (2000);        // Bits per sec
  vw_set_tx_pin (12);          // Transmitter Data Pin to Digital Pin 3
  
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);
}
void loop () {
if(!digitalRead(6)){
  char *msg2 = "5";
     vw_send ((uint8_t *) msg2, strlen (msg2));
    vw_wait_tx ();
  }
else if(!digitalRead(5)){
  char *msg2 = "4";
     vw_send ((uint8_t *) msg2, strlen (msg2));
    vw_wait_tx ();
  }
else if(!digitalRead(4)){
  char *msg2 = "3";
     vw_send ((uint8_t *) msg2, strlen (msg2));
    vw_wait_tx ();
  }
else if(!digitalRead(3)){
  char *msg2 = "2";
     vw_send ((uint8_t *) msg2, strlen (msg2));
    vw_wait_tx ();
  }
else if(!digitalRead(2)){
  char *msg2 = "1";
     vw_send ((uint8_t *) msg2, strlen (msg2));
    vw_wait_tx ();
  }
else{
  char *msg2 = "0";
     vw_send ((uint8_t *) msg2, strlen (msg2));
    vw_wait_tx ();
  } 
}
