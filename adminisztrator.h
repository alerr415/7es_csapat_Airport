#ifndef ADMINISZTRATOR_H
#define ADMINISZTRATOR_H

#include "operator.h"
#include "manipulator.h"
#include <string>

class Adminisztrator : public Operator
{
protected:
    std::string felhasznalonev, jelszo;
public:
    Adminisztrator();
    void keres() const override;
    void modosit() override;
    void teljesBevitel() const;
};

#endif // ADMINISZTRATOR_H
