#include "utazo.h"
#include "repuloter.h"
#include "stringhandler.h"
#include <algorithm>
#include <vector>

Utazo::Utazo()
{
}

void Utazo::keres()
{
    Repuloter& instance = Repuloter::getInstance();
    std::string hely;
    int opcio = 0;
    std::string idoTmp;
    std::cout << "Az aktualis helyzetet (Budapest Liszt Ferenc Repuloter)" << std::endl
              << " 1  : INDULO\n  2 : ERKEZO" << std::endl;
    std::cin >> opcio;
    if( opcio==1) {
        std::string honnan = "BUD";
        std::cout << "Adja meg a celallomast (repuloterkod): ";
    }
    else if( opcio==2) {
        std::string hova = "BUD";
        std::cout << "Adja meg az indulasi helyet (repuloterkod): ";
    }
    else {
        std::cout << "Ervenytelen parameter" << std::endl;
        return;
    }
    std::cin >> hely;
    std::cout << "Adja meg mettol listazzuk a gepeket (yyyy-m-d-h-m): ";
    std::cin >> idoTmp;
    std::vector<std::string> dateComponents = String::split<std::vector<std::string>>(idoTmp,'-');
    Datum kezdetido(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
    dateComponents.clear();
    std::cout << "Adja meg meddig listazzuk a gepeket (yyyy-m-d-h-m): ";
    std::cin >> idoTmp;
    dateComponents = String::split<std::vector<std::string>>(idoTmp,'-');
    Datum vegido(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
    dateComponents.clear();
    if(opcio==1) {
        for(auto j : instance.getIndulo())
            if(j.getHova()==hely && (j.getIndulas()>kezdetido || j.getIndulas()==kezdetido) && (j.getIndulas()<vegido || j.getIndulas()==vegido))
                std::cout << j;
    } else if(opcio==2) {
        for(auto j : instance.getErkezo())
                    if(j.getHonnan()==hely && (j.getErkezes()>kezdetido || j.getErkezes()==kezdetido) && (j.getIndulas()<vegido || j.getIndulas()==vegido))
                        std::cout << j;
    }
}

void Utazo::modosit()
{
    std::cout << "Nincs jogosultsaga adatok modositasara" << std::endl;
}

void Utazo::teljesBevitel()
{
    std::cout << "Nincs jogosultsaga adatok bevitelere" << std::endl;
}
