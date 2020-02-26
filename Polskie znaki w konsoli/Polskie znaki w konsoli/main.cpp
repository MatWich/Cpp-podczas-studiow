#include <iostream>
#include <string>

const std::string PATTERN = "¹¥œŒŸ³£ó¿¯ñÑêÊæÆÓ";    //to sa znaki odpowiednio ulozone w tablicy
int* zle_pl(std::string);    //wczytuje PATTERN do tablicy
int* zle_polskie_znaki = zle_pl(PATTERN);   //wskazujemy na pierwszy  element tablicy ze znakami
int polskie_znaki[] = { -91, -92, -104, -105, -85, -115, -120, -99, -94, -66, -67, -28, -29, -87, -88, -122, -113, -32 }; //¹¥œŒŸ³£ó¿¯ñÑêÊæÆÓ - alternatywa   
std::string Wypisz_z_pl_zn(std::string);  //np. cout << pl("Lubiê Ciê"); wypisze teraz stringa w konsoli z polskimi znakami
int main()
{

    std::cout << Wypisz_z_pl_zn("wpisany œ¹œ³¹³œ znak to: ¹œ¹œ³¹³œ¹³œÓ") <<  std::endl;

    std::cout << Wypisz_z_pl_zn("Czeœæ Œl¹sk :D ") << std::endl;

    system("pause");
    return 0;
}
int* zle_pl(std::string pattern)
{
    int* tab = new int[pattern.length()];

    for (int i = 0; i < pattern.length(); i++)
        tab[i] = static_cast<int>(pattern[i]);

    return &tab[0];
}
std::string Wypisz_z_pl_zn(std::string napis)
{
    for (int i = 0; i < napis.length(); i++)
        for (int j = 0; j < PATTERN.length(); j++)
        {
            if (napis[i] == zle_polskie_znaki[j])
            {
                napis[i] = polskie_znaki[j];
                break;
            }
        }

    return napis;
}
