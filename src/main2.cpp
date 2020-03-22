#include<iostream>
using namespace std;


struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};

enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};





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

void Wyswietl(WyrazenieZesp WyrZ)
{
  wyswietl(WyrZ.Arg1);
    switch(WyrZ.Op)
      {
      case Op_Dodaj: cout<<"+";
	break;
      case Op_Odejmij: cout<<"-";
	break;
      case Op_Mnoz: cout<<"*";
	break;
      case Op_Dziel: cout<<"/";
	break;
      }
    wyswietl(WyrZ.Arg2);
}



LZespolona Oblicz(WyrazenieZesp WyrZ)
{
  LZespolona Wynik;
  
 switch(WyrZ.Op)
  {
  case Op_Dodaj: Wynik= WyrZ.Arg1+WyrZ.Arg2;
    break;
  case Op_Odejmij: Wynik= WyrZ.Arg1-WyrZ.Arg2;
    break;
  case Op_Mnoz: Wynik= WyrZ.Arg1*WyrZ.Arg2;
    break;
  case Op_Dziel: Wynik= WyrZ.Arg1/WyrZ.Arg2;
    break;
  }
  
  return Wynik;
}
    
std::istream & operator >>(std::istream &wejsc, WyrazenieZesp &WyrZ)
{
  char znak;
  
  wejsc >> WyrZ.Arg1 >> znak >> WyrZ.Arg2;
  switch(znak)
    {
    case'+': WyrZ.Op=Op_Dodaj;
      break;
    case'-': WyrZ.Op=Op_Odejmij;
      break;
    case'*': WyrZ.Op=Op_Mnoz;
      break;
    case'/': WyrZ.Op=Op_Dziel;
      break;
    }
  return wejsc;
}


std::ostream & operator <<(std::ostream &wyjsc, WyrazenieZesp WyrZ)
{
  wyjsc<<WyrZ.Arg1;
  switch(WyrZ.Op)
    {
    case Op_Dodaj: wyjsc<<"+";
      break;
    case Op_Odejmij: wyjsc<<"-";
      break;
    case Op_Mnoz: wyjsc<<"*";
      break;
    case Op_Dziel: wyjsc<<"/";
      break;
    }
  wyjsc<<WyrZ.Arg2;
  return wyjsc;
}


int main()
{
  WyrazenieZesp WyrZ;
  LZespolona Arg1;
  
  cin >>WyrZ;
  cout<<WyrZ;
  Arg1=Oblicz(WyrZ);
  cout<<Arg1;
}

