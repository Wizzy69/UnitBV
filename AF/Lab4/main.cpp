#include <iostream>
#include <fstream>

int SumaNumere()
{
    std::ifstream fisierIntrare("fisier.txt");

    if (!fisierIntrare.is_open())
    {
        std::cout << "Fisierul nu exista";
        return;
    }

    int dimensiune;
    fisierIntrare >> dimensiune;
    int suma = 0, numar;

    for (int i = 0; i < dimensiune; ++i)
    {
        if (fisierIntrare.eof())
        {
            std::cout << "Nu exista suficiente elemente";
            return suma;
        }
        fisierIntrare >> numar;
        suma += numar;
    }
    fisierIntrare.close();
    return suma;
}

int main()
{

    std::cout << SumaNumere();
    return 0;
}