#ifndef KEY_H
#define KEY_H

#include "Arduino.h"
#include <Keyboard.h>
#include <stdarg.h>
#include <stdio.h>

#define MAX_ACCEPTED_MODIFIERS 4

#define PRESS   0
#define HOLD    1
#define TOGGLE  2
#define MACRO   3

class Key {
    int pin;
    int mode;
    int button;
    int modifiers;
    int modifier[MAX_ACCEPTED_MODIFIERS] = {0};

    bool stat;
    
    bool curr;
    bool prev;
  public:
    Key(int, int, int, ... );
    void poll();
};

#endif//KEY_H
