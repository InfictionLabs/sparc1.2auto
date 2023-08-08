
//turn right for moving to next table
void itr2()
{
  //while(1)
  {
    Serial.println("itr2");
    delay(100);
  }
  
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
    Serial.print("Iteration 2  ");
    Serial.print(encoderValue1);
    Serial.print("\t");
    

    Serial.println(encoderValue2);
    botleft();
    delay(10);

    if ((encoderValue1 < -3500) && (encoderValue2 < -3500))
    {
      motorstop();
      
     Serial.print("IF STATEMENT of itr2");
      //error= encoderValue1-10;
      delay(3000);
      while (1)
      {
        itr3();
      }
//      //encoderValue1 = 3;
//      //encoderValue2 = -3;
//
  }
}
}
