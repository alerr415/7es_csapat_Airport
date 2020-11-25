#include <iostream>
#include "repuloter.h"
#include <fstream>
#include <vector>
#include "stringhandler.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    /*Repuloter& r = Repuloter::getInstance();
    ifstream input;
    input.open("tester.csv",ios_base::in);
    if (!input.is_open())
        return -1;
    string line;
    int i=0;
    cout << "adatok beolvasasa" << endl;
    while (i<10 && getline(input,line))
    {
        cout << i << endl;
        // azonosito 0; honnan 1; hova 2; indulas 3; erkezes 4; keses 5
        vector<string> lineComponents = String::split<vector<string>>(line,';');
        vector<string> dateComponents = String::split<vector<string>>(lineComponents[3],'-');
        Datum indul(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),
                String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
        dateComponents = String::split<vector<string>>(lineComponents[4],'-');
        Datum erkezik(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),
                String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
        Jarat toAdd(lineComponents[0],lineComponents[1],lineComponents[2],indul,erkezik,String::strToNum<unsigned>(lineComponents[5]));
        r.addJarat(toAdd);
        cout << lineComponents[0] << " "
             << lineComponents[1] << " "
             << lineComponents[2] << " "
             << indul.getEv() << " " << indul.getNap() << " " << indul.getOra() << " " << indul.getPerc() << " "
             << erkezik.getEv() << " " << erkezik.getNap() << " " << erkezik.getOra() << " " << erkezik.getPerc() << " "
             << String::strToNum<unsigned>(lineComponents[5]);
        i++;
    }
    string test = "asd;sdf;tre;jtzuj;as";
    vector<string> tcomp = String::split<vector<string>>(test,';');
    for (auto it : tcomp)
        cout << it << endl;
    cout << r.getErkezo().size() << endl;
    std::cout << "Erkezo" << std::endl;
    r.erkezoMegjelenit();
    std::cout << "Indulo" << std::endl;
    r.induloMegjelenit();*/
    return 0;
}
