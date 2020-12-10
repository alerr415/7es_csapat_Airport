#include "jarat.h"

std::string Jarat::getJaratAzonosito() const
{
    return jaratAzonosito;
}

void Jarat::setJaratAzonosito(const std::string &value)
{
    jaratAzonosito = value;
}

std::string Jarat::getHonnan() const
{
    return honnan;
}

void Jarat::setHonnan(const std::string &value)
{
    honnan = value;
}

std::string Jarat::getHova() const
{
    return hova;
}

void Jarat::setHova(const std::string &value)
{
    hova = value;
}

const Datum& Jarat::getErkezes() const
{
    return erkezes;
}

void Jarat::setErkezes(const Datum &value)
{
    erkezes = value;
}

const Datum& Jarat::getIndulas() const
{
    return indulas;
}

void Jarat::setIndulas(const Datum &value)
{
    indulas = value;
}

unsigned Jarat::getKeses() const
{
    return keses;
}

void Jarat::setKeses(const unsigned &value)
{
    keses = value;
}

Jarat::Jarat(std::string _jaratAzonosito, std::string _honnan, std::string _hova, const Datum& _indulas, const Datum& _erkezes, unsigned _keses):
    jaratAzonosito(_jaratAzonosito),
    honnan(_honnan),
    hova(_hova),
    erkezes(_erkezes),
    indulas(_indulas),
    keses(_keses)
{

}



std::ostream& operator <<(std::ostream &stream, const Jarat &jarat)
{
    stream << jarat.jaratAzonosito << " "
           << jarat.honnan << " "
           << jarat.hova << " "
           << jarat.indulas << " "
           << jarat.erkezes << " "
           << jarat.keses << std::endl;
    return stream;
}
