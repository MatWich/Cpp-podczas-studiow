#include<iostream>
#include<ctime>

void Menu();
void Decyzja_po_menu(int);
double PoleKwadratu(double);
double PoleKola(double);
double PoleTrojkata(double, double);
double PoleProstokata(double, double);

int main()
{
	for (;;)
	{

		Menu();
		int wybor = 0;
		std::cin >> wybor;
		if (wybor != 5)
		{
			Decyzja_po_menu(wybor);
		}
		
		else
			break;
		//std::cout << "Nacisnij enter by kontynuowac"; 
		//system("cls");	system("pause");
	}
	
	return 0; 
}

void Menu()
{
	std::cout <<"WYBIERZ OPCJE: "<< std::endl;
	std::cout << "/////////////////////////////" << std::endl;
	std::cout << "// 1.Pole kola             //" << std::endl;
	std::cout << "// 2.Pole kwadratu:        //" << std::endl;
	std::cout << "// 3.Pole prostokata       //" << std::endl;
	std::cout << "// 4.Pole trojkata         //" << std::endl;
	std::cout << "// 5.Wychodzisz z programu //" << std::endl;
	std::cout << "/////////////////////////////" << std::endl;
}

double PoleKwadratu(double bok)
{
	bok *= bok;
	std::cout << "Pole kwadratu wynosi: " << bok << std::endl;
	return bok;
}

double PoleProstokata(double bok_krotszy, double bok_dluzszy)
{
	double pole_prostokata = bok_krotszy * bok_dluzszy;
	std::cout << "Pole prostokata wynosi: " << pole_prostokata << std::endl;
	return pole_prostokata;
}

double PoleTrojkata(double bok, double wysokosc)
{
	double pole_trojkata = (bok * wysokosc) / 2;
	std::cout << "Pole trojkata wynosi: " << pole_trojkata << std::endl;
	return pole_trojkata;
}

double PoleKola(double promien)
{
	const double PI =  3.14;
	double pole_kola = PI * promien * promien;
	std::cout << "Promien kola wynosi: " << promien << " " <<"Pole kola wynosi: " << pole_kola << std::endl;
	return pole_kola;
}

void Decyzja_po_menu(int wybor)
{
	double promien, wysokosc, bok, bok_krotszy, bok_dluzszy;
	switch (wybor)
	{
	case 1:
		std::cout << "Podaj promien kola: " << std::endl;	std::cin >> promien;
		PoleKola(promien);
		break;
	case 2:
		std::cout << "Podaj dlugosc boku kwadratu: " << std::endl;
		 std::cin >> bok;	PoleKwadratu(bok);
		break;
	case 3:
		 std::cout << "Podaj bok krotszy: "; std::cin >> bok_krotszy;
		std::cout << "i bok dluzszy: ";	std::cin >> bok_dluzszy;	
		PoleProstokata(bok_dluzszy, bok_krotszy);
		break;
	case 4:
		std::cout << "Podaj bok: "; std::cin >> bok;
		std::cout << "Podaj wysokosc: "; std::cin >> wysokosc;	
		PoleTrojkata(wysokosc, bok);
		break;
	default:
		std::cout << "Nie ma takiej opcji w menu ale milo ze sprobowales :D" << std::endl;
		break;
	}
}