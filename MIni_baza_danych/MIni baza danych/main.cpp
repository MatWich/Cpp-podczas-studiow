#include<iostream>
#include<conio.h>	//zeby miec _getch()
#include<stdlib.h>
#include<fstream>	//do ofstream

#define MIEJSCE_W_BAZIE 20

void wymagaj_entera();
void dodajOsobe();
void pokaz_osoby_w_bazie();
void zapisz_do_pliku();
void wczytaj_z_pliku();
void przeszukaj();
void usun_kogos();

struct Czlowiek
{
	std::string imie;
	std::string nazwisko;
	short wiek;
	std::string telefon;
};

short ileDodanoOsob;	//zmienna globalna ma na poczatku 0 przypisane
Czlowiek ludzie[MIEJSCE_W_BAZIE];

int main()
{
	char wybor;
	
	do
	{
		std::cout << "Osob w bazie jest: " << ileDodanoOsob << " " << std::endl;
		std::cout << "MENU" << std::endl;
		std::cout << "1. Dodaj osobe " << std::endl;
		std::cout << "2. Pokaz osobe " << std::endl;
		std::cout << "3. Zapisz osoby do plliku " << std::endl;
		std::cout << "4. Wcztaj osoby z pliku " << std::endl;
		std::cout << "5. Przeszukaj baze " << std::endl;
		std::cout << "6. Usun osobe z bazy  " << std::endl;
		std::cout << "NACISNIJ Q ABY ZAKONCZYC PROGRAM" << std::endl;

		wybor = _getch();	//nie trzeba pootwierdzac enterem

		switch (wybor)
		{
		case '1':
			std::cout << "Wybrales opcje \"Dodaj osobe\"" << std::endl;
			dodajOsobe();
			break;
		case '2':
			std::cout << "Wybrales opcje \"Pokaz osobe\"" << std::endl;
			pokaz_osoby_w_bazie();
			break;
		case '3':
			std::cout << "Wybrales opcje \"Zapisz osoby do pliku\" " << std::endl;
			zapisz_do_pliku();
			break;
		case '4':
			std::cout << "Wybrales opcje \"Wczytaj osoby z pliku\" " << std::endl;
			wczytaj_z_pliku();
			std::cout << std::endl << "Wczytano osoby z \"baza.txt\" " << std::endl;
			break;
		case '5':
			std::cout << "Wybrales opcje \"Przeszukania bazy\" " << std::endl;
			przeszukaj();
			break;
		case '6':
			std::cout << "Wybrales opcje \" Usun osobe z bazy\" " << std::endl;
			usun_kogos();
			break;
		}
		wymagaj_entera();
		system("cls");

	} while (wybor != 'q');

	

	system("pause");
	return 0;
}

void wymagaj_entera()
{
	std::cout << "Wcisnij ENTER aby kontynuowac" << std::endl;
	while (_getch() != 13);

}

void dodajOsobe()
{
	if (ileDodanoOsob < MIEJSCE_W_BAZIE)
	{
		std::cout << "Podaj imie: ";
		std::cin >> ludzie[ileDodanoOsob].imie;

		std::cout << "Podaj nazwisko: ";
		std::cin >> ludzie[ileDodanoOsob].nazwisko;

		std::cout << "Podaj wiek: ";
		std::cin >> ludzie[ileDodanoOsob].wiek;

		std::cout << "Podaj numer telefonu: ";
		std::cin >> ludzie[ileDodanoOsob].telefon;

		ileDodanoOsob++;
	}
	else
	{
		std::cout << "Overflow. Usun kogos najpierw z bazy nie bedzie bolalo... Chyba" << std::endl;
	}
}

void pokaz_osoby_w_bazie()
{
	if (ileDodanoOsob > 0)
	{
		for (int i = 0; i < ileDodanoOsob; i++)
		{
			std::cout << "Osoba o numerze: " << i + 1 << std::endl;
			std::cout << "DANE PERSONALNE" << std::endl;
			std::cout << "IMIE: " << ludzie[i].imie << std::endl;
			std::cout << "NAZWISKO: " << ludzie[i].nazwisko << std::endl;
			std::cout << "WIEK: " << ludzie[i].wiek << std::endl;
			std::cout << "TELEFON: " << ludzie[i].telefon << std::endl;
			std::cout << "------------------- " << std::endl;
		}
	}
	else
	{
		std::cout << "Czy ty  wiesz ile to jest ZERO osob NULL 0 no nie wiem jak to wytlumaczyc" << std::endl;
	}
}

void zapisz_do_pliku()
{
	std::ofstream file("baza.txt");

	if (file.is_open())
	{
		file << ileDodanoOsob << std::endl;
		for (int i = 0; i < ileDodanoOsob; i++)
		{
			file << ludzie[i].imie << std::endl;
			file << ludzie[i].nazwisko << std::endl;
			file << ludzie[i].wiek << std::endl;
			file << ludzie[i].telefon << std::endl;
		}
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku" << std::endl;
	}

	file.close();

}

void wczytaj_z_pliku()
{
	std::ifstream file("baza.txt");

	if (file.is_open())
	{
		file >> ileDodanoOsob;

		for (int i = 0; i < ileDodanoOsob; i++)
		{
			file >> ludzie[i].imie;
			file >> ludzie[i].nazwisko;
			file >> ludzie[i].wiek;
			file >> ludzie[i].telefon;
		}

		file.close();
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku moze warto go najpierw utworzyc?" << std::endl;
	}
}

void przeszukaj()
{
	if (ileDodanoOsob != 0)
	{
		std::string imie;
		std::cout << "Podaj imie a ja znajde juz ta osobe :W " << std::endl;
		std::cin >> imie;

		for (int i = 0; i < ileDodanoOsob; i++)
		{
			if (imie == ludzie[i].imie)
			{
				std::cout << "Znaleziono ma numer: " << i +1 << std::endl;
				std::cout << "DANE PERSONALNE" << std::endl;
				std::cout << "------------------- \n" << std::endl;
				std::cout << "IMIE: " << ludzie[i].imie << std::endl;
				std::cout << "NAZWISKO: " << ludzie[i].nazwisko << std::endl;
				std::cout << "WIEK: " << ludzie[i].wiek << std::endl;
				std::cout << "TELEFON: " << ludzie[i].telefon << std::endl;
				std::cout << "------------------- \n" << std::endl;
				//break;	//mozna odkomentowac jesli jest zawsze tylko jedna osoba o takim imieniu w bazie
			}
		}
	}
	else
	{
		std::cout << "Nie ma nikogo w domu " << std::endl;
	}
}

void usun_kogos()
{
	if (ileDodanoOsob != 0)
	{
		short index;
		std::cout << "Podaj numer osoby w bazie ktora chcesz usunac: ";
		std::cin >> index;
		std::cout << std::endl;

		for (short i = index; i < ileDodanoOsob; i++)
		{
			ludzie[i - 1].imie = ludzie[i].imie;
			ludzie[i - 1].nazwisko = ludzie[i].nazwisko;
			ludzie[i - 1].wiek = ludzie[i].wiek;
			ludzie[i - 1].telefon = ludzie[i].telefon;
		}
		ileDodanoOsob--;

		std::cout << "Uzytkownik o indexie: " << index << " zostal elegancko usuniety z bazy danych " << std::endl;

		//zapisz_do_pliku() //niby warto ale mozna usunac przez przypadek kogos i juz nie ma powrotu
		std::cout << "Pamietaj o zapisaniu zmian :D " << std::endl;
		
		
	}
	else
	{
		std::cout << "No chyba juz tylko siebie chcesz usunac ;)" << std::endl;
		std::cout << "REMINDER: \"Nie zapominaj o zapisaniu pliku opcja 3 \" ~ Paulo Coelho " << std::endl;
	}
}