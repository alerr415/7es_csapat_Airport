#ifndef OPERATOR_H
#define OPERATOR_H

#include "manipulator.h"
#include <string>

class Operator : public Manipulator
{
protected:
    std::string felhasznalonev, jelszo;
public:
    Operator();
    void keres() const override;
    virtual void modosit();
};

#endif // OPERATOR_H
