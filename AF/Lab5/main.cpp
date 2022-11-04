#include <iostream>

int cautareBinara(int *&vector, int element, int stanga, int dreapta)
{
    int mijloc = (stanga + dreapta) / 2;
    if (stanga > dreapta)
        return -1;
    if (vector[mijloc] == element)
        return mijloc;
    if (vector[mijloc] > element)
        return cautareBinara(vector, element, stanga, mijloc - 1);
    return cautareBinara(vector, element, mijloc + 1, dreapta);
}

int Partitie(int *&vector, int &indexStart, int &indexFinal)
{
    int pivot = vector[indexFinal];
    int i = indexStart;
    for (int j = indexStart; j <= indexFinal; j++)
    {
        if (vector[j] <= pivot)
        {
            int aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
            i++;
        }
    }

    return i - 1;
}

void quickSort(int *&vector, int indexStart, int indexFinal)
{

    // O(nlogn)
    if (indexStart < indexFinal)
    {
        int indexPivot = Partitie(vector, indexStart, indexFinal);
        quickSort(vector, indexStart, indexPivot - 1);
        quickSort(vector, indexPivot + 1, indexFinal);
    }
}

void citire(int *&vector, int &dim)
{
    std::cout << "Introduceti dimensiunea vectorului: ";
    std::cin >> dim;
    vector = new int[dim];
    for (int i = 0; i < dim; i++)
    {
        std::cout << "Introduceti elementul " << i << ": ";
        std::cin >> vector[i];
    }
}

void afisare(int *&vector, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int *vector;
    int dim;
    citire(vector, dim);
    quickSort(vector, 0, dim - 1);
    afisare(vector, dim);
    delete[] vector;
    return 0;
}