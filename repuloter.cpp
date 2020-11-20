#include "repuloter.h"

Repuloter::Repuloter()
{

}

Repuloter &Repuloter::getInstance()
{
    static Repuloter instance;
    return instance;
}
