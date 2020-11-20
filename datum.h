#ifndef DATUM_H
#define DATUM_H


class Datum
{
private:
    unsigned ev, honap, nap, ora, perc;
public:
    Datum(unsigned _ev, unsigned _honap, unsigned _nap, unsigned _ora, unsigned _perc);
    bool operator ==(Datum);   //other Datum parameterben ?? Balint te jossz ide
};

#endif // DATUM_H
