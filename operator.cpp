#include "operator.h"
#include "utazo.h"
#include <algorithm>

Operator::Operator(std::string _felhasznalonev, std::string _jelszo):
    felhasznalonev(_felhasznalonev),jelszo(_jelszo)
{
}

void Operator::keres()
{
    Repuloter& instance = Repuloter::getInstance();
    int param;
    std::string kulcsszo;
    std::cout << "Adja meg a keresesi parametereket" << std::endl
              << "  1 - HONNAN" << std::endl
              << "  2 - HOVA" << std::endl
              << "  3 - INDULAS (yyyy-m-d-h-m)" << std::endl
              << "  4 - ERKEZES (yyyy-m-d-h-m)" << std::endl
              << "  5 - JARAT AZONOSITO" << std::endl
              << ">";
    std::cin >> param;
    std::cout << "Adja meg a keresett kulcsszot:" << std::endl;
    std::cin >> kulcsszo;
    switch (param) {
    case 1: {
        std::cout << "A(z) " << kulcsszo << " felol ide erkezo jaratok adatai: " << std::endl;
        // mintapélda a keresési eredmények számának limitálására
        for(auto j: instance.getErkezo()) {
            if(j.getHonnan()==kulcsszo) {
                std::cout << j;
            }
        }
        break;
    }
    case 2: {
        std::cout << "Az innen " << kulcsszo << " fele indulo jaratok adatai: " << std::endl;
        for(auto j: instance.getIndulo()) {
            if(j.getHova()==kulcsszo) {
                std::cout << j;
            }
        }
        break;
    }
    case 3: {
        std::cout << "Az ekkortol (" << kulcsszo << ") indulo jaratok adatai: " << std::endl;
        std::vector<std::string> dateComponents = String::split<std::vector<std::string>>(kulcsszo,'-');
        Datum idopont(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
        dateComponents.clear();
        for(auto j: instance.getIndulo()) {
            if(j.getIndulas()<idopont || j.getIndulas()==idopont) {
                std::cout << j;
            }
        }
        break;
    }
    case 4: {
        std::cout << "Az ekkortol (" << kulcsszo << ") erkezo jaratok adatai: " << std::endl;
        std::vector<std::string> dateComponents = String::split<std::vector<std::string>>(kulcsszo,'-');
        Datum idopont(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
        dateComponents.clear();
        for(auto j: instance.getErkezo()) {
            if(j.getIndulas()<idopont || j.getIndulas()==idopont) {
                std::cout << j;
            }
        }
        break;
    }
    case 5: {
        std::cout << "Az ezen (" << kulcsszo << ") jaratszamu jaratok adatai: " << std::endl;
        for(auto j: instance.getIndulo()) {
            if(j.getJaratAzonosito()==kulcsszo) {
                std::cout << j;
            }
        }
        break;
    }
    default: std::cout << "Ervenytelen keresesi parameter" << std::endl;
        break;
    }

}

void Operator::modosit()
{
    std::cout << "Adja meg a jarat tipusat:\n  1 : erkezo\n  2 : indulo\n>";
    int opcio = 0;
    std::cin >> opcio;
    std::cout << "Adja meg a jarat azonositojat: ";
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
            std::cout << "A rendszer nem talalja a megadott azonositot" << std::endl;
            return;
        } else
        {
            std::cout << "A jarat adatai:" << std::endl;
            std::cout << *toModify;
            std::cout << "Adja meg a modositando jarat uj adatait" << std::endl;
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
            std::cout << "A rendszer nem talalja a megadott azonositot" << std::endl;
            return;
        } else
        {
            std::cout << "A jarat adatai:" << std::endl;
            std::cout << *toModify;
            std::cout << "Adja meg a modositando jarat uj adatait" << std::endl;
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
    std::cout << "Adja meg a jarat indulasi idejet (yyyy-m-d-h-m): ";
    std::cin >> indulas;
    std::cout << "Adja meg a jarat erkezesi idejet (yyyy-m-d-h-m): ";
    std::cin >> erkezes;
    std::cout << "Adja meg a jarat keseset: ";
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
