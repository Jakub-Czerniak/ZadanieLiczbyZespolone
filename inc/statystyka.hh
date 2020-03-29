#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

struct Statystyki
{
  int dobre;
  int wszys;
};

void wyzeruj(Statystyki &st);
void poprawne(Statystyki &st);
void niepoprawna(Statystyki &st);
int ile_dobrych(Statystyki &st);
int ile_wszystkich(Statystyki &st);
int procent_dobrych(Statystyki &st);

#endif
