#include <Mouse.h>
void setup() {
  Serial.begin(9600);

  // lWin
  pinMode(0, INPUT_PULLUP);
  // lCtrl
  pinMode(1, INPUT_PULLUP);
  // lAlt
  pinMode(2, INPUT_PULLUP);

  //rWin
  pinMode(3, INPUT_PULLUP);
  // rCtrl
  pinMode(4, INPUT_PULLUP);
  // rAlt
  pinMode(5, INPUT_PULLUP);

  // F1
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
}

void loop() {

  int lShift = !digitalRead(0);
  int lCtrl = !digitalRead(1);
  int lAlt = !digitalRead(2);


  int rShift = !digitalRead(3);
  int rCtrl = !digitalRead(4);
  int rAlt = !digitalRead(5);

  int buttonF2 = !digitalRead(6);
  int buttonF3 = !digitalRead(7);
  int buttonF4 = !digitalRead(8);
  int buttonF5 = !digitalRead(9);
  int buttonF6 = !digitalRead(10);
  int buttonF7 = !digitalRead(11);
  int buttonF9 = !digitalRead(12);
  int buttonF11 = !digitalRead(17);
  int buttonMap = !digitalRead(15);
  int buttonView = !digitalRead(16);


  int mouseScroll = analogRead(0);
  int potiMiddle = 51;
  int potiDeadZone = 5;
  int buttonPressDelay = 200;
  mouseScroll = round(mouseScroll / 10) - potiMiddle;
  
  Serial.print("lShift ");
  Serial.println(lShift);

  Serial.print("lCtrl ");
  Serial.println(lCtrl);

  Serial.print("lAlt ");
  Serial.println(lAlt);


  Serial.print("rShift ");
  Serial.println(rShift);

  Serial.print("rCtrl ");
  Serial.println(rCtrl);

  Serial.print("rAlt ");
  Serial.println(rAlt);


  Serial.print("mouseScroll ");
  Serial.println(mouseScroll);

  if (mouseScroll > 0 and mouseScroll <= potiDeadZone) {
    mouseScroll = 0;
  }

  if (mouseScroll < 0 and mouseScroll >= -potiDeadZone) {
    mouseScroll = 0;
  }

  Mouse.scroll(mouseScroll/5);

  Serial.print("mouseScroll ");
  Serial.println(mouseScroll);


  if (lShift > 0) {
    Keyboard.set_modifier(MODIFIERKEY_SHIFT);
  } else if (lCtrl > 0) {
    Keyboard.set_modifier(MODIFIERKEY_CTRL);
  } else if (lAlt > 0) {
    Keyboard.set_modifier(MODIFIERKEY_ALT);
  } else if (rShift > 0) {
    Keyboard.set_modifier(MODIFIERKEY_RIGHT_SHIFT);
  } else if (rCtrl > 0) {
    Keyboard.set_modifier(MODIFIERKEY_RIGHT_CTRL);
  } else if (rAlt > 0) {
    Keyboard.set_modifier(MODIFIERKEY_RIGHT_ALT);
  } else {
    Keyboard.set_modifier(0);
  }


  if (buttonF2 > 0) {
    Keyboard.press(KEY_F2);
    Keyboard.release(KEY_F2);
    delay(buttonPressDelay);
  }

  if (buttonF3 > 0) {
    Keyboard.press(KEY_F3);
    Keyboard.release(KEY_F3);
    delay(buttonPressDelay);
  }

  if (buttonF4 > 0) {
    Keyboard.press(KEY_F4);
    Keyboard.release(KEY_F4);
    delay(buttonPressDelay);
  }

  if (buttonF5 > 0) {
    Keyboard.press(KEY_F5);
    Keyboard.release(KEY_F5);
    delay(buttonPressDelay);
  }

  if (buttonF6 > 0) {
    Keyboard.press(KEY_F6);
    Keyboard.release(KEY_F6);
    delay(buttonPressDelay);
  }

  if (buttonF7 > 0) {
    Keyboard.press(KEY_F7);
    Keyboard.release(KEY_F7);
    delay(buttonPressDelay);
  }

  if (buttonF9 > 0) {
    Keyboard.press(KEY_F9);
    Keyboard.release(KEY_F9);
    delay(buttonPressDelay);
  }

  if (buttonF11 > 0) {
    Keyboard.press(KEY_F11);
    Keyboard.release(KEY_F11);
    delay(buttonPressDelay);
  }

  if (buttonMap > 0) {
    Keyboard.press(KEY_F10);
    Keyboard.release(KEY_F10);
    delay(buttonPressDelay);
  }

  if (buttonView > 0) {
    Keyboard.press(KEY_F1);
    Keyboard.release(KEY_F1);
    delay(buttonPressDelay);
  }



  Serial.print("F2 ");
  Serial.println(buttonF2);
  Serial.print("F3 ");
  Serial.println(buttonF3);
  Serial.print("F4 ");
  Serial.println(buttonF4);
  Serial.print("F5 ");
  Serial.println(buttonF5);
  Serial.print("F6 ");
  Serial.println(buttonF6);
  Serial.print("F7 ");
  Serial.println(buttonF7);
  Serial.print("F9 ");
  Serial.println(buttonF9);
  Serial.print("F11 ");
  Serial.println(buttonF11);


  Serial.print("F10 ");
  Serial.println(buttonMap);
  Serial.print("F1 ");
  Serial.println(buttonView);

  // if (buttonF1 > 0) {
  //   Serial.print("F1");
  //   //Serial.println(buttonF1);
  //   //Keyboard.set_key1(KEY_F1);
  // }


  Keyboard.send_now();
  // Keyboard.set_modifier(0);
  // To press just one modifier is simple.

  // Keyboard.set_modifier(MODIFIERKEY_SHIFT);



  // Joystick.button(2, switchUp);



  // Serial.print("switchUp ");
  // Serial.println(switchUp);

  // digitalWrite(6, pressedFive);

  //Joystick.button(2, !pressedOne && !pressedTwo);
  //Joystick.button(3, pressedOne && !pressedTwo);
  //Joystick.button(4, !pressedOne && pressedTwo);

  //if (!pressedOne && !pressedTwo) {
  //  Serial.println("Toggle OFF");
  //} else if (pressedOne && !pressedTwo) {
  //  Serial.println("Toggle UP");
  //} else if (!pressedOne && pressedTwo) {
  //  Serial.println("Toggle DOWN");
  //}

  delay(50);
}
