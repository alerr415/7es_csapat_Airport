#include <iostream>
#include "repuloter.h"
#include <fstream>
#include <vector>
#include "stringhandler.h"

using namespace std;

int main()
{

    return 0;
}
/*
// teljes adatbevitel fileolvasás része
cout << "Hello World!" << endl;
    Repuloter& r = Repuloter::getInstance();
    ifstream input;
    input.open("tester.csv",ios_base::in);
    if (!input.is_open())
        return -1;
    string line;
    while (getline(input,line))
    {
        // azonosito 0; honnan 1; hova 2; indulas 3; erkezes 4; keses 5
        vector<string> lineComponents = String::split<vector<string>>(line,';');
        vector<string> dateComponents = String::split<vector<string>>(lineComponents[3],'-');
        Datum indul(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),
                String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
        dateComponents.clear();
        dateComponents = String::split<vector<string>>(lineComponents[4],'-');
        Datum erkezik(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),
                String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
        Jarat toAdd(lineComponents[0],lineComponents[1],lineComponents[2],indul,erkezik,String::strToNum<unsigned>(lineComponents[5]));
        r.addJarat(toAdd);
    }
*/
