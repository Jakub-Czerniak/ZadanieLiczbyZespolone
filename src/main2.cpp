#include "BazaTestu.hh"

using namespace std;




int main()
{
  Lzespolona Skl1, Skl2, Skl3;
  Skl1=utworz(2,3);
  wyswietl(Skl1);
  Skl2=utworz(2,-4);
  wyswietl(Skl2);
  Skl3=Skl1+Skl2;
  wyswietl(Skl3);
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }
