#ifndef DATUM_H
#define DATUM_H


class Datum
{
private:
    unsigned ev, honap, nap, ora, perc;
public:
    Datum() = default;
    Datum(unsigned _ev, unsigned _honap, unsigned _nap, unsigned _ora, unsigned _perc);
    bool operator ==(const Datum& other) const;   //other Datum parameterben ?? Balint te jossz ide | megvan
    bool operator <(const Datum& other) const;
};

#endif // DATUM_H
