// Week 5
// Practice 1
// const int AnalogPin = A0;

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   int Ain = analogRead(AnalogPin);
//   Serial.println(Ain);
//   delay(1000);
// }

// Practice 2
// int IN1 = 2;
// void setup() {
//   pinMode(IN1, OUTPUT);
// }
// void loop() {
//   for(int i=0; i<255; i++) {
//     analogWrite(IN1, i);
//   }
// }


// //Practice 3
// unsigned long distance;

// void setup() {
//   pinMode(27, OUTPUT);
//   pinMode(28, INPUT_PULLUP);
//   Serial.begin(9600);
// }

// void loop() {
//   unsigned long Width;

//   digitalWrite(27, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(27, LOW);

//   Width = pulseIn(28, HIGH);
//   distance = Width / 58;

//   Serial.print("Distance : ");
//   Serial.print(distance);
//   Serial.print("cm\n");
// }

// ===========================
// ===== HOMEWORK WEEK 5 =====
// ===========================

// Team 11: Homework 1
// const int Ain = A0;
// const int IN1 = 2;

// void setup() {
//   pinMode(IN1, OUTPUT);
//   pinMode(Ain, INPUT);
//   analogWriteResolution(8);
// }
// void loop() {
//   int value = analogRead(Ain);
//   int pwm = map(value, 0, 1023, 0, 255);
//   analogWrite(IN1, pwm);
// }

// Team 11: Homework 2
unsigned long distance;
int IN1 = 2;
const int Ain = A0;
void setup() {
  // ultrasonic
  pinMode(27, OUTPUT);
  pinMode(28, INPUT_PULLUP);
  // motor
  pinMode(IN1, OUTPUT);
  // potentiometer
  pinMode(Ain, INPUT);
  analogWriteResolution(8);
  Serial.begin(9600);
}
void loop() {
  // potentiometer
  int value = analogRead(Ain);
  int pwm = map(value, 0, 1023, 0, 255);
  Serial.print("Potentiometer: ");
  Serial.print(pwm);
  Serial.print("\n");
  // ultrasonic
  unsigned long Width;

  digitalWrite(27, HIGH);
  delayMicroseconds(10);
  digitalWrite(27, LOW);

  Width = pulseIn(28, HIGH);
  distance = Width / 58;
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.print("cm\n");

  if(distance < 10) analogWrite(IN1, 0.5 * pwm);
  else analogWrite(IN1, pwm);

  delay(100);
}

