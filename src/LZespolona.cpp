
#include "LZespolona.hh"



/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */



 struct Lzespolona{
    double .re;
    double.im;
  }typedef Lzespolona


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

utworz(arg1, arg2){
  Lzespolona Wynik;
  Wynik.re=arg1;
  Wynik.im=arg2;
   }return Wynik;

}
wyswietl(LZespolona){
  std::cout<<"("<<Skl.re<<showpos<<Skl.im<<
    noshowpos<<"i)";
}
