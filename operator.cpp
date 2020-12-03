#include "operator.h"

Operator::Operator(std::string _felhasznalonev, std::string _jelszo):
    felhasznalonev(_felhasznalonev),jelszo(_jelszo)
{
}

void Operator::keresMegjelenit(std::list<Jarat>::const_iterator &_it) const
{
    std::cout << (*_it).getJaratAzonosito() << "|"
              << (*_it).getHonnan() << "|"
              << (*_it).getHova() << "|"
              << (*_it).getIndulas().getEv() << "-"
              << (*_it).getIndulas().getHonap() << "-"
              << (*_it).getIndulas().getNap() << "-"
              << (*_it).getIndulas().getOra() << "-"
              << (*_it).getIndulas().getPerc() << "|"
              << (*_it).getErkezes().getEv() << "-"
              << (*_it).getErkezes().getHonap() << "-"
              << (*_it).getErkezes().getNap() << "-"
              << (*_it).getErkezes().getOra() << "-"
              << (*_it).getErkezes().getPerc() << "|"
              << (*_it).getKeses() << std::endl;
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
    switch (param) {
    case 1: std::cout << "Az innen (" << param << ") induló gépek adatai: " << std::endl;
            //std::for_each(instance.getIndulo().cbegin(),instance.getIndulo().cend(),[&param](Jarat& j){
                 //         if(j.getHonnan()==param)
                 //             keresMegjelenit(j);
                //});
//                    for(auto j: instance.getIndulo()) {
//                        if(j.getHonnan()==param)
//                         keresMegjelenit(j);
//            }


        break;
    case 2:
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
