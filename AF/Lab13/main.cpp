#include <iostream>
#include <vector>

struct pozitie // element
{
    int valCurenta;
    int index;
};

int minimSalturi(std::vector<int> vector, int pozCrt, std::vector<pozitie> elemente)
{
    if (vector[pozCrt] == 0)
        return 0;
    if (pozCrt >= vector.size())
        return 0;

    for (int index = pozCrt; index < pozCrt + vector[pozCrt]; ++index)
    {
        if (pozCrt + vector[pozCrt] > vector.size())
            return 0;
    }
}

int main()
{

    return 0;
}