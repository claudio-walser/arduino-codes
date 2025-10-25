#include "USB.h"
#include "USBHIDMouse.h"
#include "USBHIDKeyboard.h"


USBHIDMouse Mouse;
USBHIDKeyboard Keyboard;


const int buttonPin = 2;

bool oldActive = false;
bool active = false;
// bool up = true;
// int8_t move;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  USB.begin();
  Mouse.begin();
}

void forge() {
  
  // if (up) {
  //   move = -400;
  //   up = false;
  // } else {
  //   move = 400;
  //   up = true;
  // }
  // for (int i = 1; i <= 8; i++) {
  Mouse.press(MOUSE_LEFT);
  delay(1000);
  Mouse.release(MOUSE_LEFT);
  //delay(300);

  // Mouse.move(move, 0);
  // delay(100);
  //}

  // delay(300);
  // Keyboard.press('f');
  // delay(100);
  
  // Keyboard.release('f');
  // delay(100);
}

void resetStats() {
  // up = true;
}

void loop() {
  oldActive = active;
  active = digitalRead(buttonPin) == LOW;

  if (active != oldActive) {
    resetStats();
  }

  if (active) {
    forge();
  }
  delay(300);
}
