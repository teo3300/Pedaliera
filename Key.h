#ifndef KEY_H
#define KEY_H

#include "Arduino.h"
#include <Keyboard.h>
#include <stdarg.h>
#include <stdio.h>

#define MAX_ACCEPTED_MODIFIERS 4

#define PRESS   0
#define RELEASE 1
#define HOLD    2
#define TOGGLE  3
#define MULTI   4
#define READ    5

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
    Key(int);
    void set(int);
    void bind(int, ... );
    int poll();
};

#endif//KEY_H
