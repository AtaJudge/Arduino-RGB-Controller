#define BTN 8  // Button pin for mode selection.

// Connections for RGB LED.
#define RED 9   // Pinout for red.
#define BLU 10  // Pinout for blue.
#define GRN 11  // Pinout for green.

// Connections for potentiometers.
#define POTSPD A0  // Pinout for the speed setting potentiometer.
#define POTRED A1  // Pinout for the potentiometer controls red LED.
#define POTBLU A2  // Pinout for the potentiometer controls blue LED.
#define POTGRN A3  // Pinout for the potentiometer controls green LED.


//Function prototypes:
void fadeMode(int *, int *, int *, int);
void manualMode(int *, int *, int *);
void checkMode(int *);
void fadeSpeed(int *);

void setup(){
  Serial.begin(9600);
}

int main() {
  int red_val, green_val, blue_val;
  int speed_val = 10;
  int mode_val=0;

  

  while (speed_val >= 0) { 
    while (mode_val == 0) {
      // Manual mode.
      manualMode(&red_val, &green_val, &blue_val);
      checkMode(&mode_val);
    }

    while (mode_val == 1) {
      // Manual mode.
      fadeSpeed(&speed_val);
      checkMode(&mode_val);
      fadeMode(&red_val, &green_val, &blue_val, &speed_val);
    }
  }
}


// Fade mode sets the colors of the LED's in a shape of sin wave.
void fadeMode(int *red_val, int *green_val, int *blue_val, int speed) {
}


// Allows user to control color's brightness with potentiometers.
void manualMode(int *red_val, int *green_val, int *blue_val) {
  int r, g, b;  // Potentiometer readings for RGB.

  r = analogRead(POTRED);
  g = analogRead(POTGRN);
  b = analogRead(POTBLU);

  *red_val = map(r, 0, 1023, 0, 255);
  *green_val = map(g, 0, 1023, 0, 255);
  *blue_val = map(b, 0, 1023, 0, 255);

  digitalWrite(RED, *red_val);
  digitalWrite(GRN, *green_val);
  digitalWrite(BLU, *blue_val);
}


// Checks if the mode is changed or not.
void checkMode(int *mode) {
  if (digitalRead(BTN) == 0) {
    switch (*mode) {  // Change the mode when the button is pressed.
      case 0:
        *mode = 1;
        break;
      case 1:
        *mode = 0;
        break;
    }
    printf("New mode is: %d", *mode);
    while (digitalRead(BTN))
      ;  // Waits until button is released comletely to prevent debouncing.
  }
}


// Checks the speed of the color change in the fade mode.
void fadeSpeed(int *speed) {
  *speed = analogRead(POTSPD);
  *speed = map(*speed, 0, 1023, 0, 50);  // Map the 0-1023 analog input as 0-50ms.
}