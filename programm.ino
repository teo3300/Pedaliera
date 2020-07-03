#include "Key.h"

Key left   = Key(2, MACRO, 'z', 1, KEY_LEFT_CTRL);
Key center = Key(6, MACRO, 'c', 1, KEY_LEFT_CTRL);
Key right  = Key(9, MACRO, 'v', 1, KEY_LEFT_CTRL);

void setup(){
  Keyboard.begin();
}

void loop(){
  left.poll();
  center.poll();
  right.poll();
  delay(50);
}
