#include "Arduino.h"
#include "Key.h"

Key::Key(int _pin, int _button, int _mode){
  pinMode(_pin, INPUT_PULLUP);
  pin = _pin;

  button = _button;
  mode = _mode;

  stat = false;

  curr = 1;
  prev = 1;
}


void Key::poll(){
  prev = curr;
  curr = digitalRead(pin);
  switch(mode){
    case HOLD:
      if(!curr && prev){
        Keyboard.press(button);
      }else if (curr && !prev){
        Keyboard.release(button);
      }
      break;
    case TOGGLE:
      if(!curr && prev){
        stat = !stat;
        if(stat){
          Keyboard.press(button);
        }else{
          Keyboard.release(button);
        }
      }
      break;
    default:
      if(!curr && prev){
        Keyboard.write(button);
      }
  }
}
