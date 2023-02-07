#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void test1();

class Ksztalt
{
public:
    virtual float oblicz_pole()=0;
};

class Kolo: public Ksztalt
{
private:
    float r;
public:
    Kolo(float x=1)
    {
        r = x;
    }
    virtual float oblicz_pole()
    {
        cout<<"Pole koła wynosi: "<<3.14*r*r;
    }
};

class Prostokat: public Ksztalt
{
private:
    float szer, wys;
public:
    Prostokat(float s=1, float w=1)
    {
        szer = s;
        wys = w;
    }
    virtual float oblicz_pole()
    {
        cout<<"Pole czworokąta wynosi: "<<wys*szer;
        return wys*szer;
    }

};

float pole_obiektu(Ksztalt* w)
{
    return w -> oblicz_pole();
}


/*
funkcja wirtualna write
Klasy - 1. klasa przechowująca tekst do wyświetlenia w terminalu
2. klasa przechowująca tekst do zapisu do pliku - metoda write do zapisu
Napisać program, który będzie zapisywał
*/

class Out //klasa nadrzędna
{
public:
    virtual void write_out()=0;
};

/*
Klasa przechowująca informację o pliku do zapisu, lokalizacja
*/
class File_out: public Out
{
private:
    string name;
    FILE* f;

public:
    File_out(string n)
    {
        name = n;
        f = fopen(name.c_str(), "a+");
    }
    ~File_out()
    {
        fclose(f);
    }
    void write_out()
    {
        fprintf(f, "hello\n");
    }


};

class Terminal_out: public Out
{
private:
    string disp;
public:
    Terminal_out(string d="000")
    {
        disp = d;
    }
    void write_out()
    {
        cout<<disp<<endl;
    }

};

void wypisz_obiekt(Out* o)
{
    o -> write_out();
}

int main()
{
    File_out plik1("hello.txt");
    string s;

    cout<<"Podaj tekst: ";
    cin>>s;

    Terminal_out term1(s.c_str());

    Terminal_out* a = new Terminal_out[2];

//Mamy listę obiektów

    a[0] = term1;

    for(int i=0; i<2; i++)
    {
//       wypisz_obiekt(a[i]);
    }

    return 0;
}

void test1()
{
    Kolo ko(5);
    Prostokat p1(5,9);
    Prostokat a(1,1);

    int wybor;

    cout<<"Wpisz liczbę: ";
    cin>>wybor;
    cout<<endl;

    Ksztalt* wsk;
    if(wybor == 0)
    {
       wsk = &p1;
    }
    else if(wybor == 1)
    {
        wsk = &ko;
    }
    else
    {
        wsk = &a;
    }

    wsk -> oblicz_pole();
}
