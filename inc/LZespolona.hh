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
bool operator ==(LZespolona Skl1, LZespolona Skl2);
bool operator != (LZespolona Skl1, LZespolona Skl2);
std::istream & operator >>(std::istream &wejsc, LZespolona &Skl);
std::ostream & operator <<(std::ostream &wyjsc, LZespolona Skl);
#endif
