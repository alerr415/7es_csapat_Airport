#ifndef ADMINISZTRATOR_H
#define ADMINISZTRATOR_H

#include "operator.h"
#include "manipulator.h"
#include <string>

class Adminisztrator : public Operator
{
public:
    Adminisztrator();
    virtual ~Adminisztrator() override = default;
    virtual void keres() const override;
    virtual void modosit() override;
    virtual void teljesBevitel() const;
};

#endif // ADMINISZTRATOR_H
