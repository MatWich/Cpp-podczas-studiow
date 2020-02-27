#include<iostream>

//110101 = 1* 2^5 +1 *2^4 + 0 * 2^3 + 1 * 2^2 + 0 * 2^1 + 1 * 2^0

void dziesietny_na_binarny();
void dwojkowy_na_dziesietny();

int main()
{

	//dziesietny_na_binarny();
	dwojkowy_na_dziesietny();
	system("pause");
	return 0;
}

void dziesietny_na_binarny()
{
	int liczba, wynik = 0;
	int tab[100] = { 0 };
	std::cout << "Podaj liczbe dziesietna ktora chcesz zamienic na binarna: ";	std::cin >> liczba;	std::cin.ignore();
	std::cout << std::endl;

	int i = 0;	//miejsce np i = 0 odpowiada 1 lub 0 * 2^0

	do
	{
		i++;
		tab[i] = liczba % 2;
		liczba = liczba / 2;
		wynik = 2 * liczba + tab[i];
	} while (wynik >= 2);

	std::cout << "Liczba w systemie dwojkowym wyglada: ";

	for (; i > 0;)
	{
		std::cout << tab[i];
		i--;
	}
}

void dwojkowy_na_dziesietny()
{
	std::string liczba;
	int wynik = 0;

	std::cout << "Podaj liczbe w systemie dwojkowym: ";	std::cin >> liczba;	std::cin.ignore();

	for (short i = 0; i < liczba.length(); i++)
	{
		if (liczba[i] == '1')
		{
			wynik = wynik * 2 + 1;
		}
		else
		{
			wynik = wynik * 2;
		}
	}

	std::cout << "Liczba w systemie dwojkowy jest rowna: " << wynik << std::endl;
}