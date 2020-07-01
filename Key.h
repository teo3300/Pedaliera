#ifndef KEY_H
#define KEY_H

#include <Keyboard.h>

#define PRESS   0
#define HOLD    1
#define TOGGLE  2

class Key {
    int pin;
    int button;
    int mode;

    bool stat;
    
    bool curr;
    bool prev;
  public:
    Key(int, int, int);
    void poll();
};

#endif//KEY_H
