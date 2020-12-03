#ifndef OPERATOR_H
#define OPERATOR_H

#include "manipulator.h"
#include "repuloter.h"
#include <string>
#include <iostream>
#include <algorithm>

class Operator : public Manipulator
{
protected:
    std::string felhasznalonev, jelszo;

    void keresMegjelenit(std::list<Jarat>::const_iterator& _it) const;
public:
    Operator() = default;
    Operator(std::string _felhasznalonev, std::string _jelszo);
    virtual ~Operator() override = default;
    virtual void keres() const override;
    virtual void modosit() override;
    virtual void teljesBevitel() override;
};

#endif // OPERATOR_H
