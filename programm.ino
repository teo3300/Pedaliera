#include "Key.h"

Key left   = Key(2, KEY_UP_ARROW, HOLD);
Key center = Key(6, KEY_RIGHT_SHIFT, PRESS);
Key right  = Key(9, KEY_DOWN_ARROW, HOLD);

void setup(){
  Keyboard.begin();
}

void loop(){
  left.poll();
  center.poll();
  right.poll();
  delay(50);
}
