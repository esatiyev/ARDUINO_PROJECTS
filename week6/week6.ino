// Practice 1: External Interrupt
// #define LD0 13
// #define LD1 20
// #define SW 21

// bool LD1_state = false;
// void setup() {
//   pinMode(LD0, OUTPUT);
//   pinMode(LD1, OUTPUT);
//   pinMode(SW, INPUT_PULLUP);
//   attachInterrupt(SW, SW_ISR, RISING);
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
// #include <DueTimer.h>
// #define LED 13
// volatile boolean state = true;

// void setup() {
//   pinMode(LED, OUTPUT);
//   Timer3.attachInterrupt(Timer_ISR).start(500000);
// }

// void loop() {
//   delay(1000);
// }

// void Timer_ISR() {
//   digitalWrite(LED, state);
//   state = !state;
// }


// ===========================
// ===== HOMEWORK WEEK 5 =====
// ===========================

// // Team 11: Homework 1
// #include <DueTimer.h>
// #define LD0 13
// #define LD1 12
// #define LD2 11
// #define LD_ISR 20
// #define SW 21
// volatile bool inISR = false;      
// volatile int count = 0;           
// void setup() {
//   pinMode(LD0, OUTPUT);
//   pinMode(LD1, OUTPUT);
//   pinMode(LD2, OUTPUT);
//   pinMode(LD_ISR, OUTPUT);

//   // Button
//   pinMode(SW, INPUT_PULLUP);

//   Serial.begin(9600);
//   attachInterrupt(SW, buttonISR, FALLING);
// }
// void loop() {
//   if (!inISR) {
//     digitalWrite(LD0, HIGH);
//     digitalWrite(LD1, HIGH);
//     digitalWrite(LD2, HIGH);
//     delay(1000);
    
//     digitalWrite(LD0, LOW);
//     digitalWrite(LD1, LOW);
//     digitalWrite(LD2, LOW);
//     delay(1000);
//   }
// }
// void buttonISR() {
//   inISR = true;       
//   count = 0;        
//   Timer3.attachInterrupt(timerISR).start(1000000); // 1 second interval
//   delayMicroseconds(100000); 
// }
// void timerISR() {
//   count++;
//   Serial.print("ISR Second: ");
//   Serial.println(count);
//   digitalWrite(LD_ISR, HIGH);

//   if (count >= 5) {
//     Timer3.stop(); // Stop Timer after 5 seconds
//     digitalWrite(LD_ISR, LOW);  
//     inISR = false;               
//   }
// }

// Team 11: Homework 2
#define SW 21              
#define MOTOR_PWM 2         
volatile int pressCount = 0;
volatile unsigned long lastInterruptTime = 0;  
void setup() {
  pinMode(MOTOR_PWM, OUTPUT);
  pinMode(SW, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(SW), SW_ISR, FALLING);
}

void loop() {
  // all handled in ISR
}

void SW_ISR() {
  unsigned long currentTime = millis();
  // Debounce: Only trigger if at least 200ms passed since last press
  if (currentTime - lastInterruptTime > 200) {
    pressCount++;
    if (pressCount > 3) {
      pressCount = 0;
    }

    switch (pressCount) {
      case 1:
        analogWrite(MOTOR_PWM, 64);   // ~25% duty
        break;
      case 2:
        analogWrite(MOTOR_PWM, 128);  // ~50%
        break;
      case 3:
        analogWrite(MOTOR_PWM, 255);  // ~100%
        break;
      case 0:
        analogWrite(MOTOR_PWM, 0);   
        break;
    }

    lastInterruptTime = currentTime; 
  }
}
