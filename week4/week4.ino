// Practice 1
// void setup() {
//   // put your setup code here, to run once:
//   pinMode(44, OUTPUT);

// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   digitalWrite(44, HIGH);
//   delay(1000);
//   digitalWrite(44, LOW);
//   delay(1000);
// }


// // Practice 2
// #define LED 13
// #define BUTTON 2
// void setup() {
//   // put your setup code here, to run once:
//   pinMode(LED, OUTPUT);
//   pinMode(BUTTON, INPUT_PULLUP);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   if(digitalRead(BUTTON) == LOW) {
//     digitalWrite(LED, HIGH);
//   } else {
//     digitalWrite(LED, LOW);
//   }
// }

// // Practice 3
// #define LED1 7
// #define LED2 6
// #define BUTTON1 5
// #define BUTTON2 4
// void setup() {

//   pinMode(LED1, OUTPUT);
//   pinMode(LED2, OUTPUT);
//   pinMode(BUTTON1, INPUT_PULLUP);
//   pinMode(BUTTON2, INPUT_PULLUP);
//   Serial.begin(115200);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   if(digitalRead(BUTTON1) == LOW) {
//     digitalWrite(LED1, HIGH);
//     Serial.println("turn on");
//   } else {
//     digitalWrite(LED1, LOW);
//     Serial.println("turn off");
//   }
  
//   if(digitalRead(BUTTON2) == LOW) {
//     digitalWrite(LED2, HIGH);
//     Serial.println("turn on 2");
//   } else {
//     digitalWrite(LED2, LOW);
//     Serial.println("turn off 2");
//   }
// }



// Serial 2
// int val = 0;

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
  
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   if(Serial.available() > 0) {
//     val = Serial.read();
//     Serial.println(val - '0');
//   }
// }






// ===========================
// ===== HOMEWORK WEEK 4 =====
// ===========================

// Team 11: Homework 1
// void setup() {
//   Serial.begin(9600);
// }

// void loop() {
//   if (Serial.available()) {
//     char c = Serial.read();

//     if ( ('A' <= c) && (c <= 'Z')) {
//       c = c + 0x20;
//     } 
//     else if ( ('a' <= c) && (c <= 'z')) {
//       c = c - 0x20;
//     }

//     Serial.write(c);
//   }
// }


// Team 11: Homework 2
#define LED1  5
#define LED2  6
#define LED3  7
bool g_is_blinking = false;
bool r_is_blinking = false;
bool y_is_blinking = false;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    Serial.write(c);
    if (c == 'g')      g_is_blinking = !g_is_blinking;
    else if (c == 'r') r_is_blinking = !r_is_blinking;
    else if (c == 'y') y_is_blinking = !y_is_blinking;     
  }
  
  if(g_is_blinking) digitalWrite(LED1, HIGH);
  if(r_is_blinking) digitalWrite(LED2, HIGH);
  if(y_is_blinking) digitalWrite(LED3, HIGH);
  delay(500);

  if(g_is_blinking) digitalWrite(LED1, LOW);
  if(r_is_blinking) digitalWrite(LED2, LOW);
  if(y_is_blinking) digitalWrite(LED3, LOW);
  delay(500);
}



