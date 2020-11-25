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
            && this->perc == other.perc;
}

bool Datum::operator <(const Datum &other) const
{
    return this->ev < other.ev
            && this->honap < other.honap
            && this->nap < other.nap
            && this->ora < other.ora
            && this->perc < other.perc;
}

unsigned Datum::getEv() const
{
    return ev;
}

unsigned Datum::getHonap() const
{
    return honap;
}

unsigned Datum::getNap() const
{
    return nap;
}

unsigned Datum::getOra() const
{
    return ora;
}

unsigned Datum::getPerc() const
{
   return perc;
}


