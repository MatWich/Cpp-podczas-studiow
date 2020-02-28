#include<iostream>
#include<conio.h>	//do _getch()

void zakoncz_program();
void haslo();	//wczytuje i sprawdza czy haslo jest inteligentne

int main()
{

	haslo();
	zakoncz_program();
	system("pause");
	return 0;
}

void zakoncz_program()
{
	char odpowiedz[1];
	std::cout << "Czy chcesz zakonczyc program? (T/N)" << std::endl;	std::cin >> odpowiedz;	std::cin.ignore();	std::cout << std::endl;

	odpowiedz[0] = toupper(odpowiedz[0]);

	if (odpowiedz[0] == 'T')
	{
		std::cout << "Adios do nastepnego :D" << std::endl;
		_getch();
	}
	else if (odpowiedz[0] == 'N')
	{
		main();
	}
	else
	{
		zakoncz_program();	//nie ma podawania innych  literek !!!
	}
}

void haslo()
{

	std::string hasla;
	short dlugosc_hasla;
	int i, j, k, l;	//licznik sprawdzajace co zostalo podane

	while (true)
	{
		j = 0;	k = 0; l = 0; i = -1;

		std::cout << "Podaj inteligentne haslo: ";	std::cin >> hasla;	std::cin.ignore();	std::cout << std::endl;

		dlugosc_hasla = hasla.length() -1;

		while (i < dlugosc_hasla)
		{
			i++;

			if (hasla[i] >= '0' && hasla[i] <= '9')
			{
				j++;
			}
			else if (hasla[i] >= 'a' && hasla[i] <= 'z')
			{
				k++;
			}
			else if (hasla[i] >= 'A' && hasla[i] <= 'Z')
			{
				l++;
			}
			if (j != 0 && l != 0 && k != 0)
			{
				break;
			}
		}
		
		if (j != 0 && l != 0 && k != 0)
		{
			std::cout << "Haslo jest inteligentne :D" << std::endl;
			break;
		}
		if (j == 0)
		{
			std::cout << "\n Nie wpisales zadnej cyfry :(" << std::endl;
		}
		if (k == 0)
		{
			std::cout << "\n Nie wpisales zadnej malej litery :(" << std::endl;
		}
		if (l == 0)
		{
			std::cout << "\n Nie wpisales zadnej DUZEJ litery :(" << std::endl;
		}
	}
}