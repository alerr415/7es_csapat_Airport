#include "bejelentkezteto.h"
#include <fstream>
#include <string>
#include <vector>
#include "stringhandler.h"

Bejelentkezteto::Bejelentkezteto()
{

}

Bejelentkezteto &Bejelentkezteto::getInstance()
{
    static Bejelentkezteto instance;
    return instance;
}

Manipulator *Bejelentkezteto::bejelentkeztet(const std::string &felhasznalonev, const std::string &jelszo) const
{
    std::ifstream alkalmazottak;
    alkalmazottak.open("alkalmazottak.csv",std::ios_base::in);
    std::string line;
    while (getline(alkalmazottak,line)) {
        std::vector<std::string> components = String::split<std::vector<std::string>>(line,';');
        if (components[0] == felhasznalonev && components[1] == jelszo){
            if (components[2] == "op")
                return new Operator(felhasznalonev,jelszo);
            else if (components[2] == "admin")
                return new Adminisztrator(felhasznalonev,jelszo);
        }
    }
    alkalmazottak.close();
    return nullptr;
}
