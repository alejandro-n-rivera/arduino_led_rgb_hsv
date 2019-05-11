# Arduino LED strip control with RGB and HSV

Allows for setting colors using the RGB color space ([0..255], [0..255], [0..255]) \
and the HSV (a.k.a. HSB) color space ([0..359], [0.00..1.00], [0.00..1.00])

The HSV color space is useful for controlling LED brightness (V) apart from hue (H) and saturation (S).

This program includes definitions for color names (based on my own 5V RGB LED strips, YMMV).

Functions include:\
**setLEDRGB(r,g,b):** Sets LED colors based on RGB values \
**setLEDHSV(h,s,v):** Sets LED colors based on HSV values \
**blinkHSV():** Displays six main HSV colors with a 1 second delay \
**cycleHSV():** Smoothly cycles through HSV color space \
**setLEDColor(color):** Allows setting LED color to: OFF, RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, CYAN, PINK, or WHITE \
**testColors():** Tests all the color names (OFF, RED, etc.)

Below is the wiring diagram (made with [Fritzing](http://fritzing.org/)) for the Arduino - LED strip connection. \
I used three [ZVN3310A](https://www.diodes.com/assets/Datasheets/ZVN3310A.pdf) N-channel MOSFETs, however many general-purpose transistors should work. In my case, the pin arrangement (according to the ZVN3310A doc linked above) was: \
**D:** [R, G, or B on the LED strip] \
**G:** [Pin 3, 5, or 6 on the Arduino] \
**S:** GND on the Arduino

You may have to reference the documentation for the pinout of your own transistors as it may differ from mine.

![Wiring diagram](https://github.com/alejandro-n-rivera/arduino_led_rgb_hsv/blob/master/wiring_diagram.png)

Feel free to use (at your own risk), modify, and share.
