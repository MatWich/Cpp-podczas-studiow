#include<iostream>
#include<math.h>

bool czy_jest_Liczba_Pierwsza(int);
void generuj_liczby_pierwsze(int, int);
//madzejsze generowanie liczb pierwszych
void sito_Erastoteneta();
//podajemy dwie liczby i zwraca nam NWD czyli najwiekszy wspolny dzielnik
int Euklides_NWD(int, int);
//Prostsza wersja Euklides_NWD
int NWD(int, int);

void wielokrotnosc();

int main()
{


	//generuj_liczby_pierwsze(2, 10);
	//sito_Erastoteneta();
	std::cout << Euklides_NWD(238, 84) << std::endl;
	std::cout << NWD(238, 84) << std::endl;
	wielokrotnosc();
	system("pause");
	return 0;
}


bool czy_jest_Liczba_Pierwsza(int liczba)
{
	if (liczba <= 1)
	{
		return false;
	}

	for (unsigned int i = 2; i <= sqrt(liczba); i++)	//od 1 nie  ma sensu 
	{
		if (!(liczba % i))
		{
			return false;
		}
	}
	return true;
}


//liczba == od ktorej liczby ma generowac
//ile == ile liczb pierwszych ma wypluc funkcja na konsole
void generuj_liczby_pierwsze(int liczba, int ile)
{
	for (unsigned int i = 0; i < ile; i++)
	{
		if (czy_jest_Liczba_Pierwsza(liczba))
		{
			std::cout << i+1 << ". = " << liczba << std::endl;
		}
		else
		{
			i--;
		}
		liczba++;
	}
}

void sito_Erastoteneta()
{
	bool* tab = new bool;
	
	unsigned int ile, w;

	std::cout << "Do ktorej liczby mam wypisywac liczby pierwsze: ";	std::cin >> ile;	std::cin.ignore();
	
	//utawienie poczatkowe miejsc tablicy na true
	for (int i = 2; i <= ile; i++)
	{
		tab[i] = true;
	}
	//znajdowanie liczb pierwszych
	for (int i = 2; i <= ile; i++)
	{
		if ((i != 2) && (i % 2 == 0))	//zeby nie bylo duplikatow w while
		{
			i++;
		}

		w = i + i;
		while (w <= ile)
		{
			tab[w] = false;
			w += i;
		}
	}
	//wypisanie
	for (int i = 2; i <= ile; i++)
	{
		if (tab[i])
		{
			std::cout << i << ", ";
		}
	}



	delete[] tab;
}

int Euklides_NWD(int licznik, int mianownik)
{

	while (licznik != mianownik)
	{
		if (licznik > mianownik)
		{
			licznik = licznik - mianownik;
		}
		else
		{
			mianownik = mianownik - licznik;
		}
	}

	return licznik;
}

int NWD(int licznik, int mianownik)	//ulamek ma licznik i mianownik jak cos to nie jest odniesienie do petli
{
	int reszta;

	while (reszta = licznik % mianownik)
	{
		licznik = mianownik;
		mianownik = reszta;
	}
	return mianownik;
}

void wielokrotnosc()
{
	int liczba1, liczba2;

	std::cout << "Podaj pierwsza liczbe, ktora chcesz sprawdzic: "; std::cin >> liczba1;	std::cin.ignore();	std::cout << std::endl;
	std::cout << "Podaj pod katem jakiej liczby chcesz sprawdzic wielokrotnosc: "; std::cin >> liczba2;	std::cin.ignore();	std::cout << std::endl;

	if (liczba1 % liczba2 == 0)
	{
		std::cout << liczba1 << " jest wielokrotnoscia liczby " << liczba2 << std::endl;
	}
	else
	{
		std::cout << liczba1 << " nie jest wielokrotnoscia liczby " << liczba2 << std::endl;
	}
}
