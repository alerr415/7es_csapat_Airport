#include "operator.h"
#include "utazo.h"

Operator::Operator(std::string _felhasznalonev, std::string _jelszo):
    felhasznalonev(_felhasznalonev),jelszo(_jelszo)
{
}

void Operator::keres()
{
    Repuloter& instance = Repuloter::getInstance();
    int param;
    std::string kulcsszo, opcio;
    std::list<Jarat> jaratlista;
    jaratlista.clear();
    std::cout << "Mi alapján szeretne keresni?" << std::endl;
    std::cout << "1 - HONNAN" << std::endl;
    std::cout << "2 - HOVA" << std::endl;
    std::cout << "3 - INDULÁS (a megadott időpont utáni indulások listázása)" << std::endl;
    std::cout << "4 - ÉRKEZÉS (a megadott időpont utáni indulások listázása)" << std::endl;
    std::cout << "5 - JÁRAT AZONOSÍTÓ" << std::endl;
    std::cin >> param;
    std::cout << "Adja meg a keresett kulcsszót!" << std::endl;
    std::cout << "Időpont keresésénél az elvárt megadási formátum: YYYY-MM-DD-HH-MM" << std::endl;
    std::cin >> kulcsszo;
    switch (param) {
    case 1: std::cout << "A(z) " << kulcsszo << " felől ide érkező gépek adatai: " << std::endl;
            for(auto j: instance.getErkezo()) {
                if(j.getHonnan()==kulcsszo)
                    std::cout << j;
                }
            break;
    case 2: std::cout << "Az innen " << kulcsszo << " felé induló gépek adatai: " << std::endl;
            for(auto j: instance.getIndulo()) {
                if(j.getHova()==kulcsszo)
                    std::cout << j;
            }
            break;
    case 3: std::cout << "Az ekkortól (" << kulcsszo << ") induló gépek adatai: " << std::endl;
            for(auto j: instance.getIndulo()) {
                std::vector<std::string> dateComponents = String::split<std::vector<std::string>>(kulcsszo,'-');
                Datum idopont(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
                dateComponents.clear();
                if(j.getIndulas()<idopont || j.getIndulas()==idopont)
                    jaratlista.push_back(j);
            }
            jaratlista.sort([](Jarat j1, Jarat j2){
                return j1.getIndulas() < j2.getIndulas(); });
            jaratlista.clear();
            break;
    case 4: std::cout << "Az ekkortól (" << kulcsszo << ") érkező gépek adatai: " << std::endl;
            for(auto j: instance.getErkezo()) {
                std::vector<std::string> dateComponents = String::split<std::vector<std::string>>(kulcsszo,'-');
                Datum idopont(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
                dateComponents.clear();
                if(j.getIndulas()<idopont || j.getIndulas()==idopont)
                    jaratlista.push_back(j);
            }
            jaratlista.sort([](Jarat j1, Jarat j2){
                return j1.getIndulas() < j2.getIndulas(); });
            jaratlista.clear();
            break;
    case 5: std::cout << "Az ezen (" << kulcsszo << ") járatszámú gépek adatai: " << std::endl;
            for(auto j: instance.getIndulo()) {
                if(j.getJaratAzonosito()==kulcsszo)
                    std::cout << j;
            }
            break;
    default: std::cout << "ERROR: Érvénytelen keresési paraméter!" << std::endl;
        break;
    }

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
