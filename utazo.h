#ifndef UTAZO_H
#define UTAZO_H

#include "manipulator.h"

class Utazo : public Manipulator
{
public:
    Utazo();
    virtual ~Utazo() override = default;
    void keres() const override;
    void modosit() override;
    void teljesBevitel() override;
};

#endif // UTAZO_H
