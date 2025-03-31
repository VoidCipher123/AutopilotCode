// #include "SoftServo.h"

// SoftServo ServoPitch;  // Y
// SoftServo ServoRoll;   // x
// SoftServo ServoYaw;    // z
// SoftServo ServoEng;    // Additional servo (For any other purpose)


// void ServoSetup() {
//   // Attach pin to servo
//   ServoPitch.attach(PitchPin);
//   ServoRoll.attach(RollPin);
//   ServoYaw.attach(YawPin);
//   ServoEng.attach(EngPin);
//   // Make async mode to get rid of delays
//   ServoPitch.asyncMode();
//   ServoRoll.asyncMode();
//   ServoYaw.asyncMode();
//   ServoEng.asyncMode();
// }

// void servoTick() {
//   ServoPitch.tick();
//   ServoRoll.tick();
//   ServoYaw.tick();
//   ServoEng.tick();
// }

// void angleWrite(int x, int y, int z) {
//   ServoPitch.write(x);
//   ServoRoll.write(y);
//   ServoYaw.write(z);
// }

// void angleWrite(int x, int y, int z, int e) {
//   ServoPitch.write(x);
//   ServoRoll.write(y);
//   ServoYaw.write(z);
//   ServoEng.write(e);
// }

// void angleWriteMicroseconds(int x, int y, int z) {
//   ServoPitch.writeMicroseconds(x);
//   ServoRoll.writeMicroseconds(y);
//   ServoYaw.writeMicroseconds(z);
// }

// void angleWriteMicroseconds(int x, int y, int z, int e) {
//   ServoPitch.writeMicroseconds(x);
//   ServoRoll.writeMicroseconds(y);
//   ServoYaw.writeMicroseconds(z);
//   ServoEng.writeMicroseconds(e);
// }


// void Attach_servos() {
//   //if servo is not controled by the Arduino Begin controlling
//   if (~(ServoPitch.attached())) ServoPitch.attach(PitchPin);
//   if (~(ServoRoll.attached())) ServoRoll.attach(RollPin);
//   if (~(ServoYaw.attached())) ServoYaw.attach(YawPin);
//   if (~(ServoEng.attached())) ServoEng.attach(EngPin);
// }


// void Detach_servos() {
//   //If servo is controlled by Arduino Stop conrolling
//   if (ServoPitch.attached()) {
//     ServoPitch.write(90);
//     delay(100);
//     ServoPitch.detach();
//     pinMode(PitchPin, LOW);
//   }

//   if (ServoRoll.attached()) {
//     ServoRoll.write(90);
//     delay(100);
//     ServoRoll.detach();
//     pinMode(RollPin, LOW);
//   }

//   if (ServoYaw.attached()) {
//     ServoYaw.write(90);
//     delay(100);
//     ServoYaw.detach();
//     pinMode(YawPin, LOW);
//   }
//   if (ServoEng.attached()) {
//     ServoEng.write(90);
//     delay(100);
//     ServoEng.detach();
//     pinMode(EngPin, LOW);
//   }
// }
#include <Servo.h>

Servo ServoRoll;   // x
Servo ServoPitch;  // Y
Servo ServoYaw;    // z
Servo ServoEng;    // Additional servo (For any other purpose)

void ServoSetup() {
  // Attach pin to servo
  ServoPitch.attach(PitchPin);
  ServoRoll.attach(RollPin);
  ServoYaw.attach(YawPin);
  ServoEng.attach(EngPin);
  ServoEng.writeMicroseconds(2000);
  delay(1000);
  ServoEng.writeMicroseconds(1000);

  
}

void angleWrite(int x, int y, int z) {
  ServoPitch.write(x);
  ServoRoll.write(y);
  ServoYaw.write(z);
  ServoEng.writeMicroseconds(GetEngine());
}

void angleWrite(int x, int y, int z, int e) {
  ServoPitch.write(x);
  ServoRoll.write(y);
  ServoYaw.write(z);
  ServoEng.write(e);
}

void angleWriteMicroseconds(int x, int y, int z) {
  ServoPitch.writeMicroseconds(x);
  ServoRoll.writeMicroseconds(y);
  ServoYaw.writeMicroseconds(z);
}

void angleWriteMicroseconds(int x, int y, int z, int e) {
  ServoPitch.writeMicroseconds(x);
  ServoRoll.writeMicroseconds(y);
  ServoYaw.writeMicroseconds(z);
  ServoEng.writeMicroseconds(e);
}


// #include <Adafruit_SoftServo.h>  // SoftwareServo (works on non PWM pins)

// Adafruit_SoftServo ServoRoll;   // x
// Adafruit_SoftServo ServoPitch;  // Y
// Adafruit_SoftServo ServoYaw;    // z
// Adafruit_SoftServo ServoEng;    // Additional servo (For any other purpose)


// void ServoSetup(){
//   OCR0A = 0xAF;            // any number is OK
//   TIMSK0 |= _BV(OCIE0A);    // Turn on the compare interrupt (below!)
//   ServoPitch.attach(PitchPin);
//   ServoRoll.attach(RollPin);
//   ServoYaw.attach(YawPin);
//   ServoEng.attach(EngPin);
// }

// void angleWrite(int x, int y, int z) {
//   ServoPitch.write(x);
//   ServoRoll.write(y);
//   ServoYaw.write(z);
// }

// void angleWriteMicroseconds(int x, int y, int z) {
//   ServoPitch.writeMico(x);
//   ServoRoll.write(y);
//   ServoYaw.write(z);
// }


// void Attach_servos() {
//   //if servo is not controled by the Arduino Begin controlling
//   if (~(ServoPitch.attached())) ServoPitch.attach(PitchPin);
//   if (~(ServoRoll.attached())) ServoRoll.attach(RollPin);
//   if (~(ServoYaw.attached())) ServoYaw.attach(YawPin);
//   if (~(ServoEng.attached())) ServoEng.attach(YawPin);
// }


// void Detach_servos() {
//   //If servo is controlled by Arduino Stop conrolling
//   if (ServoPitch.attached()) {
//     // ServoPitch.write(90);
//     // delay(100);
//     ServoPitch.detach();
//     pinMode(PitchPin, LOW);
//   }

//   if (ServoRoll.attached()) {
//     // ServoRoll.write(90);
//     // delay(100);
//     ServoRoll.detach();
//     pinMode(RollPin, LOW);
//   }

//   if (ServoYaw.attached()) {
//     // ServoYaw.write(90);
//     // delay(100);
//     ServoYaw.detach();
//     pinMode(YawPin, LOW);
//   }
//   if (ServoEng.attached()) {
//     // ServoYaw.write(90);
//     // delay(100);
//     ServoEng.detach();
//     pinMode(EngPin, LOW);
//   }
// }


// volatile uint8_t servoTmrCounter = 0;
// SIGNAL(TIMER0_COMPA_vect) {
//   // this gets called every 2 milliseconds
//   servoTmrCounter += 2;
//   // every 20 milliseconds, refresh the servos!
//   if (servoTmrCounter >= 20) {
//     servoTmrCounter = 0;
//     ServoPitch.refresh();
//     ServoRoll.refresh();
//     ServoYaw.refresh();
//     ServoEng.refresh();
//   }
// }

