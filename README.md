# Pedaliera
A really small library to control a pedal board using an arduino (Leonardo - micro)

## What does it do
It allows to easily modify configuration and binding for different buttons

## References

### In `setup`
**`Key(_pin)`**
Constructor setting _pin as `INPUT_PULLUP` by default
### In `setup` or `loop`
**`Key.set(_mode)`**
Set button's reading mode (output on raising/falling edge, toggle, hold, multiple buttons, status read)

**`Key.bind(_button, ... <modifers>)`**
Set button (or buttons in case of multiple bunding) binding (It's possible to use all values from the <Keyboard.h> standars library)
The maximum binding number for every button is set to 5 (only used in `MULTI` mode) (edit `MAX_ACCEPTED_MODIFIERS` in Key.h)
### In `loop`
**`Key.poll()`**
Get button state, output depends on button mode

## Setting modes in `Key.set(_mode)`, `Keboard.h`'s functions called and return value on `Key.pool()`
**`PRESS`**
  `Keyboard.write(_button)` on button press and `return 1`
  
**`RELEASE`**
  Keyboard.write(_button) on button release and `return 1`
  
**`HOLD`**
  `Keyboard.press(_button)` on press and `Keyboard.release(_button)` on release
  
**`TOGGLE`**
  Alternate `Keyboard.press(_button)` and `Keyboard.release(_button)` when button is pressed (on changing state)
  
**`MULTI`**
  `Keyboard.press(_modifier)` for each modifier and `Keyboard.write(_button)`, then `Keyboard.release(_modifier)` foreach
  
**`READ`**
  `return 1` when button is pressed (on changing state), act like **`PRESS`** for the arduino without sending data on serial
