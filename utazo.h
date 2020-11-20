#ifndef UTAZO_H
#define UTAZO_H

#include "manipulator.h"

class Utazo : public Manipulator
{
public:
    Utazo();
    ~Utazo() = default;
    void keres() const;
};

#endif // UTAZO_H
