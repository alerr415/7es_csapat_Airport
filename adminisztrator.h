#ifndef ADMINISZTRATOR_H
#define ADMINISZTRATOR_H

#include "operator.h"
#include "manipulator.h"
#include <string>
#include "repuloter.h"

class Adminisztrator : public Manipulator
{
private:
    std::string felhasznalonev = "";
    std::string jelszo = "";
public:
    Adminisztrator() = default;
    Adminisztrator(std::string _felhasznalonev, std::string _jelszo);
    virtual ~Adminisztrator() override = default;
    virtual void teljesBevitel() override;
    virtual void modosit() override;
    virtual void keres() override;
private:
    void manualisBevitel();
    void fileBevitel();
    Jarat rekordBeolvas();
};

#endif // ADMINISZTRATOR_H
