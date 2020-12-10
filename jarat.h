#ifndef JARAT_H
#define JARAT_H

#include <string>
#include "datum.h"
#include <iostream>

class Jarat
{
private:
    std::string jaratAzonosito, honnan, hova;
    Datum erkezes, indulas;
    unsigned keses;
public:
    Jarat() = default;
    Jarat(std::string _jaratAzonosito, std::string _honnan, std::string _hova, const Datum& _indulas,  const Datum& _erkezes,unsigned _keses);
    void print() const;

    std::string getJaratAzonosito() const;
    void setJaratAzonosito(const std::string &value);

    std::string getHonnan() const;
    void setHonnan(const std::string &value);

    std::string getHova() const;
    void setHova(const std::string &value);

    const Datum& getErkezes() const;
    void setErkezes(const Datum &value);

    const Datum& getIndulas() const;
    void setIndulas(const Datum &value);

    unsigned getKeses() const;
    void setKeses(const unsigned &value);

    friend std::ostream& operator <<(std::ostream& stream, const Jarat& jarat);
};

std::ostream& operator <<(std::ostream& stream, const Jarat& jarat);

#endif // JARAT_H
