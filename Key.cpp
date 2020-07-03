#include "Key.h"

Key::Key(int _pin, int _mode, int _button, ...){
  pinMode(_pin, INPUT_PULLUP);
  pin = _pin;
  mode = _mode;

  button = _button;

  va_list arguments; 
  va_start ( arguments, _button);
  if (_mode == MACRO){
    modifiers = va_arg (arguments, int);
    if (modifiers > MAX_ACCEPTED_MODIFIERS) modifiers = MAX_ACCEPTED_MODIFIERS;
    int i = modifiers;
    while(i-->0){
      modifier[i] = va_arg (arguments, int);
    }
  }
  va_end (arguments);

  stat = false;

  curr = 1;
  prev = 1;
}


void Key::poll(){
  prev = curr;
  curr = digitalRead(pin);
  switch(mode){
    case MACRO:
      if(!curr && prev){
        int t = modifiers;
        while(t-->0)Keyboard.press(modifier[t]);
        Keyboard.write(button);
        t = modifiers;
        while(t-->0)Keyboard.release(modifier[t]);
      }
      break;
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
