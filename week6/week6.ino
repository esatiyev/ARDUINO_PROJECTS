// Practice 1: External Interrupt
// #define LD0 13
// #define LD1 20
// #define SW 21

// bool LD1_state = false;
// void setup() {
//   pinMode(LD0, OUTPUT);
//   pinMode(LD1, OUTPUT);
//   pinMode(SW, INPUT_PULLUP);
//   attachInterrupt(SW, SW_ISR, FALLING);
// }

// void loop() {
//   digitalWrite(LD0, LOW);
//   delay(1000);
//   digitalWrite(LD0, HIGH);
//   delay(1000);
// }

// void SW_ISR() {
//   LD1_state = !LD1_state;
//   digitalWrite(LD1, LD1_state);
//   delayMicroseconds(100000); // 100ms
// }

// Practice 2: Interrupt using MsTimer2
#include <DueTimer.h>
#define LED 13
volatile boolean state = true;

void setup() {
  pinMode(LED, OUTPUT);
  Timer3.attachInterrupt(Timer_ISR).start(500000);
}

void loop() {
  delay(1000);
}

void Timer_ISR() {
  digitalWrite(LED, state);
  state = !state;
}