#pragma once

#include <string>
#include "Kedv.h"

// class of abstract creatures
class Allat
{
protected:
    std::string nev;
    int eletero;
    Allat (const std::string &str, int e = 0) :nev(str), eletero(e) {}
public:
    std::string name() const
    {
        return nev;
    }
    int power() const
    {
        return eletero;
    }
    void atalakit(int p)
    {
        eletero += p;
    }
    bool eleteros() const
    {
        return eletero >= 5;
    }
    virtual void szamol(Kedv* &nap) = 0;
    virtual ~Allat () {}
};


class Tarantula : public Allat
{
public:
    Tarantula(const std::string &str, int e = 0) : Allat(str, e) {}
    void szamol(Kedv* &nap) override
    {
        nap = nap->szamol(this);
    }
};

class Horcsog : public Allat
{
public:
    Horcsog(const std::string &str, int e = 0) : Allat(str, e) {}
    void szamol(Kedv* &nap) override
    {
        nap = nap->szamol(this);
    }
};

class Macska: public Allat
{
public:
    Macska(const std::string &str, int e = 0) : Allat(str, e) {}
    void szamol(Kedv* &nap) override
    {
        nap = nap->szamol(this);
    }
};

