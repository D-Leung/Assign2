#ifndef PRISONER_H
#define PRISONER_H

#include<string>

class Prisoner
{
    public:
        std::string getfirstName() { return firstName; }
        void setfirstName(std::string fname) { firstName = fname; }
        std::string getlastName() { return lastName; }
        void setlastName(std::string lname) { lastName = lname; }
        std::string getidNumber() { return idNumber; }
        void setidNumber(std::string idNum) { idNumber = idNum; }
        int gettimeSentence() { return timeSentence; }
        void settimeSentence(int sentence) { timeSentence = sentence; }
        int gettimeServed() { return timeServed; }
        void settimeServed(int served) { timeServed = served; }
        int gettimeRemain();
        int getcredit() { return credit; }
        void setcredit(int infraction);
        int getdebit() { return debit; }
        void setdebit(int infraction);
    protected:
        std::string idNumber;
        int timeSentence;
        int timeServed;
        int timeRemain;
        int credit;
        int debit;
    private:
        std::string firstName;
        std::string lastName;
};

int Prisoner::gettimeRemain()
{
    this->timeRemain = timeSentence - timeServed;
    return timeRemain;
}

void Prisoner::setcredit(int infraction)
{
    if (infraction >= 1)
        this->credit = 0;
    else
        this->credit = 1;
}

void Prisoner::setdebit(int infraction)
{
    if (infraction >= 1)
        this->debit = 1;
    else
        this->debit = 0;
}



#endif // PRISONER_H
