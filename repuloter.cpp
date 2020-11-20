#include "repuloter.h"

std::list<Jarat> Repuloter::getIndulo() const
{
    return indulo;
}

std::list<Jarat> Repuloter::getErkezo() const
{
    return erkezo;
}

Repuloter::Repuloter()
{

}

Repuloter &Repuloter::getInstance()
{
    static Repuloter instance;
    return instance;
}
