void man()
{
  vR == analogRead(potR);
  vG == analogRead(potG);
  vB == analogRead(potB);

  digitalWrite(rPin, vR);
  digitalWrite(gPin, vG);
  digitalWrite(bPin, vB);
}
