#ifndef Touch_h
#define Touch_h

#include "Arduino.h"

#define TOUCH_1 A1
#define TOUCH_2 A2
#define TOUCH_3 A0
#define TOUCH_4 A3

class Touch
{
    public:
        int getRawX();
        int getRawY();
    private:
        int xRaw;
        int yRaw;
};

#endif