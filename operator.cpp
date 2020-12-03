#include "operator.h"

Operator::Operator(std::string _felhasznalonev, std::string _jelszo):
    felhasznalonev(_felhasznalonev),jelszo(_jelszo)
{
}

void Operator::keres() const
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
            jaratlista.sort([](Jarat& j1, Jarat& j2){
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
            jaratlista.sort([](Jarat& j1, Jarat& j2){
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

}

void Operator::teljesBevitel()
{

}
