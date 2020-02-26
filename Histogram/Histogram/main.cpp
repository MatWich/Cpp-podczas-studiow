#include<iostream>

using namespace std;

void histogram();

int main()
{
    histogram();
    return 0;
}


void histogram()
{
    int c, temp = 0;

    int character[123];   //jezyk ANCII
    //0-9
    for (int i = 48; i < 58; ++i) character[i] = 0;
    //A-Z
    for (int i = 65; i < 91; ++i) character[i] = 0;
    //a-z
    for (int i = 97; i < 123; ++i) character[i] = 0;

    std::cout << "Wpisz jakies literki jakie tylko chcesz :D : \n";


    //czytanie tekstu do napotkania znaku nowej lini [enter]
    while ((c = getchar()) != '\n' && c != EOF)
    {
        ++character[c];
    }

    //0-9 wypisanie histogramu
    for (int i = 48; i < 58; ++i) {
        putchar(i);
        for (int j = 0; j < character[i]; ++j) {
            temp++;
            //putchar('*');     //gdyby sie chcialo miec gwiazdki bo liczby sa za nudne :D
        }
        printf(" - %d \n", temp);
        temp = 0;
    }
    //A-Z wypisanie histogramu
    for (int i = 65; i < 91; ++i) {
        putchar(i);

        for (int j = 0; j < character[i]; ++j) {
            temp++;
            //putchar('*');         //gdyby sie chcialo miec gwiazdki bo liczby sa za nudne :D
        }
        std::cout << "- " << temp << std::endl;
        temp = 0;
    }
    //a-z wypisanie histogramu
    for (int i = 97; i < 123; ++i) {
        putchar(i);

        for (int j = 0; j < character[i]; ++j) {
            temp++;
            //  putchar('*');           //gdyby sie chcialo miec gwiazdki bo liczby sa za nudne :D
        }
        std::cout << "- " << temp << std::endl;
        temp = 0;
    }
}