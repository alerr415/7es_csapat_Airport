#include "datum.h"

Datum::Datum(unsigned _ev, unsigned _honap, unsigned _nap, unsigned _ora, unsigned _perc):
    ev(_ev),
    honap(_honap),
    nap(_nap),
    ora(_ora),
    perc(_perc)
{
}

Datum::Datum(unsigned _ev, unsigned _honap, unsigned _nap):
    ev(_ev),
    honap(_honap),
    nap(_nap),
    ora(0),
    perc(0)
{}

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
    if (this->ev < other.ev)
        return true;
    else if (this->ev == other.ev && this->honap < other.honap)
        return true;
    else if (this->ev == other.ev && this->honap == other.honap && this->nap < other.nap)
        return true;
    else if (this->ev == other.ev && this->honap == other.honap && this->nap == other.nap && this->ora < other.ora)
        return true;
    else if (this->ev == other.ev && this->honap == other.honap && this->nap == other.nap && this->ora == other.ora && this->perc < other.perc)
        return true;
    else return false;
}

bool Datum::operator >(const Datum &other) const
{
    if (this->ev > other.ev)
        return true;
    else if (this->ev == other.ev && this->honap > other.honap)
        return true;
    else if (this->ev == other.ev && this->honap == other.honap && this->nap > other.nap)
        return true;
    else if (this->ev == other.ev && this->honap == other.honap && this->nap == other.nap && this->ora > other.ora)
        return true;
    else if (this->ev == other.ev && this->honap == other.honap && this->nap == other.nap && this->ora == other.ora && this->perc > other.perc)
        return true;
    else return false;
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



std::ostream &operator <<(std::ostream &stream, const Datum &datum)
{
    stream << datum.ev << "-" << datum.honap << "-" << datum.nap << "-" << datum.ora << "-" << datum.perc;
    return stream;
}
