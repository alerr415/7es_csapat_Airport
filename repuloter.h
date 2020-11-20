#ifndef REPULOTER_H
#define REPULOTER_H

#include "jarat.h"
#include <list>

class Repuloter
{
private:
    std::string nev;
    std::list<Jarat> indulo;
    std::list<Jarat> erkezo;
    //+ Time ido ???? balint te jossz
private:
    Repuloter();
    Repuloter(const Repuloter &other);
public:
    static Repuloter& getInstance();

    void addJarat(const Jarat& ujJarat);
    std::list<Jarat> getIndulo() const;
    std::list<Jarat> getErkezo() const;
    void erkezoMegjelenit() const;
    void induloMegjelenit() const;
};

#endif // REPULOTER_H
