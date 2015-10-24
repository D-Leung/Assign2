#ifndef JAILED_H
#define JAILED_H

#include <math.h>

class Jailed : public Prisoner
{
    public:
        Jailed();
        float calculateGoodtime();
    protected:
        float goodTime;
        double goodTimerate = .10;
    private:
};

Jailed::Jailed()
{
    int tS = timeSentence;
    int tSer = timeServed;
    double gTR = goodTimerate;
}

float Jailed::calculateGoodtime()
{
    this->goodTime = (floor(timeServed) * goodTimerate);
    return goodTime;
}

#endif // JAILED_H
