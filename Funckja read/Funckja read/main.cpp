//porownuje dwa pliki tekstowe na podstawie wielkosci

#include<iostream>
#include<fstream>
#include<string.h>

bool areFilesEqual(std::fstream *, std::fstream *);

int sizeOfFile(std::fstream*);

int main()
{
	/*
		read(gdzie zapisac, ile bajtow)
	*/

	std::fstream otwarty_plik1, otwarty_plik2;

	otwarty_plik1.open("test.txt", std::ios::in | std::ios::binary | std::ios::ate);
	otwarty_plik2.open("test2.txt", std::ios::in | std::ios::binary | std::ios::ate);

	if (otwarty_plik1.is_open() && otwarty_plik2.is_open())
	{
		if (areFilesEqual(&otwarty_plik1, &otwarty_plik2))
		{
			std::cout << "Pliki sa identyczne :D " << std::endl;
		}
		else
		{
			std::cout << "Cos sie jesenak roznia" << std::endl;
		}
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku :( " << std::endl;
	}

	return 0;
}

bool areFilesEqual(std::fstream* file1, std::fstream* file2)
{
	int fileSize1 = sizeOfFile(file1);
	int fileSize2 = sizeOfFile(file2);

	if (fileSize1 == fileSize2)
	{
		int BUFFER_SIZE = fileSize1;
		
		char* file1Buffer = new char[BUFFER_SIZE];
		char* file2Buffer = new char[BUFFER_SIZE];
		
		file1->read(file1Buffer, BUFFER_SIZE);
		file2->read(file2Buffer, BUFFER_SIZE);

		if (memcmp(file1Buffer, file2Buffer, BUFFER_SIZE) != 0)
		{
			std::cout << "Pliki nie sa rowne " << std::endl;
			
			delete[]file1Buffer;
			delete[]file2Buffer;
			return false;
		}
		delete[]file1Buffer;
		delete[]file2Buffer;

		return true;
	}
	else
	{
		std::cout << "Pliki sie sa rowne maja inna wielkosc" << std::endl;
		return false;
	}
}

int sizeOfFile(std::fstream* file)
{
	file->seekg(0, std::ios::end);
	int sizeOfFile = file->tellg();
	file->seekg(0, std::ios::beg);

	return sizeOfFile;
}