/* GitHub: alejandro-n-rivera */
// By default uses first three PWM (~) pins on the Arduino Uno
#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6

// Color names supported: (e.g., setLEDColor(RED);)
#define OFF 0
#define RED 1
#define ORANGE 2
#define YELLOW 3
#define GREEN 4
#define BLUE 5
#define PURPLE 6
#define CYAN 7
#define PINK 8
#define WHITE 9


// Red, Green, Blue ranges: R: [0, 255], G: [0, 255], B: [0, 255] (e.g., setLEDRGB(255, 125, 0);)
// Hue, Saturation, Value (Brightness) ranges: H: [0, 359], S: [0.00, 1.00], V: [0.00, 1.00] (e.g., setLEDHSV(270, 0.50, 1.00);)

void setup()
{
  // Arduino reference docs: "You do not need to call pinMode() to set the pin as an output before calling analogWrite()."
  // So, uh, I guess there really isn't anything else to setup...
}

void loop()
{
  HSVBlink();
  HSVCycle();
  testColors();
  goGators();

}

void setLEDRGB(byte r, byte g, byte b)
{
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

void setLEDHSV(int h, float s, float v)
{
  /* Formula used (Alternative): https://en.wikipedia.org/wiki/HSL_and_HSV#HSV_to_RGB */
  
  float r, g, b;

  // Convert HSV to RGB using Alternative Wikipedia formula
  r = v - (v * s * max(min(fmod(5.0+(h/60.0), 6.0), min(4.0 - (fmod(5.0+(h/60.0), 6.0)), 1.0)), 0.0));
  g = v - (v * s * max(min(fmod(3.0+(h/60.0), 6.0), min(4.0 - (fmod(3.0+(h/60.0), 6.0)), 1.0)), 0.0));
  b = v - (v * s * max(min(fmod(1.0+(h/60.0), 6.0), min(4.0 - (fmod(1.0+(h/60.0), 6.0)), 1.0)), 0.0));

  setLEDRGB(r * 255, g * 255, b * 255); // Multiply RGB by 255 to convert to byte values
}

void HSVBlink()
{
  // Jumps to the six main HSV colors
  // Set Hue to: 0, 60, 120, 180, 240, 300
  for(int i = 0; i < 6; i++)
  {
    setLEDHSV(i*60, 1.00, 1.00);
    delay(1000);
  }
}

void HSVCycle()
{
  // Cycle through all the Hues [0..359] at full Saturation and Brightness
  for(int i = 0; i < 360; i++)
  {
    setLEDHSV(i, 1.00, 1.00); // Set LED Hue, Saturation, and Brightness (Value)
    delay(25);
  }
}

void setLEDColor(int color)
{
  // Set LED color by name (HSV versions of same color in comments)
  switch(color)
  {
    case OFF:
      setLEDRGB(0, 0, 0);
      // setLEDHSV(0, 0.00, 0.00);
      break;
    case RED:
      setLEDRGB(255, 0, 0);
      // setLEDHSV(0, 1.00, 1.00);
      break;
    case ORANGE:
      setLEDRGB(255, 25, 0);
      // setLEDHSV(6, 1.00, 1.00);
      break;
    case YELLOW:
      setLEDRGB(255, 250, 0);
      // setLEDHSV(59, 1.00, 1.00);
      break;
    case GREEN:
      setLEDRGB(0, 255, 0);
      // setLEDHSV(120, 1.00, 1.00);
      break;
    case BLUE:
      setLEDRGB(0, 0, 255);
      // setLEDHSV(240, 1.00, 1.00);
      break;
    case PURPLE:
      setLEDRGB(255, 0, 255);
      // setLEDHSV(300, 1.00, 1.00);
      break;
    case CYAN:
      setLEDRGB(0, 255, 255);
      // setLEDHSV(180, 1.00, 1.00);
      break;
    case PINK:
      setLEDRGB(255, 0, 144);
      // setLEDHSV(326, 1.00, 1.00);
      break;
    case WHITE:
      setLEDRGB(255, 255, 255);
      // setLEDHSV(0, 0.00, 1.00);
      break;
  }
}

void testColors()
{
  setLEDColor(RED);
  delay(1000);
  setLEDColor(ORANGE);
  delay(1000);
  setLEDColor(YELLOW);
  delay(1000);
  setLEDColor(GREEN);
  delay(1000);
  setLEDColor(BLUE);
  delay(1000);
  setLEDColor(PURPLE);
  delay(1000);
  setLEDColor(CYAN);
  delay(1000);
  setLEDColor(PINK);
  delay(1000);
  setLEDColor(WHITE);
  delay(1000);
  setLEDColor(OFF);
  delay(1000);
}

void goGators()
{
  setLEDColor(ORANGE);
  delay(1000);
  setLEDColor(BLUE);
  delay(1000);
}
