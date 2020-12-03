#include "adminisztrator.h"
#include "stringhandler.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

Adminisztrator::Adminisztrator(std::string _felhasznalonev, std::string _jelszo):
    Operator(_felhasznalonev,_jelszo)
{
}

void Adminisztrator::teljesBevitel()
{
    // bejelntekés után vagyunk, azt a main végzi
    // beviteli adatok megjelenítése
    std::cout << "Adja meg a beviteli módot:\n  1 : manuális\n  2 : fájlból olvasás\n>" << std::endl;
    int opcio = 0;
    std::cin >> opcio;
    switch (opcio)
    {
    case 1:
        manualisBevitel();
        break;
    case 2:
        fileBevitel();
        break;
    default: break;
    }
}

void Adminisztrator::modosit()
{

}

void Adminisztrator::keres() const
{

}

void Adminisztrator::manualisBevitel()
{
    std::cout << "Adja meg a beviteli opciót:\n 1 : új rekord\n 2 : rekord módosítása" << std::endl;
    unsigned opcio = 0;
    std::cin >> opcio;
    Repuloter& r = Repuloter::getInstance();
    switch (opcio)
    {
    case 1: {
        Jarat toAdd = rekordBeolvas();
        r.addJarat(toAdd);
        break;
    }
    case 2: {
        rekordModosit();
        break;
    }
    default: break;
    }
}

void Adminisztrator::fileBevitel()
{
    Repuloter& r = Repuloter::getInstance();
    std::string file = "";
    std::ifstream input;
    std::cout << "adja meg a file nevet: ";
    std::cin >> file;
    input.open(file,std::ios_base::in);
    if (!input.is_open())
        return ;
    std::string line;
    while (getline(input,line))
    {
        // azonosito 0; honnan 1; hova 2; indulas 3; erkezes 4; keses 5
        std::vector<std::string> lineComponents = String::split<std::vector<std::string>>(line,';');
        std::vector<std::string> dateComponents = String::split<std::vector<std::string>>(lineComponents[3],'-');
        Datum indul(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),
                String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
        dateComponents.clear();
        dateComponents = String::split<std::vector<std::string>>(lineComponents[4],'-');
        Datum erkezik(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),
                String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
        Jarat toAdd(lineComponents[0],lineComponents[1],lineComponents[2],indul,erkezik,String::strToNum<unsigned>(lineComponents[5]));
        r.addJarat(toAdd);
    }
    std::cout << "Adatok beolvasva" << std::endl;
}

Jarat Adminisztrator::rekordBeolvas()
{
    std::string azonosito = "";
    std::string honnan = "";
    std::string hova = "";
    std::string indulas = "";
    std::string erkezes = "";
    unsigned keses = 0;
    std::cout << "Adja meg a járat azonosítóját: " ;
    std::cin >> azonosito;
    std::cout << "adja meg a járat indulási helyét: ";
    std::cin >> honnan;
    std::cout << "Adja meg a járat érkezési helyét: ";
    std::cin >> hova;
    std::cout << "Adja meg a járat indulási idejét (yyyy-m-d-h-m)";
    std::cin >> indulas;
    std::cout << "Adja meg a járat érkezési idejét (yyyy-m-d-h-m)";
    std::cin >> erkezes;
    std::cout << "Adja meg a járat késését";
    std::cin >> keses;
    std::vector<std::string> dateComponents = String::split<std::vector<std::string>>(indulas,'-');
    Datum indulas_d(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
    dateComponents.clear();
    dateComponents = String::split<std::vector<std::string>>(erkezes,'-');
    Datum erkezes_d(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
    Jarat toReturn(azonosito,honnan,hova,indulas_d,erkezes_d,keses);
    return toReturn;
}

void Adminisztrator::rekordModosit()
{
    std::cout << "Adja meg a járat típusát: 1 : érkező\n 2 : induló\n>";
    int opcio = 0;
    std::cin >> opcio;
    std::cout << "Adja meg a járat azonosítóját: ";
    std::string azonosito = "";
    std::cin >> azonosito;
    switch (opcio)
    {
    case 1: {
        auto toModify = std::find_if(Repuloter::getInstance().getErkezo().begin(),Repuloter::getInstance().getErkezo().end(),[azonosito](const Jarat& jarat){
            return jarat.getJaratAzonosito() == azonosito;
        });
        if (toModify == Repuloter::getInstance().getErkezo().end())
        {
            std::cout << "A rendszer nem találja a megadott azonosítót";
            return;
        } else
        {
            std::cout << "A járat adatai:" << std::endl;
            //TODO: megjelenit() függvény

            std::cout << "Adja meg a módosítandó járat új adatait" << std::endl;
            *toModify = rekordBeolvas();
        }
        break;
    }
    case 2:
        break;
    default: break;
    }
}
