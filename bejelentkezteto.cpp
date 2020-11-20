#include "bejelentkezteto.h"

Bejelentkezteto::Bejelentkezteto()
{

}

Bejelentkezteto &Bejelentkezteto::getInstance()
{
    static Bejelentkezteto instance;
    return instance;
}
