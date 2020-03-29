
#include "statystyka.hh"


void wyzeruj(Statystyki &st)
{
  st.dobre=0;
  st.wszys=0;
}

void poprawne(Statystyki &st)
{
  st.dobre= st.dobre+1;
  st.wszys= st.wszys+1;
}

void niepoprawna(Statystyki &st)
{
  st.wszys= st.wszys+1;
}

int ile_dobrych(Statystyki &st)
{
  return st.dobre;
}

int ile_wszystkich(Statystyki &st)
{
  return st.wszys;
}

int procent_dobrych(Statystyki &st)
{
  int procent;
  procent=100*st.dobre/st.wszys;
  return procent;
}


