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
    // tesztelésre; nem végleges
    for (auto e : erkezo)
    {
        std::cout << e.getJaratAzonosito() << "|"
                  << e.getHonnan() << "|"
                  << e.getHova() << "|"
                  << e.getIndulas().getEv() << "-"
                  << e.getIndulas().getHonap() << "-"
                  << e.getIndulas().getNap() << "-"
                  << e.getIndulas().getOra() << "-"
                  << e.getIndulas().getPerc() << "|"
                  << e.getErkezes().getEv() << "-"
                  << e.getErkezes().getHonap() << "-"
                  << e.getErkezes().getNap() << "-"
                  << e.getErkezes().getOra() << "-"
                  << e.getErkezes().getPerc() << "|"
                  << e.getKeses() << std::endl;
    }
}

void Repuloter::induloMegjelenit() const
{
    // tesztelésre; nem végleges
    for (auto e : indulo)
    {
        std::cout << e.getJaratAzonosito() << "|"
                  << e.getHonnan() << "|"
                  << e.getHova() << "|"
                  << e.getIndulas().getEv() << "-"
                  << e.getIndulas().getHonap() << "-"
                  << e.getIndulas().getNap() << "-"
                  << e.getIndulas().getOra() << "-"
                  << e.getIndulas().getPerc() << "|"
                  << e.getErkezes().getEv() << "-"
                  << e.getErkezes().getHonap() << "-"
                  << e.getErkezes().getNap() << "-"
                  << e.getErkezes().getOra() << "-"
                  << e.getErkezes().getPerc() << "|"
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
        erkezo.push_back(ujJarat);
        erkezo.sort([](const Jarat& a, const Jarat& b) {
            return a.getErkezes() < b.getErkezes();
        });
    }
    else if (ujJarat.getHonnan() == nev)
    {
        indulo.push_back(ujJarat);
        indulo.sort([](const Jarat& a, const Jarat& b) {
            return a.getIndulas() < b.getIndulas();
        });
    }
}
