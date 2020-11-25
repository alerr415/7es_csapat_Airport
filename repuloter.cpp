#include "repuloter.h"
#include <chrono>
#include <ctime>
#include <iostream>

std::list<Jarat>& Repuloter::getIndulo()
{
    return indulo;
}

std::list<Jarat>& Repuloter::getErkezo()
{
    return erkezo;
}

void Repuloter::erkezoMegjelenit() const
{
    for (auto e : erkezo)
    {
        std::cout << e.getJaratAzonosito() << "|"
                  << e.getHonnan() << "|"
                  << e.getHova() << "|"
                  << e.getIndulas().getEv() << "-"
                  << e.getIndulas().getHonap() << "-"
                  << e.getIndulas().getNap() << "-"
                  << e.getIndulas().getOra() << "-"
                  << e.getErkezes().getEv() << "-"
                  << e.getErkezes().getHonap() << "-"
                  << e.getErkezes().getNap() << "-"
                  << e.getErkezes().getOra() << "-"
                  << e.getErkezes().getPerc() << "|"                 << e.getIndulas().getPerc() << "|"
                  << e.getKeses() << std::endl;
    }
}

void Repuloter::induloMegjelenit() const
{
    for (auto e : indulo)
    {
        std::cout << e.getJaratAzonosito() << "|"
                  << e.getHonnan() << "|"
                  << e.getHova() << "|"
                  << e.getIndulas().getEv() << "-"
                  << e.getIndulas().getHonap() << "-"
                  << e.getIndulas().getNap() << "-"
                  << e.getIndulas().getOra() << "-"
                  << e.getErkezes().getEv() << "-"
                  << e.getErkezes().getHonap() << "-"
                  << e.getErkezes().getNap() << "-"
                  << e.getErkezes().getOra() << "-"
                  << e.getErkezes().getPerc() << "|"
                  << e.getIndulas().getPerc() << "|"
                  << e.getKeses() << std::endl;
    }
}

Repuloter::Repuloter()
{
    std::chrono::system_clock::time_point rendszerido = std::chrono::system_clock::now();
    time_t most = std::chrono::system_clock::to_time_t(rendszerido);
    tm lokalis = *localtime(&most);
    ido = Datum(lokalis.tm_year+1900,lokalis.tm_mon+1,lokalis.tm_mday,lokalis.tm_hour,lokalis.tm_min);

    nev = "Budapest, Liszt Ferenc";  // konstans, itt változtatható
}

Repuloter &Repuloter::getInstance()
{
    static Repuloter instance;
    return instance;
}

void Repuloter::addJarat(const Jarat &ujJarat)
{
    if (ujJarat.getHova() == nev)
    {
        auto it = erkezo.begin();
        while (it != erkezo.end() && it->getErkezes() < ujJarat.getErkezes())
        {
            ++it;
        }
        erkezo.insert(++it,ujJarat);
    }
    else if (ujJarat.getHonnan() == nev)
    {
        auto it =indulo.begin();
        while (it != indulo.end() && it->getIndulas() < ujJarat.getIndulas())
        {
            ++it;
        }
        indulo.insert(++it,ujJarat);
    }
}
