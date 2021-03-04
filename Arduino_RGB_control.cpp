#define rPin 9
#define gPin 10
#define bPin 11
#define rPot A1
#define gPot A2
#define bPot A3
#define potSpd A4
#define modeBtn 2
bool LightMode = 1;
int FadeSpeedVal;
int rVal;
int gVal;
int bVal;
int rDir = -1;
int gDir = 1;
int bDir = -1;
float rad;
int r, g, b, i, sinOut;
void setup()
{
  Serial.begin(9600);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(rPot, INPUT);
  pinMode(gPot, INPUT);
  pinMode(bPot, INPUT);
  pinMode(potSpd, INPUT);
  pinMode(modeBtn, INPUT);
}
void loop() 
{
  fadeMode();
}
void CheckFadeSpeed()
{
  FadeSpeedVal = analogRead(potSpd);
  FadeSpeedVal = map(FadeSpeedVal, 0, 1023, 10, 100);
}
void CheckLightMode()
{
  if (digitalRead(modeBtn) == HIGH) {
    LightMode = !LightMode;
    
  }
}
void fadeMode()
{
   analogWrite(rPin, 255);
  analogWrite(bPin, 255);
  analogWrite(gPin, 255);
  for (i = 90; i <= 270; i++)
  {
    CheckLightMode();
    if (LightMode == 0)
      break;
    CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(gPin, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 90; i <= 270; i++)
  {
    CheckLightMode();
    if (LightMode == 0)
      break;
    CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(bPin, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 270; i >= 90; i--)
  {
    CheckLightMode();
    if (LightMode == 0)
      break;
    CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(gPin, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 90; i <= 270; i++)
  {
    CheckLightMode();
    if (LightMode == 0)
      break;
    CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(rPin, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 270; i >= 90; i--)
  {
    CheckLightMode();
    if (LightMode == 0)
      break;
    CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(bPin, sinOut);
    delay(FadeSpeedVal);
  }
  for (i = 90; i <= 270; i++)
  {
    CheckLightMode();
    if (LightMode == 0)
      break;
    CheckFadeSpeed();
    rad = DEG_TO_RAD * i;
    sinOut = constrain((sin(rad) * 128) + 128, 0, 255);
    analogWrite(gPin, sinOut);
    delay(FadeSpeedVal);
  }
 
}
void manualMode()
{
  CheckLightMode();
  Serial.println ("Manuel Mod");
}
