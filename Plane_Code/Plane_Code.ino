#define Debug 1
#define Radio433Pin 2

//Servo pins
#define PitchPin 10
#define RollPin 5
#define YawPin 9
#define EngPin 11


#include "I2Cdev.h"
#include "Led.h"

#include "PID.h"
//Gyroscope is connected to pins  A4 and A5 relative to SDA and SCL on gyroscope


//-Vals-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
float globalRotationX = 0.0;  // Global X Angle
float globalRotationY = 0.0;  // Global Y Angle
float globalRotationZ = 0.0;  // Global Z Angle
float globalHeight = 0.0;   // Global heiglobalHeightt

float globalAccelerationX = 0.0;  // Global X acceleration
float globalAccelerationY = 0.0;  // Global Y acceleration
float globalAccelerationZ = 0.0;  // Global Z acceleration

float globalAccelerationYError = 0.0;

float targetRotationX = 0.0;  // Target x angle
float targetRotationY = 0.0;  // Target y angle
float targetRotationZ = 0.0;  // Target z angle

//-Coef for the X angle------------------------------------------
float kPX = 2.5;
float kIX = 0.005;
float kDX = 0;

//-Coef for the Y angle------------------------------------------
float kPY = 2;
float kIY = 0;
float kDY = 0;

//-Coef for the Z angle------------------------------------------
float kPZ = 1;
float kIZ = 0;
float kDZ = 0;

float globalSpeed = 0;

static uint32_t tmrM = 0;
static uint32_t tmrSpd = 0;
bool flightFlag = true;
//-Main Setup-----------------------------------------------------------------------------------------------------------------------------------------------------------------

PID Pitch(1, 0, 0, 10);
PID Roll(1, 0, 0, 10);
PID Yaw(1, 0, 0, 10);
PID Engine(1, 0, 0, 10);

void setup() {  
  Serial.begin(115200);  // Setup of main usb port for debug
  delay(4000);
  LedSetup();   //Setup of RGB led strip
  Gyrosetup();  // Setup of Gyroscope
  ServoSetup();    // Setup of Servo
  rxSetup();
  delay(100);
}
long long flightTmr = 0;

void levelOff(){
  getInfo(&globalRotationX, &globalRotationY, &globalRotationZ);
  debugPrint("x:", globalRotationX, " y:", globalRotationY, "z:", globalRotationZ);
  float ux = Pitch.update(globalRotationX, (millis() - flightTmr)/1000);
  float uy = Roll.update(globalRotationY, (millis() - flightTmr)/1000);
  float uz = Yaw.update(globalRotationZ, (millis() - flightTmr)/1000);

  angleWrite(90 - uy, 90 + ux, 90 - uz);
  flightTmr = millis();
}

//-Main code-----------------------------------------------------------------------------------------------------------------------------------------------------------------
uint8_t currentMode = 0;
long long modeTMR  = 0;
void loop() {  
  currentMode = Flight_mode();
  // levelOff();
  switch (currentMode){
    case 0:
      manualFlight();
    break;
    case 1:
      levelOff();
      break;
  };
}