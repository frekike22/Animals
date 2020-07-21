#include "Kedv.h"
#include "Allat.h"

using namespace std;


Vidam* Vidam::_instance = nullptr;
Vidam* Vidam::instance()
{
    if(_instance == nullptr)
    {
        _instance = new Vidam();
    }
    return _instance;
}
void Vidam::destroy()
{
    if ( nullptr!=_instance )
        delete _instance;
}

Kedv* Vidam::szamol(Tarantula *p)
{
    p->atalakit(1);
    return this;
}

Kedv* Vidam::szamol(Horcsog *p)
{
    p->atalakit(2);
    return this;
}
Kedv* Vidam::szamol(Macska *p)
{
    p->atalakit(3);
    return this;
}
// implementation of class Grass
Atlagos* Atlagos::_instance = nullptr;
Atlagos* Atlagos::instance()
{
    if(_instance == nullptr)
    {
        _instance = new Atlagos();
    }
    return _instance;
}
void Atlagos::destroy()
{
    if ( nullptr!=_instance )
        delete _instance;
}

Kedv* Atlagos::szamol(Tarantula *p)
{
    p->atalakit(-2);
    return this;
}

Kedv* Atlagos::szamol(Horcsog *p)
{
    p->atalakit(-3);
    return this;
}
Kedv* Atlagos::szamol(Macska *p)
{
    p->atalakit(3);
    return this;
}


// implementation of class Marsh
Szomoru* Szomoru::_instance = nullptr;
Szomoru* Szomoru::instance()
{
    if(_instance == nullptr)
    {
        _instance = new Szomoru();
    }
    return _instance;
}
void Szomoru::destroy()
{
    if ( nullptr!=_instance )
        delete _instance;
}

Kedv* Szomoru::szamol(Tarantula *p)
{
    p->atalakit(-3);
    return this;
}

Kedv* Szomoru::szamol(Horcsog*p)
{
    p->atalakit(-5);
    return this;
}
Kedv* Szomoru::szamol(Macska *p)
{
    p->atalakit(-7);
    return this;
}
