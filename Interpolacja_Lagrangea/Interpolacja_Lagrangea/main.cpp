//Interpolacja metoda Lagrange'a
//w pliku tekstowym jako pierwszy wiersz podajemy liczbe wezlow
//nastepnie punkty kazdy nastepny w nowej linii np. 3.0 4.0 \n -0.6 3

#include <iostream>
#include <fstream>
#include <string>
#include<conio.h>

void IntLagr();
void menu();
void decyzja_menu(char);

int main()
{
    for (;;)
    {
        system("cls");
        menu();
        char wybor; std::cin >> wybor;  std::cin.ignore();
        
        if (wybor != 'q')
        {
           decyzja_menu(wybor);
        }
        else
        {
            std::cout << "No to papa :D" << std::endl;
            break;
        }
        //std::cout << "Nacisnij enter by kontynuowac"; 
        //system("cls");	system("pause");
    }
   
    system("pause");
    return EXIT_SUCCESS;
}

void IntLagr()
{
    std::ifstream file("data.txt");  //otwiera plik do odczytu  nie stworzy nowego jesli nie ma go w folderze
    
    if (file.bad())
    {
        std::cout << "Plik nie istnieje sprawdz czy jest w folderze z programem" << std::endl;
        exit;
    }
    
    int liczba_wezlow;
    file >> liczba_wezlow;  //odczytujemy liczbê wêz³ów z pliku
   
    double* xtab = new double[liczba_wezlow];//tworzymy dynamiczn¹ tablicê o rozmiarze 2*iloœæ wêz³ów
    double * ytab = new double[liczba_wezlow]; //tablica z wêz³ami i wartoœciami funkcji w wêz³ach

    std::cout << "Liczba wezlow odczytana z pliku " << liczba_wezlow << std::endl;

    for (int i = 0; i < liczba_wezlow; i++) //dopóki istniej¹ wêz³y
    {
        file >> xtab[i]; //pobieramy wartoœci z pliku
        file >> ytab[i];
    }
    std::cout << std::endl;

    //wypisuje punkty
    for (int i = 0; i < liczba_wezlow; i++)
    {
        std::cout << "x" << i << ": " << xtab[i] << "\t";
        std::cout << "y" << i << ": " << ytab[i];
        std::cout << std::endl;
    }
    double punkt;            //punkt dla którego liczymy wartoœæ wielomianu
    std::cout << "Podaj punkt: ";
    std::cin >> punkt;
    double x = punkt;
    double y = 0.0;
   
    for (int i = 0; i < liczba_wezlow; i++)
    {
        double mul = ytab[i]; //ustawiamy mul na wartosci funkcji
        for (int j = 0; j < liczba_wezlow; j++)
        {
            if (i != j)
                mul *= (x - xtab[j]) / (xtab[i] - xtab[j]); //mul=y*(x-x0)/(x1-x0)
        }
        y += mul; //sumujemy
    }
    std::cout << "f(" << x << ") ~= " << y << std::endl;
    
    std::cout << "Nacisnij enter by kontynuowac"; 
    _getch();
    
    file.close();
}

void menu()
{
    std::cout << "              MENU " << std::endl;
    std::cout << "################################## " << std::endl;
    std::cout << "1. Interpolacja metoda Lagrange'a " << std::endl;
    std::cout << "q. Wyjscie z programu " << std::endl;
    std::cout << "################################## " << std::endl;
}

void decyzja_menu(char wybor)
{
    switch (wybor)
    {
    case '1':
        IntLagr();
        break;
    default:
        std::cout << "O tym lowco easter eggow ;)" << std::endl;
        break;
    }
}