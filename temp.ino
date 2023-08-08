void temp()
{
  while(1)
  {
    bailout:
    Serial.println("waiting for auto to start");
    delay(100);
   if(digitalRead(startpin)== LOW)
   main_function(); 
  }
}
