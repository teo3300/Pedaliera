#include "Key.h"

Key left   = Key(2);
Key center = Key(6);
Key right  = Key(9);
int stat = 0;

void setup(){
  left.set(PRESS);
  left.bind(KEY_LEFT_ARROW);
  center.set(READ);
  right.set(PRESS);
  right.bind(KEY_RIGHT_ARROW);
  Keyboard.begin();
}

void loop(){
  if(center.poll()){
    stat = !stat;
    if(stat){
      left.bind(' ');
      right.bind(KEY_RIGHT_SHIFT);
    }else{
      left.bind(KEY_LEFT_ARROW);
      right.bind(KEY_RIGHT_ARROW);
    }
  }
  
  left.poll();
  right.poll();
  delay(50);
}
