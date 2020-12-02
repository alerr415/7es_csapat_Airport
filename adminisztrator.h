#ifndef ADMINISZTRATOR_H
#define ADMINISZTRATOR_H

#include "operator.h"
#include "manipulator.h"
#include <string>
#include "repuloter.h"

class Adminisztrator : public Operator
{
public:
    Adminisztrator() = default;
    Adminisztrator(std::string _felhasznalonev, std::string _jelszo);
    virtual ~Adminisztrator() override = default;
    virtual void teljesBevitel();
private:
    void manualisBevitel();
    void fileBevitel();
    Jarat rekordBeolvas();
    void rekordModosit();
};

#endif // ADMINISZTRATOR_H
