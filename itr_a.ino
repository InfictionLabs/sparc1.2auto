//move same distance back

void itr_a()
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
    Serial.print("itr_a:     ");
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
//        botright();
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
//        botleft();
//        delay(100);
//      }
//    }
    motorback();
    Serial.print("e1=");
     Serial.print(encoderValue1);
     Serial.print("   e2=");
     Serial.println(encoderValue2);

 if (((encoderValue1 < -15000) && (encoderValue2 > 15000))||(back_edge == 1))//back
    {
      motorstop();
      read_dual_sensors();
    delay(100);
     Serial.print("IF STATEMENT");
      //error= encoderValue1-10;
      delay(3000);
     if(back_edge == 1)
      {
        motorfwd();
      }
      Serial.print("IF STATEMENT");
      //error= encoderValue1-10;
      delay(3000);
      while (back_edge != 1)
      {
        itr1();
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
