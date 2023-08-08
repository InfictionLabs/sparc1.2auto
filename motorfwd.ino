void motorfwd()
{
    Serial.println("motorfwd");

  analogWrite(m1, 60);
  digitalWrite(dir1, LOW);

  analogWrite(m2, 60);
  digitalWrite(dir2, LOW);
  delay(10);
}
