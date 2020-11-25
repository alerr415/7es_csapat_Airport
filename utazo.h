#ifndef UTAZO_H
#define UTAZO_H

#include "manipulator.h"

class Utazo : public Manipulator
{
public:
    Utazo();
    virtual ~Utazo() override = default;
    void keres() const override;
};

#endif // UTAZO_H
