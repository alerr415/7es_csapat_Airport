#include "operator.h"
#include "utazo.h"

Operator::Operator(std::string _felhasznalonev, std::string _jelszo):
    felhasznalonev(_felhasznalonev),jelszo(_jelszo)
{
}

void Operator::keres()
{
    Utazo u;
    u.keres();
}

void Operator::modosit()
{
    std::cout << "Adja meg a járat típusát:\n 1 : érkező\n 2 : induló\n>";
    int opcio = 0;
    std::cin >> opcio;
    std::cout << "Adja meg a járat azonosítóját: ";
    std::string azonosito = "";
    std::cin >> azonosito;
    switch (opcio)
    {
    case 1: {
        auto toModify = std::find_if(Repuloter::getInstance().getErkezo().begin(),Repuloter::getInstance().getErkezo().end(),[azonosito](Jarat jarat){
            return jarat.getJaratAzonosito() == azonosito;
        });
        if (toModify == Repuloter::getInstance().getErkezo().end())
        {
            std::cout << "A rendszer nem találja a megadott azonosítót" << std::endl;
            return;
        } else
        {
            std::cout << "A járat adatai:" << std::endl;
            std::cout << *toModify;
            std::cout << "Adja meg a módosítandó járat új adatait" << std::endl;
            rekordBeolvas(*toModify);
        }
        Repuloter::getInstance().getErkezo().sort([](Jarat a, Jarat b) {
            return a.getErkezes() < b.getErkezes();
        });
        break;
    }
    case 2: {
        auto toModify = std::find_if(Repuloter::getInstance().getIndulo().begin(),Repuloter::getInstance().getIndulo().end(),[azonosito](Jarat jarat){
            return jarat.getJaratAzonosito() == azonosito;
        });
        if (toModify == Repuloter::getInstance().getIndulo().end())
        {
            std::cout << "A rendszer nem találja a megadott azonosítót" << std::endl;
            return;
        } else
        {
            std::cout << "A járat adatai:" << std::endl;
            std::cout << *toModify;
            std::cout << "Adja meg a módosítandó járat új adatait" << std::endl;
            rekordBeolvas(*toModify);
        }
        Repuloter::getInstance().getIndulo().sort([](Jarat a, Jarat b) {
            return a.getIndulas() < b.getIndulas();
        });

        break;
    }
    default: break;
    }

}

void Operator::teljesBevitel()
{
    std::cout << "Nincsen jogosultsaga adatok bevitelere" << std::endl;
}


void Operator::rekordBeolvas(Jarat &toModify)
{
    std::string indulas = "";
    std::string erkezes = "";
    unsigned keses = 0;
    std::cout << "Adja meg a járat indulási idejét (yyyy-m-d-h-m): ";
    std::cin >> indulas;
    std::cout << "Adja meg a járat érkezési idejét (yyyy-m-d-h-m): ";
    std::cin >> erkezes;
    std::cout << "Adja meg a járat késését: ";
    std::cin >> keses;
    std::vector<std::string> dateComponents = String::split<std::vector<std::string>>(indulas,'-');
    Datum indulas_d(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
    dateComponents.clear();
    dateComponents = String::split<std::vector<std::string>>(erkezes,'-');
    Datum erkezes_d(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
    toModify.setIndulas(indulas_d);
    toModify.setErkezes(erkezes_d);
    toModify.setKeses(keses);
}
