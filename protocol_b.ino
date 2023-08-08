void protocol_b()
{


  while (1)
  {
    Serial.print("protocol b:     ");
    read_dual_sensors();
    delay(100);

    //
    //    //read_dual_sensors();
    //    //delay(100);
    mpu.update();
    //    if ((millis() - timer) > 10) { // print data every 10ms
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

    //    }
    while (z > (3 + iniz) ) //left
    {
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
        botright();
        //motorstop();

      }
    }

    while (z < (iniz - 3) ) //right
    {
      mpu.update();
      if ((millis() - timer) > 10)
      {
        /*Serial.print("\tX : ");
          Serial.print(mpu.getAngleX());
          Serial.print("\tY : ");
          Serial.print(mpu.getAngleY());*/
        Serial.println("right");
        // Serial.println(mpu.getAngleZ());
        timer = millis();
        z = mpu.getAngleZ();

        botleft();
      }
    }
    motorback();

    if (back_edge == 1)
    {
      motorstop();
      delay(100);
      protocol_c();
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
