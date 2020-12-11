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
    std::string viszonyitas, hely;
    std::string idoTmp;
    std::cout << "Az aktualis helyzetet (Budapest Liszt Ferenc Repuloter) szeretne indulasi, vagy erkezesi helyszinnek? (indulasi / erkezesi)" << std::endl << ">";
    std::cin >> viszonyitas;
    if(viszonyitas=="indulasi") {
        std::string honnan = "BUD";
        std::cout << "Adja meg hova szeretne menni! (repuloterkod)" << std::endl;
    }
    else if(viszonyitas=="erkezo") {
        std::string hova = "BUD";
        std::cout << "A honnan erkezo gepek adataira kivancsi? (repuloterkod)" << std::endl;
    }
    else
        std::cout << "Ervenytelen parameter" << std::endl;
    std::cin >> hely;
    std::cout << "Megjegyzes: Hogyha az indulast valaszotta a lehetosegek kozul, akkor az indulasi idok kozott fog keresni, " << std::endl
              << "\t hogyha az erkezest valaszotta a lehetosegek kozul, akkor az erkezesi idok kozott fog keresni." << std::endl;
    std::cout << "Adja meg mettol listazzuk a gepeket! (yyyy-m-d-h-m)" << std::endl;
    std::cin >> idoTmp;
    std::vector<std::string> dateComponents = String::split<std::vector<std::string>>(idoTmp,'-');
    Datum kezdetido(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
    dateComponents.clear();
    std::cout << "Adja meg meddig listazzuk a gepeket! (yyyy-m-d-h-m)" << std::endl;
    std::cin >> idoTmp;
    dateComponents = String::split<std::vector<std::string>>(idoTmp,'-');
    Datum vegido(String::strToNum<unsigned>(dateComponents[0]),String::strToNum<unsigned>(dateComponents[1]),String::strToNum<unsigned>(dateComponents[2]),String::strToNum<unsigned>(dateComponents[3]),String::strToNum<unsigned>(dateComponents[4]));
    dateComponents.clear();
    if(viszonyitas=="indulasi") {
        for(auto j : instance.getIndulo())
            if(j.getHova()==hely && (j.getIndulas()>kezdetido || j.getIndulas()==kezdetido) && (j.getIndulas()<vegido || j.getIndulas()==vegido))
                std::cout << j;
    } else if(viszonyitas=="erkezo") {
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
