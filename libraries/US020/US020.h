#ifndef US020_h
#define US020_h

#include "Arduino.h"

class US020 {
    public:
        US020(int echoPin, int trigerPin);
        unsigned long ping();
    private:
        int _echoPin;
        int _trigerPin;
};

#endif
