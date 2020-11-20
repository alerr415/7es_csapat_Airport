#ifndef JARAT_H
#define JARAT_H

#include <string>
#include "datum.h"

class Jarat
{
private:
    std::string jaratAzonosito, honnan, hova;
    Datum erkezes, indulas;
    unsigned keses;
public:
    Jarat(std::string _jaratAzonosito, std::string _honnan, std::string _hova, const Datum& _erkezes, const Datum& _indulas, unsigned _keses);
    void print() const;

    std::string getJaratAzonosito() const;
    void setJaratAzonosito(const std::string &value);

    std::string getHonnan() const;
    void setHonnan(const std::string &value);

    std::string getHova() const;
    void setHova(const std::string &value);

    Datum getErkezes() const;
    void setErkezes(const Datum &value);

    Datum getIndulas() const;
    void setIndulas(const Datum &value);

    unsigned getKeses() const;
    void setKeses(const unsigned &value);
};

#endif // JARAT_H
