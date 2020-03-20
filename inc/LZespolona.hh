#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


LZespolona utworz(double arg1, double arg2);
void wyswietl(LZespolona Skl);
LZespolona Sprzezenie(LZespolona Skl);
double Modul2(LZespolona Skl);

/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator *(LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator /(LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator /(LZespolona  Skl1,  double  Skl2);

#endif
