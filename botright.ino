void botright()
{
  Serial.println("right");
  analogWrite(m1, 50);
  digitalWrite(dir1, LOW);

  analogWrite(m2, 50);
  digitalWrite(dir2, HIGH);
}
