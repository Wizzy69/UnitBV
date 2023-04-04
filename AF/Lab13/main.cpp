#include <iostream>
#include <vector>

struct pozitie // element
{
    int valCurenta;
    int index;

    pozitie(int valCurenta, int index)
    {
        this->valCurenta = valCurenta;
        this->index = index;
    }
};

int minimVector(std::vector<pozitie> vector)
{
    int minim = vector[0].valCurenta;
    for (int index = 0; index < vector.size(); ++index)
    {
        if (vector[index].valCurenta < minim)
            minim = vector[index].valCurenta;
    }
    return minim;
}

int minimSalturi(std::vector<int> vector, int pozCrt)
{
    std::vector<pozitie> elemente;
    if (vector[pozCrt] == 0)
        return 0;
    if (pozCrt >= vector.size())
        return 0;
    for (int index = pozCrt; index < pozCrt + vector[pozCrt]; ++index)
    {
        if (index > vector.size())
            return 0;

        pozitie element(
            vector[pozCrt] + minimSalturi(vector, index),
            index);
        elemente.push_back(element);
    }

    return minimVector(elemente);
}

int main()
{
    std::vector<int> vector = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    std::cout << minimSalturi(vector, 0);
    return 0;
}