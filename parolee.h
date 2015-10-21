#ifndef PAROLEE_H
#define PAROLEE_H

#include <math.h>

class Parolee : public Prisoner
{
    public:
        Parolee();
        ~Parolee();
        void setparole(int sentence);
    protected:
        int parole;
    private:
};

void Parolee::setparole(int sentence)
{
    this->parole = floor(.33 * sentence);
}

#endif // PAROLEE_H
