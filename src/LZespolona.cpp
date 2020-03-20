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


void wyswietl(LZespolona Skl)
{
  std::cout<<"("<<Skl.re<<showpos<<Skl.im<<
    noshowpos<<"i)";
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

  Wynik.re = Skl1.re/Skl2;
  Wynik.im = Skl1.im/Skl2;
  return Wynik;
}

LZespolona operator /(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;
  Wynik=Skl1*Sprzezenie(Skl2)/Modul2(Skl2);
  return Wynik;
}



