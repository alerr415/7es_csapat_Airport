#ifndef ADMINISZTRATOR_H
#define ADMINISZTRATOR_H

#include "operator.h"
#include "manipulator.h"
#include <string>
#include "repuloter.h"

class Adminisztrator : public Manipulator
{
public:
    Adminisztrator() = default;
    Adminisztrator(std::string _felhasznalonev, std::string _jelszo);
    virtual ~Adminisztrator() override = default;
    virtual void teljesBevitel() override;
    virtual void modosit() override;
    virtual void keres() const override;
private:
    void manualisBevitel();
    void fileBevitel();
    Jarat rekordBeolvas();
    void rekordModosit();
};

#endif // ADMINISZTRATOR_H
