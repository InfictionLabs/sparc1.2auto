void botleft()
{
  Serial.println("left");
  analogWrite(m1, 50);
  digitalWrite(dir1, HIGH);

  analogWrite(m2, 50);
  digitalWrite(dir2, LOW);
}
