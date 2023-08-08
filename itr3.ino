//move forward
void itr3()
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
    Serial.println("Iteration 3  ");
    Serial.print(encoderValue1);
    Serial.print("\t");
   

    Serial.println(encoderValue2);
    motorfwd();
    delay(10);

    if ((encoderValue1 >= 4500) && (encoderValue2 < -4500))
    {
      motorstop();
      
     Serial.print("IF STATEMENT of itr3 ");
      //error= encoderValue1-10;
      delay(3000);
      while (1)
      {
        itr4();
      }
//      //encoderValue1 = 3;
//      //encoderValue2 = -3;
//
  }
}
}
