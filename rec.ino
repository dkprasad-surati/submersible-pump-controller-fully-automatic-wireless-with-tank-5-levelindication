#include <VirtualWire.h>
bool state;
void setup () {
  Serial.begin (9600);            // Debugging only
 
  // Initialise the IO and ISR
  vw_setup (2000);      // Bits per sec
  vw_set_rx_pin (11);    // Rx Data pin to Digital  Pin 2
  vw_rx_start ();       // Start the receiver PLL running
    pinMode(9, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
 pinMode(8, INPUT_PULLUP);
}
void loop () {
  uint8_t buf [VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message (buf, &buflen)) {
    int i; 
    // Message with a good checksum received, dump it
    //Serial.println(buf [0]);
   switch(buf [0]){
    case '0':
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,0);
digitalWrite(7,0);
    break;
    case '1':
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(5,0);
digitalWrite(6,0);
digitalWrite(7,0);
    break;
    case '2':
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,0);
digitalWrite(6,0);
digitalWrite(7,0);
    break;
    case '3':
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,0);
digitalWrite(7,0);
    break;
    case '4':
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,1);
digitalWrite(7,0);
    break;
    case '5':
digitalWrite(3,1);
digitalWrite(4,1);
digitalWrite(5,1);
digitalWrite(6,1);
digitalWrite(7,1);
    break;    
    }
if(buf [0]<50) digitalWrite(9,0);   
if(buf [0]>52) digitalWrite(9,1);
else if(!digitalRead(8)&!state){state=1;digitalWrite(9,!digitalRead(9));  }      
  if(digitalRead(8))state=0;
  }
}
