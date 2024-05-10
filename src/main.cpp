#include <Arduino.h>
#include "NonBlockingOutput.h"
#define NUM_OUTPUS 8
// ini adalah pin yang digunakan untuk output
// const uint8_t arOutputsPin[NUM_OUTPUS] = {15, 4, 5, 18, 19, 21, 22, 23};
const uint8_t arOutputsPin[NUM_OUTPUS] = {13, 12, 14, 27, 26, 25, 33, 32};

// ini adalah durasi output dalam milisecond
uint16_t arOutputOnDuration[NUM_OUTPUS] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};

NonBlockingOutput nbOutput;
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  
  for (uint8_t i = 0; i < NUM_OUTPUS; i++) {
    nbOutput.addOutput(arOutputsPin[i], arOutputOnDuration[i]);
  }
  nbOutput.begin();
  nbOutput.start();
}

void loop() {
  nbOutput.update();
}
