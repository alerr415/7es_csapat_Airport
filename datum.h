#ifndef DATUM_H
#define DATUM_H
#include <ostream>

class Datum
{
private:
    unsigned ev, honap, nap, ora, perc;
public:
    Datum() = default;
    Datum(unsigned _ev, unsigned _honap, unsigned _nap, unsigned _ora, unsigned _perc);
    Datum(unsigned _ev, unsigned _honap, unsigned _nap);
    bool operator ==(const Datum& other) const;   //other Datum parameterben ?? Balint te jossz ide | megvan
    bool operator <(const Datum& other) const;
    friend std::ostream& operator <<(std::ostream& stream, const Datum& datum);

    unsigned getEv() const;
    unsigned getHonap() const;
    unsigned getNap() const;
    unsigned getOra() const;
    unsigned getPerc() const;
};

std::ostream& operator <<(std::ostream& stream, const Datum& datum);

#endif // DATUM_H
