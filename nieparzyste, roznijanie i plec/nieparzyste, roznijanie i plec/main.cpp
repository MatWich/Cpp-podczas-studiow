#include<iostream>
#include<string>

void Odgadnij_plec();
void generowanie_liczb_nieparzystych();
void rozbijanie_liczby();

int main()
{

	//Odgadnij_plec();
	//generowanie_liczb_nieparzystych();
	rozbijanie_liczby();
	system("pause");
	return 0;
}

void Odgadnij_plec()
{
	std::string imie;
	std::cout << "Podaj swoje imie: " << std::endl;	std::cin >> imie;	std::cin.ignore();

	int dlugosc_slowa = imie.length();

	if (imie[dlugosc_slowa - 1] == 'a' || imie[dlugosc_slowa - 1] == 'A')
	{
		std::cout << "Oczywiscie ze kobita :D " << std::endl;
	}
	else
	{
		std::cout << "Oczywiscie ze chlop :D " << std::endl;
	}


}

void generowanie_liczb_nieparzystych()
{
	int ile, ktora = 0;
	std::cout << "Ile liczb nieparzystych wypisac: " << std::endl;	std::cin >> ile;	std::cin.ignore();

	for (int i = 1; i < ile * 2; i++)
	{
		if (i % 2 == 1)	//innej reszty z dzielenia poza zerem nie moze byc
		{
			ktora++;
			std::cout << ktora << ". = " << i <<std::endl;
		}
	}
}

void rozbijanie_liczby()
{
	std::string liczba;
	short int finger = 0;

	std::cout << "Podaj liczbe do rozbicia: ";	std::cin >> liczba;	std::cin.ignore();	std::cout << std::endl;

	for (int i = 0; i < liczba.length(); i++)
	{
		if (liczba[i] == 44 || liczba[i] == 46)		//przecinek i kropka
		{
			finger = i;
		}
	}
	std::cout << "Przed znakiem: " << std::endl;
	
	if (liczba[0] != '-')
	{	
		//wypisanie
		for (int i = 0; i < liczba.length(); i++)
		{
			if (i < finger || i > finger)
			{
				std::cout << liczba[i] << std::endl;
			}
			else if (i == finger)
			{
				std::cout << "Po znaku: " << std::endl;
			}
		}
	}
	else
	{
		for (int i = 1; i < liczba.length(); i++)
		{
			liczba[i - 1] = liczba[i];
		}
		finger--;
		liczba[liczba.length() - 1] == '\0';	//zeby nie zwiekszalo ilosci cyfr
		
		//wypisanie
		for (int i = 0; i < liczba.length(); i++)
		{
			if (i < finger || i > finger)
			{
				std::cout << liczba[i] << std::endl;
			}
			else if (i == finger)
			{
				std::cout << "Po znaku: " << std::endl;
			}
		}
	}
	
}