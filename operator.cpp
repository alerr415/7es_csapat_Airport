#include "operator.h"

Operator::Operator(std::string _felhasznalonev, std::string _jelszo):
    felhasznalonev(_felhasznalonev),jelszo(_jelszo)
{
}

void Operator::keres() const
{
    Repuloter& instance = Repuloter::getInstance();
    int param;
    std::string kulcsszo;
    std::cout << "Mi alapján szeretne keresni?" << std::endl;
    std::cout << "1 - HONNAN" << std::endl;
    std::cout << "2 - HOVA" << std::endl;
    std::cout << "3 - INDULÁS" << std::endl;
    std::cout << "4 - ÉRKEZÉS" << std::endl;
    std::cout << "5 - JÁRAT AZONOSÍTÓ" << std::endl;
    std::cin >> param;
    std::cout << "Adja meg a keresett kulcsszót!" << std::endl;
    std::cin >> kulcsszo;
    /*if (indulo)
     * ref lista indulo
     * else
     * ref lista erkezo
    ez alapjan hivja meg a switch case-eket*/
    switch (param) {
    case 1: std::cout << "Az innen (" << kulcsszo << ") induló gépek adatai: " << std::endl;
            if(kulcsszo==instance.getNev())
                for(auto j: instance.getIndulo()) {
                    if(j.getHonnan()==kulcsszo)
                        std::cout << j;
                }
            else
                for(auto j: instance.getErkezo()) {
                    if(j.getHonnan()==kulcsszo)
                        std::cout << j;
                }
            break;
    case 2: std::cout << "Az ide (" << kulcsszo << ") induló gépek adatai: " << std::endl;
            for(auto j: instance.getIndulo()) {
                if(j.getHova()==kulcsszo)
                    std::cout << j;
            }
            break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    default: std::cout << "Érvénytelen keresési paraméter!" << std::endl;
        break;
    }
}

void Operator::modosit()
{

}

void Operator::teljesBevitel()
{

}
