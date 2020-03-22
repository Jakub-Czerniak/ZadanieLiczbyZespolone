#include<iostream> 
#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

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
