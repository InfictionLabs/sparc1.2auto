//libraries initialization//

  #include "Adafruit_VL53L0X.h"
  #include "Wire.h"
  #include <MPU6050_light.h>
  
  //timer object//
  MPU6050 mpu(Wire);
unsigned long timer = 0;


// variables for motor's position encoder//
int encoderPin1 = 2;//left
int encoderPin2 = 3;//left
int encoderPin3 = 18;//right
int encoderPin4 = 19;//right

//motor driver variables//
int m1 = 4; //left motor
int dir1 = 5;//left motor
int m2 = 13;//right motor
int dir2 = 25;//right motor

//int pin = 25;
int startpin = 35;
//initialize tof sensors//
#include "Adafruit_VL53L0X.h"

// address we will assign if dual sensor is present
#define LOX1_ADDRESS 0x30
#define LOX2_ADDRESS 0x31
#define LOX3_ADDRESS 0x32
#define LOX4_ADDRESS 0x32
int sensor1, sensor2, sensor3, sensor4;

int tof1 = 0;
int tof2 = 0;
int tof3 = 0;
int tof4 = 0;


// set the pins to shutdown or select the tof sensors
#define SHT_LOX1 6
#define SHT_LOX2 7
#define SHT_LOX3 10
#define SHT_LOX4 9

// objects for the vl53l0x
Adafruit_VL53L0X lox1 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox2 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox3 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox4 = Adafruit_VL53L0X();

// this holds the measurement
VL53L0X_RangingMeasurementData_t measure1;
VL53L0X_RangingMeasurementData_t measure2;
VL53L0X_RangingMeasurementData_t measure3;
VL53L0X_RangingMeasurementData_t measure4;

/*
    Reset all sensors by setting all of their XSHUT pins low for delay(10), then set all XSHUT high to bring out of reset
    Keep sensor #1 awake by keeping XSHUT pin high
    Put all other sensors into shutdown by pulling XSHUT pins low
    Initialize sensor #1 with lox.begin(new_i2c_address) Pick any number but 0x29 and it must be under 0x7F. Going with 0x30 to 0x3F is probably OK.
    Keep sensor #1 awake, and now bring sensor #2 out of reset by setting its XSHUT pin high.
    Initialize sensor #2 with lox.begin(new_i2c_address) Pick any number but 0x29 and whatever you set the first sensor to
*/

// other flags and variables//
int z = 0;
int front_edge = 0;
int back_edge = 0;
int sensor_error = 0;
int iniz = 0;


//for encoders...
int error = 10590;

long nor = 1;
volatile long lastEncoded1 = 0;
volatile long encoderValue1 = 0;
long lastencoderValue1 = 0;

int lastMSB1 = 0;
int lastLSB1 = 0;

volatile long lastEncoded2 = 0;
volatile long encoderValue2 = 0;
long lastencoderValue2 = 0;

int lastMSB2 = 0;
int lastLSB2 = 0;

int protoselect=26;

void loop()
{
  
  if(digitalRead(startpin)== LOW)
  {
  main_function();  
  }

  else
  {
  while(1)
  {
    bailout:
    Serial.println("waiting for auto to start");
    delay(100);
   if(digitalRead(startpin)== LOW)
   break; 
  }
  }
}
