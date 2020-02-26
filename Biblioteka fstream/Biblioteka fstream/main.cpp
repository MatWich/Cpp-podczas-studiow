#include<iostream>
#include<fstream>

int main()
{
	/*
		ios::in    ----> INPUT - odczyt
		ios::out   ----> OUTPUT - zapis
		ios::trunc ----> TRUNCATE - ucinanie(wymazac)
		ios::ate   ----> AT THE END - poczatkowa pozycja (wskaznik) na koniec pliku
		ios::app   ----> APPEND -  zawartosc dolaczana jest na koncu pliku

		DOMYSLNE FLAGI
		fstream  - ios::in | ios::out 
		ofstream - ios::out
		ifstream - ios::in

		funkcje:
		bad() badbit(1) - true jesli powstanie blad np zapisywanie do pliku ktory jest tylko do odczytu
		good() goodbit(0) - true gdy wszystko jest wporzadku :D
		fail() failbit(4) - zwraca true gdy probujemy wczytac ciag znakow do liczby typu integer	pojawia sie zawsze gdy pojawia sie badbit ale w druga strone to nie dziala
		eof() END OF FILE(2) 
		rdstate()- READ STATE przeczytaj stan	zlicza bity np failbit i eof jest  wtedy bd 6
		
		tellg() - tell get - powiedz gdzie jest ustawiony wskaznik (odczytu)
		seekg() - seek get - ustaw wskaznik na pozycji ... (zapisu)
		ios::end - od konca
		ios::beg - od poczatku
		ios::cur - od biezacego ustawienia

		tellp - tell put - powiedz gdzie jest ustawiony wskaznik zapisu
		seekp - seek put - ustawia wskaznik do zapisu na pozycji
	*/
	std::string buffer;
	std::fstream otwarty_plik;
	otwarty_plik.open("test.txt", std::ios::out | std::ios::app | std::ios::in);

	if (otwarty_plik.is_open())
	{
		do
		{
			otwarty_plik >> buffer;
			std::cout << buffer << std::endl;
		} while (!otwarty_plik.eof());


	
	
		
		std::cout << "Wooohooo DZIALA Otworzcie tez szampana ! ! ! " << std::endl;
		otwarty_plik << " tekscik";
		otwarty_plik << "\n";
		otwarty_plik << "i\n";
		otwarty_plik << "jeszcze jeden";
		system("notepad test.txt");	//zobacz efekty ;)

		std::cout << otwarty_plik.tellg() << std::endl;
		otwarty_plik.seekg(0);

		otwarty_plik >> buffer;
		std::cout << buffer << std::endl;
	}
	else
	{
		std::cout << "Cos nie dziala ciekawe co cnie? " << std::endl;
	}

	otwarty_plik.close();

	system("pause");
	return 0;
}