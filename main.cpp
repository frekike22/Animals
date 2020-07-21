#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "Allat.h"
#include "Kedv.h"

using namespace std;

void letrehoz(const string &str, vector<Allat*> &allatok, vector<Kedv*> &napok)
{
    ifstream f (str);
    if(f.fail())
    {
        cout << "A fajl nem letezik!\n";
        exit(1);
    }


    int n;
    f >> n;
    allatok.resize(n);
    for( int i=0; i<n; ++i )
    {
        char ch;
        string nev;
        int p;
        f >> ch >> nev >> p;
        switch(ch)
        {
        case 'T' :
            allatok[i] = new Tarantula(nev, p);
            break;
        case 'H' :
            allatok[i] = new Horcsog(nev, p);
            break;
        case 'M' :
            allatok[i] = new Macska(nev, p);
            break;
        }

    }


    int m;
    f >> m;
    napok.resize(m);
    for( int j=0; j<m; ++j )
    {
        char k;
        f >> k;
        switch(k)
        {
        case 'v':
            napok[j] = Vidam::instance();
            break;
        case 'a' :
            napok[j] = Atlagos::instance();
            break;
        case 's' :
            napok[j] = Szomoru::instance();
            break;
        }

    }
}


void Gondoskodas(vector<Allat*> &allatok, vector<Kedv*> &napok, vector<int> &Eleteros)
{
    int maxEletero=allatok[0]->power();
    string maxNev = allatok[0]->name();

    unsigned int s=0;
    for( unsigned int i=0; i< allatok.size(); ++i )
    {

        for( unsigned  int j=0; j <napok.size(); ++j )
        {
            (allatok[i]->szamol(napok[j]));
            Eleteros.push_back(allatok[i]->power());
            if(Eleteros[i]>maxEletero)
            {
                maxEletero=Eleteros[i];
                maxNev=allatok[i]->name();

                if(allatok[j]->eleteros())
                {
                    s++;
                }
                if (s==(allatok.size()-1))
                {

                    if(napok[j]== Atlagos::instance())
                    {
                        napok[j]=Vidam::instance();
                    }
                    else if(napok[j]== Szomoru::instance())
                    {
                        napok[j]=Atlagos::instance();
                    }
                }



            }





        }

    }
    cout<<maxNev<<endl;
    cout<<maxEletero<<endl;
}




//Feladat:       Lények megszűntetése
//Bemenõ adatok: vector<Creature*> &creaturess  - lények pointereinek tömbje
//Tevékenység:   minden dinamikusan lefoglalt lényt töröl.
void destroy(vector<Allat*> &allatok)
{
    for(int i=0; i<(int)allatok.size(); ++i)
        delete allatok[i];
}

//Feladat:       Terepek megszűntetése
//Bemenõ adatok: vector<Creature*> &creaturess  - lények pointereinek tömbje
//Tevékenység:   minden dinamikusan lefoglalt terepet töröl.
void destroyKedv()
{
    Vidam::destroy();
    Atlagos::destroy();
    Szomoru::destroy();
}


//#define NORMAL_MODE

int main()
{
    vector<Allat*> allatok;
    vector<Kedv*> napok;
    vector<int> eleteros;
    vector<int> maxeleteros;
    vector<string> maxnev;

    letrehoz("bemenet.txt", allatok, napok );

    Gondoskodas(allatok,napok,eleteros);


    destroy(allatok);
    destroyKedv();
    return 0;
}

