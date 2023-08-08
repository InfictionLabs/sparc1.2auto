
//this function reads the sensors and gets the data from accelecerometer
//and calibrates it to zero position and calls protocol a.
void main_function()
{
  // setID();
  Serial.println("entering main function");
  delay(1000);
  read_dual_sensors();
  //delay(100);
//while(1)
//{
//  temp();
//}
  for (int i = 0; i < 10; i++)
  {
    mpu.update();
  }
  iniz = mpu.getAngleZ();
  Serial.print("iniz=");
  Serial.println(mpu.getAngleZ());
  delay(1000);

  while (1)
  {
    
     if(digitalRead(startpin)== HIGH)
     {
      motorstop();
      delay(200);
      temp();
     }
    //   read_dual_sensors();
    //delay(100);

    mpu.update();
    delay(100);
    Serial.print("\tZ : ");
    Serial.println(mpu.getAngleZ());
    //      timer = millis();
    z = mpu.getAngleZ();
    //
    //
    read_dual_sensors();
    delay(1000);
    if (sensor_error == 1)
    {
      motorstop();
      while (1)
      {
        Serial.println("bot not on table");
         //read_dual_sensors();
        delay(5000);
        
      }
    }
    if (sensor_error == 0)
    {
      while (1)
      {
         if(digitalRead(startpin)== HIGH)
     {
      motorstop();
      delay(200);
      temp();
     }
        //Serial.print("protocol_a:    ");
        if(digitalRead(protoselect)==HIGH)
        protocol_a();
        if(digitalRead(protoselect)==LOW)
        protocol_d();

      }
    }

  }
}
