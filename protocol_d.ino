
//autonomous starts with protocol d for encoder movements only//

//move forward

void protocol_d()
{
  encoderValue1 = 0;
  encoderValue2 = 0;
  while (1)
  {
     if(digitalRead(startpin)== HIGH)
     {
      motorstop();
      delay(200);
      temp();
     }
    Serial.print("protocol d:     ");
    read_dual_sensors();
    delay(100);


    mpu.update();
    if ((millis() - timer) > 10)
    {
      Serial.print("\tZ : ");
      Serial.println(mpu.getAngleZ());

      z = mpu.getAngleZ();

    }
    //    while (z > (3 + iniz) ) //left
    //    {
    //      mpu.update();
    //      if ((millis() - timer) > 10)
    //      { // print data every 10ms
    //
    //        Serial.println("left");
    //
    //        timer = millis();
    //        z = mpu.getAngleZ();
    //        botleft();
    //
    //
    //      }
    //    }
    //
    //    while (z < (iniz - 3) ) //right
    //    {
    //      mpu.update();
    //      if ((millis() - timer) > 10)
    //      {
    //
    //        timer = millis();
    //        z = mpu.getAngleZ();
    //
    //        botright();
    //        delay(100);
    //      }
    //    }
    motorfwd();

    Serial.print("e1=");
    Serial.print(encoderValue1);
    Serial.print("   e2=");
    Serial.println(encoderValue2);

    if (((encoderValue1 >= 15000) && (encoderValue2 < -15000))||(front_edge == 1))//fwd
    {
      motorstop();
      read_dual_sensors();
    delay(100);
      if(front_edge == 1)
      {
        motorback();
      }
      Serial.print("IF STATEMENT");
      //error= encoderValue1-10;
      delay(3000);
      while (front_edge != 1)
      {
        itr_a();
      }
    }

    if (front_edge == 1)
    {
      Serial.println("front sensor detected");
      motorstop();
      delay(1000);
      while (1)
      {
        itr_a();
      }

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
