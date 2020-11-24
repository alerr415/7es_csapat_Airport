#include "repuloter.h"
#include <chrono>
#include <ctime>

std::list<Jarat>& Repuloter::getIndulo()
{
    return indulo;
}

std::list<Jarat>& Repuloter::getErkezo()
{
    return erkezo;
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
        while (it->getErkezes() < ujJarat.getErkezes())
        {
            ++it;
        }
        erkezo.insert(++it,ujJarat);
    }
    else if (ujJarat.getHonnan() == nev)
    {
        auto it =indulo.begin();
        while (it->getIndulas() < ujJarat.getIndulas())
        {
            ++it;
        }
        indulo.insert(++it,ujJarat);
    }
}
