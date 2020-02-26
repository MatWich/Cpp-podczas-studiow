#include<iostream>

int silnia(int);
int silniaV2(int);
long int potega(int, int);
long potegaV2(int,int);
long int fib(int);
void fibIteracyjnie();

void Horner_Iteracyjnie();
void Horner_Rekurencyjnie();

int main()
{
    int b, c, d, e;
    int a = 5;
    b = silnia(3);
    c = silniaV2(a);
    d = potega(a, 2);
    e = potegaV2(a, 3);
    
    std::cout <<"Potega iteracyjnie z "<< a << " " << "wynosi: " << e << std::endl;
    std::cout << "Potega rekurencyjnie z " << a << " " << "wynosi: " << d << std::endl;
    std::cout << "Silnia iteracyjna: "<< b << std::endl;
    std::cout << "Silnia rekurencyjnie: " << c << std::endl;
    std::cout << "Czwarty element ciagu figbonacziego wynosi: " << fib(4) << std::endl;
    //fibIteracyjnie();
    Horner_Iteracyjnie();

    return 0;

}


int silnia(int n)
{
    int s = n;
    while (--n) s *= n;
    return s;
}
int silniaV2(int a)
{
    int n = a;
    if (n == 0) return 1;
    else return(n * silniaV2(n - 1));


}

long int potega(int p, int w)
{
    if (w == 0) return 1;
    else return p * potega(p, w - 1);
}

long potegaV2(int p, int w)
{
    long int wynik = 1;
    while (w > 0)
    {

        wynik = wynik * p;
        w--;
    }
    return wynik;
}


long int fib(int n)
{
    if (n == 1 || n == 2) return 1;
    else return (fib(n - 1) + fib(n - 2));

}

void fibIteracyjnie()
{
    unsigned int ktora, wynik;
    std::cout << "Ktora liczbe z ciagu fibonacziego chcesz zobaczyc? ";
    std::cin >> ktora;
    std::cin.ignore();
    std::cout << std::endl;

    int a = 1, b = 1;

    if (ktora == 0)
    {
        wynik = 0;
    }
    else if (ktora == 1 || ktora == 2)
    {
        wynik = 1;
    }
    else
    {
        for (int i = 3; i <= ktora; i++)
        {
            wynik = a + b;
            a = b;
            b = wynik;
        }
    }

    std::cout << "Fib(" << ktora << ") " << "wyniosi: " << wynik << std::endl;
}

void Horner_Iteracyjnie()
{
    int stopien_wielomianu; 

    std::cout << "Podaj stopien wielomianu: ";
    std::cin >> stopien_wielomianu;
    std::cin.ignore();

    int* tab = new int[stopien_wielomianu];

    std::cout << "Podaj wartosci: " << std::endl;
        
    for (int i = 0; i <= stopien_wielomianu; i++)
    {
        std::cout << "tab[" << i << "] = ";
        std::cin >> tab[i];
        std::cin.ignore();
    }

    int x;

    std::cout << "Podaj x: ";
    std::cin >> x;
    std::cin.ignore();
    
    //na przyklad dla wielomianu 4 stopnia
    //(((5 * x + 2) * x + 1) * x + 20) * x + 1 

    int wynik = tab[0];

    for (int i = 0; i <= stopien_wielomianu; i++)
    {
        wynik = wynik * x + tab[i];
    }


    std::cout << "Wynik wynosi: " << wynik << std::endl;

    delete[] tab;
}
