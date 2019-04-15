/*
 * IRremote: IRsendRawDemo - demonstrates sending IR codes with sendRaw
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * IRsendRawDemo - added by AnalysIR (via www.AnalysIR.com), 24 August 2015
 *
 * This example shows how to send a RAW signal using the IRremote library.
 * The example signal is actually a 32 bit NEC signal.
 * Remote Control button: LGTV Power On/Off. 
 * Hex Value: 0x20DF10EF, 32 bits
 * 
 * It is more efficient to use the sendNEC function to send NEC signals. 
 * Use of sendRaw here, serves only as an example of using the function.
 * 
 */


#include <IRremote.h>

IRsend irsend;
bool radiPC = false;
bool radiHT = false;
bool DIMM = false;
int PCpin = 8;
int HTpin = 12;
int khz = 38; // 38kHz carrier frequency for the NEC protocol
unsigned int irSignal[] = {4420, 4420, 520, 1638, 520, 1638, 520, 520, 520, 520, 520, 520, 520, 520, 520, 1638, 520, 520, 520, 1638, 520, 1638, 520, 520, 520, 520, 520, 1638, 520, 520, 520, 1638, 520, 520, 520, 1638, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 1638, 520, 1638, 520, 1638, 520, 1638, 520, 1638, 520, 1638, 520, 1638, 520, 45656};
unsigned int irSignal2[] = {4420, 4420, 520, 1638, 520, 1638, 520, 520, 520, 520, 520, 520, 520, 520, 520, 1638, 520, 520, 520, 1638, 520, 1638, 520, 520, 520, 520, 520, 1638, 520, 520, 520, 1638, 520, 520, 520, 520, 520, 520, 520, 520, 520, 1638, 520, 1638, 520, 520, 520, 520, 520, 520, 520, 1638, 520, 1638, 520, 1638, 520, 520, 520, 520, 520, 1638, 520, 1638, 520, 1638, 520, 45656};
void sendIR(){
  
irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz);

}
void sendIR2(){
irsend.sendRaw(irSignal2, sizeof(irSignal2) / sizeof(irSignal2[0]), khz);
}


volatile byte state = LOW;
void setup()
{
  Serial.begin(115200);
  pinMode(PCpin, INPUT);
  pinMode(HTpin, INPUT);
}

void loop() { 
   radiPC = digitalRead(PCpin);
   radiHT = digitalRead(HTpin);
   if(radiPC && !radiHT){ sendIR(); digitalWrite(LED_BUILTIN, HIGH); DIM = false;}
   if(!radiPC && radiHT){ sendIR(); digitalWrite(LED_BUILTIN, LOW);}
   delay(5000);
   if(radiPC && radiHT && !DIMM){sendIR2(); DIMM=true;}
}


