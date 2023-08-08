void setup()
{

//  pinMode(m1, OUTPUT);
//  pinMode(dir1, OUTPUT);
//  pinMode(m2, OUTPUT);
//  pinMode(dir2, OUTPUT);
//  digitalWrite(dir2,LOW);

  Serial.begin(115200);

  Wire.begin();

  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  //while (status != 0)
  {
  } // stop everything if could not connect to MPU6050
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");

  // wait until serial port opens for native USB devices
  //  while (! Serial) {
  //    delay(1);
  //  }


  pinMode(SHT_LOX1, OUTPUT);
  pinMode(SHT_LOX2, OUTPUT);
  pinMode(SHT_LOX3, OUTPUT);
  pinMode(SHT_LOX4, OUTPUT);

  Serial.println("Shutdown pins inited...");

  digitalWrite(SHT_LOX1, LOW);
  digitalWrite(SHT_LOX2, LOW);
  digitalWrite(SHT_LOX3, LOW);
  digitalWrite(SHT_LOX4, LOW);

  Serial.println("Both in reset mode...(pins are low)");


  Serial.println("Starting...");
  setID();

  delay(1000);
//pinMode(pin,OUTPUT);
//digitalWrite(pin,LOW);

  pinMode(encoderPin1, INPUT_PULLUP);
  pinMode(encoderPin2, INPUT_PULLUP);
  pinMode(encoderPin3, INPUT_PULLUP);
  pinMode(encoderPin4, INPUT_PULLUP);

    pinMode(m1, OUTPUT);
    pinMode(dir1, OUTPUT);
    pinMode(m2, OUTPUT);
    pinMode(dir2, OUTPUT);
    pinMode(protoselect,INPUT);
pinMode(startpin,INPUT_PULLUP);
    digitalWrite(protoselect,LOW);

//  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
//  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on
//  digitalWrite(encoderPin3, HIGH); //turn pullup resistor on
//  digitalWrite(encoderPin4, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3)
  attachInterrupt(digitalPinToInterrupt(encoderPin1), updateEncoder1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPin2), updateEncoder1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPin3), updateEncoder2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPin4), updateEncoder2, CHANGE);
  delay(2000);
}
