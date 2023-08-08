
//turn left and come back
void itr4()
{

  encoderValue1 = 0;
  encoderValue2 = 0;

  delay(100);
  while (1) // ((encoderValue1 >= 0 && encoderValue1 < 5863) && (encoderValue2 >= 0 && encoderValue2 < 5863)) // move 72cm forward
  {
 if(digitalRead(startpin)== HIGH)
     {
      motorstop();
      delay(200);
      temp();
     }
    Serial.println("Iteration 4  ");
    Serial.print(encoderValue1);
    Serial.print("\t");


    Serial.println(encoderValue2);
    botright();
    delay(10);

    if ((encoderValue1 > 3500) && (encoderValue2 > 3500))
    {
      motorstop();

      Serial.print("IF STATEMENT of itr4");
      //error= encoderValue1-10;
      delay(3000);
      while (1)
      {
        if (digitalRead(protoselect) == HIGH)
          protocol_a();
        if (digitalRead(protoselect) == LOW)
        {
          encoderValue1 = 0;
          encoderValue2 = 0;
          while (1)
         {
//            motorback();
//            if ((encoderValue1 < -4500) && (encoderValue2 > 4500))
//            {
//              motorstop();
//              delay(1000);
              protocol_d();
          }
//          }
        }
      }
    }
  }
  //      //encoderValue1 = 3;
  //      //encoderValue2 = -3;
  //
}
