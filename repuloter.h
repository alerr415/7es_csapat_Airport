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
    Datum ido;
private:
    Repuloter();
    Repuloter(const Repuloter &) = delete;
    Repuloter(const Repuloter&&) = delete;
public:
    static Repuloter& getInstance();

    std::string& getNev();
    void addJarat(const Jarat& ujJarat);
    std::list<Jarat>& getIndulo();
    std::list<Jarat>& getErkezo();
    void erkezoMegjelenit() const;
    void induloMegjelenit() const;
};

#endif // REPULOTER_H
