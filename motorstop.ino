void motorstop()
{
  analogWrite(m1, 0);
  digitalWrite(dir1, LOW);

  analogWrite(m2, 0);
  digitalWrite(dir2, LOW);
  Serial.println("motorstop");
}
