#include "datum.h"

Datum::Datum(unsigned _ev, unsigned _honap, unsigned _nap, unsigned _ora, unsigned _perc):
    ev(_ev),
    honap(_honap),
    nap(_nap),
    ora(_ora),
    perc(_perc)
{

}

bool Datum::operator ==(const Datum &other) const
{
    return this->ev == other.ev
            && this->honap == other.honap
            && this->nap == other.nap
            && this->ora == other.ora
            && this->perc == perc;
}


