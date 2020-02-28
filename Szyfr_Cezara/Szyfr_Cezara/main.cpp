#include<iostream>
#include<string>

const int ile = 3;

//zamienia literki o 3 do przodu np zamiast a bedzie napisane d itd
std::string szyfr_cezara(std::string*);

std::string odszyfrowanie_cezara(std::string*);

int main()
{
	std::string tekst = "";
	std::cout << "Podaj slowo do zaszyfrowania: ";	std::cin >> tekst;	std::cin.ignore();

	std::cout << "Zaszyfrowany tekst: " << szyfr_cezara(&tekst) << std::endl;

	std::cout << "Odszyfrowany tekst: " << odszyfrowanie_cezara(&tekst) << std::endl;

	system("pause");
	return 0;
}

std::string szyfr_cezara(std::string* tekst)
{
	int temp  = 0;
	std::string slowo = *tekst;

	for (int i = 0; i < slowo.length(); i++)
	{

		temp = slowo[i] + ile;

		if (temp < 0)
		{
			slowo[i] += (255 + ile);
		}
		else if (temp > 255)
		{
			slowo[i] -= (255 - ile);
		}
		else
		{
			slowo[i] += ile;
		}
	}
	*tekst = slowo;
	return slowo;
}

std::string odszyfrowanie_cezara(std::string* tekst)
{
	int temp = 0;
	std::string slowo = *tekst;

	for (int i = 0; i < slowo.length(); i++)
	{
		temp = slowo[i] - ile;

		if (temp < 0) { slowo[i] += (255 - ile); }
		else if (temp > 255) { slowo[i] -= (255 + ile); }
		else { slowo[i] -= ile; }
	}
	*tekst = slowo;
	return slowo;
}