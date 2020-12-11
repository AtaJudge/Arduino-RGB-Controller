int rVal = 254;
int gVal = 1;
int bVal = 127;

int rDir = -1;
int gDir = 1;
int bDir = -1;

int fdspd;
int vR;
int vG;
int vB;
boolean mod = 0;
int vLDR;

#define rPin 11
#define gPin 10
#define bPin 9

#define potR A0
#define potG A1
#define potB A2
#define potF A3

#define LDR A4
#define btn 2


void setup()
{
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(potR, INPUT);
  pinMode(potG, INPUT);
  pinMode(potB, INPUT);
  pinMode(potF, INPUT);
  pinMode(LDR, INPUT);
  pinMode(btn, INPUT);
}
void loop()
{
  fdspd == analogRead(potF);
  map(fdspd,0,1023,0,150);
  vLDR == analogRead(LDR);

  if(HIGH == digitalRead(btn))
  {
    mod = !mod;
  }

  if(mod == 0 || LDR <= 100)
  {
    fade();
  }
  else if(mod == 1 || LDR >= 600)
  {
    man();
  }

  
}
 
