#include <iostream>
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "statystyka.hh"
#include "BazaTestu.hh"

using namespace std;




int main(int argc, char **argv)
{
  BazaTestu   BazaT = { nullptr, 0, 0 };
  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona LZes_Odp;
  Statystyki stat;
  int il_prob;
  
 
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }
  

  if (InicjalizujTest(&BazaT,argv[1],stat) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;


  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << "Twoje pytanie: ";
    cout << WyrZ_PytanieTestowe << endl;
    cout << "Twoja odpowiedź: ";
    cin >> LZes_Odp;
    for(il_prob=2;!cin.good();il_prob--)
      {
	if(il_prob==0)
	  {
	    cerr << "Przekroczono liczbę prób wpisania technicznie poprawnej liczby."; 
	    exit(1);
	  }
	cin.clear();
	cin.ignore(10000,'\n');
	cout << "Wpisz liczbę w formacie (x(+ lub -)yi)"<< endl;
	cout << "Zostało prób: " << il_prob <<endl;
	cin >> LZes_Odp;
      }
    
    if(Oblicz(WyrZ_PytanieTestowe)==LZes_Odp)
      {
	cout <<"Odpowiedź poprawna." <<endl;
	cout << endl;
	poprawne(stat);
      }
    else
      {
	cout <<"Odpowiedź niepoprawna. Prawidłową odpowiedzią jest: "<< Oblicz(WyrZ_PytanieTestowe) <<endl;
	cout << endl;
	niepoprawna(stat);
      }    
  }

  
  cout << endl;
  cout << "Statystyki końcowe:" <<endl;
  cout << "Ilość poprawnych: " << ile_dobrych(stat) << endl;
  cout << "Ilość wszytskich: " << ile_wszystkich(stat) << endl;
  cout << "Procent poprawnych: " << procent_dobrych(stat) << "%" << endl;
  cout << "Koniec testu." << endl;
  cout << endl;

}
