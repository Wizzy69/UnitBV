#include <iostream>
#include <vector>

template <typename T>
T Suma(const std::vector<T> &vector, int indexStanga, int indexDreapta)
{
    if (indexStanga == indexDreapta)
        return vector[indexStanga];
    else
    {
        int mijloc = (indexStanga + indexDreapta) / 2;
        return Suma(vector, indexStanga, mijloc) +
               Suma(vector, mijloc + 1, indexDreapta);
    }
}

int main()
{
    std::vector<int> vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << Suma(vector, 0, vector.size() - 1);
    return 0;
}