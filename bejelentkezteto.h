#ifndef BEJELENTKEZTETO_H
#define BEJELENTKEZTETO_H

#include <string>
#include "manipulator.h"
#include "adminisztrator.h"
#include "operator.h"

class Bejelentkezteto
{
private:
    Bejelentkezteto();
    Bejelentkezteto(const Bejelentkezteto& other);
public:
    static Bejelentkezteto& getInstance();

    Manipulator* bejelentkeztet(const std::string& felhasznalonev, const std::string& jelszo) const;
};

#endif // BEJELENTKEZTETO_H
