#pragma once

#include <string>

class Tarantula;
class Horcsog;
class Macska;

// class of abstract grounds
class Kedv
{
public:
    virtual Kedv* szamol(Tarantula *p) = 0 ;
    virtual Kedv* szamol(Horcsog *p) = 0;
    virtual Kedv* szamol(Macska *p) = 0 ;
    virtual ~Kedv() {}
};

// class of sand
class Vidam : public Kedv
{
public:
    static Vidam* instance();
    Kedv* szamol(Tarantula *p) override;
    Kedv* szamol(Horcsog *p) override;
    Kedv* szamol(Macska *p) override;
    static void destroy() ;
protected:
    Vidam() {}
private:
    static Vidam* _instance;
};

class Atlagos : public Kedv
{
public:
    static Atlagos* instance();
    Kedv* szamol(Tarantula *p) override;
    Kedv* szamol(Horcsog *p) override;
    Kedv* szamol(Macska *p) override;
    static void destroy() ;
protected:
    Atlagos() {}
private:
    static Atlagos* _instance;
};


class Szomoru : public Kedv
{
public:
    static Szomoru* instance();
    Kedv* szamol(Tarantula *p) override;
    Kedv* szamol(Horcsog *p) override;
    Kedv* szamol(Macska *p) override;
    static void destroy() ;
protected:
    Szomoru() {}
private:
    static Szomoru* _instance;
};
