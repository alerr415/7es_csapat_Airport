#include "repuloter.h"
#include <ctime>
#include <iostream>
#include <algorithm>

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
    std::cout << ido << std::endl;
    auto first = std::find_if(erkezo.cbegin(),erkezo.cend(),[this](Jarat j) {
        return ido < j.getErkezes();
    });
    if (first == erkezo.cend())
    {
        std::cout << "err" << std::endl;
        return;
    }
    for (unsigned i=0;i<10;i++)
    {
        std::cout << *first;
        ++first;
    }
}

void Repuloter::induloMegjelenit() const
{
    std::cout << ido << std::endl;
    auto first = std::find_if(indulo.cbegin(),indulo.cend(),[this](Jarat j) {
        return ido < j.getIndulas();
    });
    if (first == indulo.cend())
    {
        std::cout << "err" << std::endl;
        return;
    }
    for (unsigned i=0;i<10;i++)
    {
        std::cout << *first;
        ++first;
    }
}

Repuloter::Repuloter()
{
    std::chrono::system_clock::time_point rendszerido = std::chrono::system_clock::now();
    time_t most = std::chrono::system_clock::to_time_t(rendszerido);
    tm lokalis = *localtime(&most);
    ido = Datum(lokalis.tm_year+1900,lokalis.tm_mon+1,lokalis.tm_mday,lokalis.tm_hour,lokalis.tm_min);

    nev = "BUD";  // konstans, itt változtatható
}

Repuloter &Repuloter::getInstance()
{
    static Repuloter instance;
    return instance;
}

void Repuloter::szinkronizal(const std::chrono::system_clock::time_point &most)
{
    time_t most_t = std::chrono::system_clock::to_time_t(most);
    tm lokalis = *localtime(&most_t);
    ido = Datum(lokalis.tm_year+1900,lokalis.tm_mon+1,lokalis.tm_mday,lokalis.tm_hour,lokalis.tm_min);

}

std::string &Repuloter::getNev()
{
    return nev;
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
