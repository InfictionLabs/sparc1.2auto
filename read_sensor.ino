void read_dual_sensors()
{

  lox1.rangingTest(&measure1, false); // pass in 'true' to get debug data printout!
  lox2.rangingTest(&measure2, false); // pass in 'true' to get debug data printout!
  lox3.rangingTest(&measure3, false); // pass in 'true' to get debug data printout!
  lox4.rangingTest(&measure4, false); // pass in 'true' to get debug data printout!
  // print sensor one reading

  /******************************first sensor reading******************************/
  //Serial.print("1: ");
  if (measure1.RangeStatus != 4)
  { // if not out of range
    sensor1 = measure1.RangeMilliMeter;
    //Serial.print(sensor1);
    //Serial.print("mm");
    if (sensor1 >= 70)
    {
      tof1 = 1;
      //Serial.print("tof1=");
      //Serial.print(tof1);
    }
    if (sensor1 < 70)
    {
      tof1 = 0;
      //Serial.print("tof1=");
      //Serial.print(tof1);
    }
  }
  else
  {
    //Serial.print("tof 1 Out of range");
    tof1 = 1;
  }


  /******************************second sensor reading******************************/

  //Serial.print(" ");
  //Serial.print("2: ");
  if (measure2.RangeStatus != 4)
  { // if not out of range
    sensor2 = measure2.RangeMilliMeter;
    //Serial.print(sensor2);
    //Serial.print("mm");
    if (sensor2 >= 70)
    {
      tof2 = 1;
      //Serial.print("tof2=");
      //Serial.print(tof2);
    }
    if (sensor2 < 70)
    {
      tof2 = 0;
      //Serial.print("tof2=");
      //Serial.print(tof2);
    }
  }
  else
  {
    //Serial.print("tof 2 Out of range");
    tof2 = 1;
  }



  /******************************third sensor reading******************************/

  //Serial.print(" ");

  //Serial.print("3: ");
  if (measure3.RangeStatus != 4)
  { // if not out of range
    sensor3 = measure3.RangeMilliMeter;
    //Serial.print(sensor3);
    //Serial.print("mm");
    if (sensor3 >= 70)
    {
      tof3 = 1;
      //Serial.print("tof3=");
      //Serial.print(tof3);
    }
    if (sensor3 < 70)
    {
      tof3 = 0;
      //Serial.print("tof3=");
      //Serial.print(tof3);
    }
  }
  else
  {
    //Serial.print("tof 3 Out of range");
    tof3 = 1;
  }

  /******************************fourth sensor reading******************************/

  //Serial.print(" ");

  //Serial.print("4: ");
  if (measure4.RangeStatus != 4)
  { // if not out of range
    sensor4 = measure4.RangeMilliMeter;
    //Serial.println(sensor4);
    //Serial.println("mm");
    if (sensor4 >= 70)
    {
      tof4 = 1;
      //Serial.print("tof4=");
      //Serial.print(tof4);
    }
    if (sensor4 < 70)
    {
      tof4 = 0;
      //Serial.print("tof4=");
      //Serial.print(tof4);
    }
  }
  else
  {
    //Serial.print("tof 4 Out of range");
    tof4 = 1;
  }

  // Serial.println();

  if (tof1 == 1 && tof2 == 1)
  {
    Serial.println("front sensor stop");
    front_edge = 1;
    delay(100);
  }
  else
  {
    front_edge = 0;
    delay(100);
  }

  if (tof3 == 1 && tof4 == 1)
  {
    Serial.println("back sensor stop");
    back_edge = 1;
  }
  else
  {
    back_edge = 0;
  }


  if (front_edge == 1 && back_edge == 1)
  {
    // motorstop();

    sensor_error = 1;
    Serial.println("bot not on the table");
  }
}
