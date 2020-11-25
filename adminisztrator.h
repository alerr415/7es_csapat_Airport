#ifndef ADMINISZTRATOR_H
#define ADMINISZTRATOR_H

#include "operator.h"
#include "manipulator.h"
#include <string>

class Adminisztrator : public Operator
{
public:
    Adminisztrator() = default;
    Adminisztrator(std::string _felhasznalonev, std::string _jelszo);
    virtual ~Adminisztrator() override = default;
    virtual void keres() const override;
    virtual void modosit() override;
    virtual void teljesBevitel() const;
};

#endif // ADMINISZTRATOR_H
