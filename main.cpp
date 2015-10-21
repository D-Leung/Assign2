#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>

#include "prisoner.h"
#include "jailed.h"
#include "parolee.h"

using namespace std;

int main()
{
    ifstream jail("prisoner_data.csv");
    string line, idNum, sent, serv, lname, fname;
    int sentence, served;

    ///////////////////////////////////////////////////
    /* Statement to make sure file is opened */
    if ( jail.is_open() )
        cout << "File opened successfully.\n";
    else
        cout << "File failed to open.\n";
    ///////////////////////////////////////////////////

    /* Reading and skipping the first line of file. */
    getline(jail,line);

    vector<string> vidNum;
    vector<int> vsentence;
    vector<int> vserved;
    vector<string> vlname;
    vector<string> vfname;

    /*
        While loop to read, parse, and assign necessary
        information to Prisoner class.
    */
    while(getline(jail,line))
    {
        stringstream text(line);

        getline(text,idNum,',');
        vidNum.push_back(idNum);

        getline(text,sent,',');
        istringstream(sent) >> sentence;
        vsentence.push_back(sentence);

        getline(text,serv,',');
        istringstream(serv) >> served;
        vserved.push_back(served);

        getline(text,lname,',');
        vlname.push_back(lname);

        getline(text,fname);
        vfname.push_back(fname);
    }
    jail.close();

    /*
        For loops to assign all the variables into the
        Prisoner class array 0-50 for a total of 51 entries
    */
    Prisoner p[100]; // Initializing Prisoner class

    for (int i = 0; i <= vidNum.size(); i++)
    {
        p[i].setidNumber(vidNum[i]);
        p[i].settimeSentence(vsentence[i]);
        p[i].settimeServed(vserved[i]);
        p[i].setlastName(vlname[i]);
        p[i].setfirstName(vfname[i]);
    }

    return 0;
}
