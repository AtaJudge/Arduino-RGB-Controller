void fade() {
  analogWrite(rPin, rVal);
  analogWrite(gPin, gVal);

  rVal = rVal + rDir;
  gVal = gVal + gDir;
  bVal = bVal + bDir;

  if (rVal >= 255 || rVal <= 0) {
    rDir = rDir * -1;
  }

  if (gVal >= 255 || gVal <= 0) {
    gDir = gDir * -1;
  }

  if (bVal >= 255 || bVal <= 0) {
    bDir = bDir * -1;
  }

  delay(fdspd);
}
