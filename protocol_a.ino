void protocol_a()
{
  while (1)
  {
     if(digitalRead(startpin)== HIGH)
     {
      motorstop();
      delay(200);
      temp();
     }
    Serial.print("protocol a:     ");
    read_dual_sensors();
    delay(100);

    //
    //    //read_dual_sensors();
    //    //delay(100);
    mpu.update();
       if ((millis() - timer) > 10)
       { // print data every 10ms
    //      /*Serial.print("\tX : ");
    //        Serial.print(mpu.getAngleX());
    //        Serial.print("\tY : ");
    //        Serial.print(mpu.getAngleY());*/
    Serial.print("\tZ : ");
    Serial.println(mpu.getAngleZ());
    //      timer = millis();
    z = mpu.getAngleZ();
    //
    //

        }
    while (z > (3 + iniz) ) //left
    {
       if(digitalRead(startpin)== HIGH)
     {
      motorstop();
      delay(200);
      temp();
     }
      mpu.update();
      if ((millis() - timer) > 10)
      { // print data every 10ms
        /*Serial.print("\tX : ");
          Serial.print(mpu.getAngleX());
          Serial.print("\tY : ");
          Serial.print(mpu.getAngleY());*/
        Serial.println("left");
        // Serial.println(mpu.getAngleZ());
        timer = millis();
        z = mpu.getAngleZ();
        botleft();
        //motorstop();

      }
    }

    while (z < (iniz - 3) ) //right
    {
       if(digitalRead(startpin)== HIGH)
     {
      motorstop();
      delay(200);
      temp();
     }
      mpu.update();
      if ((millis() - timer) > 10)
      {
        /*Serial.print("\tX : ");
          Serial.print(mpu.getAngleX());
          Serial.print("\tY : ");
          Serial.print(mpu.getAngleY());*/
        
        // Serial.println(mpu.getAngleZ());
        timer = millis();
        z = mpu.getAngleZ();

        botright();
        delay(100);
      }
    }
    motorfwd();

    if (front_edge == 1)
    {
      motorstop();
      delay(1000);
      protocol_b();
      //break;
    }
    if (sensor_error == 1)
    {

      while (1)
      {
        motorstop();
        Serial.println("bot not on table");
      }
    }
  }
}
