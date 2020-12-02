#include "operator.h"

Operator::Operator(std::string _felhasznalonev, std::string _jelszo):
    felhasznalonev(_felhasznalonev),jelszo(_jelszo)
{
}

void Operator::keres() const
{
//    Repuloter& instance = Repuloter::getInstance();
//    int param;
//    std::string kulcsszo;
//    std::cout << "Mi alapján szeretne keresni?" << std::endl;
//    std::cout << "1 - HONNAN" << std::endl;
//    std::cout << "2 - HOVA" << std::endl;
//    std::cout << "3 - INDULÁS" << std::endl;
//    std::cout << "4 - ÉRKEZÉS" << std::endl;
//    std::cout << "5 - JÁRAT AZONOSÍTÓ" << std::endl;
//    std::cin >> param;
//    std::cout << "Adja meg a keresett kulcsszót!" << std::endl;
//    std::cin >> kulcsszo;
//    switch (param) {
//    case 1: if(std::find(instance.getIndulo().cbegin(),instance.getIndulo().cend(), [param](auto *it){
//                         if((*it).getHonnan()==param) return *it;} )!=instance.getIndulo().cend())
//            //ez kore teszek majd egy ciklust, hogy vegig menjen az egeszen es itt majd kiiratok minden egyes talalatot
//        break;
//    case 2:
//        break;
//    case 3:
//        break;
//    case 4:
//        break;
//    case 5:
//        break;
//    default: std::cout << "Érvénytelen keresési paraméter!" << std::endl;
//        break;
//    }
}

void Operator::modosit()
{

}
