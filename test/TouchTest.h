#ifndef TouchTest_h
#define TouchTest_h

#include "Touch.h"

class TouchTest{
    public:
        void setup();
        void loop();
        void getRawValues();
    private:
        Touch touch;
};

#endif