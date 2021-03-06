#include<iostream>
#include "LZespolona.hh"

using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */




LZespolona utworz(double arg1, double arg2)
{
  LZespolona Wynik;
  
  Wynik.re=arg1;
  Wynik.im=arg2;
  return Wynik;
}



LZespolona Sprzezenie(LZespolona Skl)
{
  LZespolona Wynik;
  Wynik.re=Skl.re;
  Wynik.im=(-Skl.im);
  return Wynik;
}

  
double Modul2(LZespolona Skl)
{
  double Wynik;
  Wynik=Skl.re*Skl.re+Skl.im*Skl.im;
  return Wynik;
}


LZespolona  operator +(LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator -(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator *(LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2.re-Skl1.im*Skl2.im;
  Wynik.im = Skl1.re*Skl2.im+Skl1.im*Skl2.re;
  return Wynik;
}


LZespolona operator /(LZespolona Skl1, double Skl2)
{
  LZespolona Wynik;
  if(Skl2!=0)
    {
  Wynik.re = Skl1.re/Skl2;
  Wynik.im = Skl1.im/Skl2;
    }
  else
    {
      cerr<<"Dzielenie przez 0 jest niedozwolone.";
      exit(1);
    }
  return Wynik;
}

LZespolona operator /(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;
  Wynik=Skl1*Sprzezenie(Skl2)/Modul2(Skl2);
  return Wynik;
}

bool operator ==(LZespolona Skl1, LZespolona Skl2)
{
  if(abs(Skl1.re-Skl2.re)<0.00001 && abs(Skl1.im-Skl2.im)<0.00001)
    return true;
  return false;
}

bool operator != (LZespolona Skl1, LZespolona Skl2)
{
  return !(Skl1==Skl2);
}

std::istream & operator >>(std::istream &wejsc, LZespolona &Skl)
{
  char znak;
  
  wejsc>>znak;
  if(znak != '(')
    wejsc.setstate(std::ios::failbit);
  wejsc>>Skl.re>>Skl.im>>znak;
  if(znak != 'i')
    wejsc.setstate(std::ios::failbit);
  wejsc>>znak;
  if (znak != ')')
    wejsc.setstate(std::ios::failbit);
  return wejsc;
}

std::ostream & operator <<(std::ostream &wyjsc, LZespolona Skl)
{
  wyjsc<<"("<<Skl.re<<showpos<<Skl.im<<noshowpos<<"i)";
  return wyjsc;
}
