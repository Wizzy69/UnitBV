#include <iostream>
#include <fstream>

int Partitie(int *&vector, int &indexStart, int &indexFinal, bool crescator)
{
    int pivot = vector[indexFinal];
    int i = indexStart;
    for (int j = indexStart; j <= indexFinal; j++)
    {
        if (crescator)
        {
            if (vector[j] <= pivot)
            {
                int aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
                i++;
            }
        }
        else
        {
            if (vector[j] >= pivot)
            {
                int aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
                i++;
            }
        }
    }

    return i - 1;
}

void quickSort(int *&vector, int indexStart, int indexFinal, bool crescator)
{

    // O(nlogn)
    if (indexStart < indexFinal)
    {
        int indexPivot = Partitie(vector, indexStart, indexFinal, crescator);
        quickSort(vector, indexStart, indexPivot - 1, crescator);
        quickSort(vector, indexPivot + 1, indexFinal, crescator);
    }
}

void citire(int *&vector, int &dim)
{
    std::ifstream f("problema2.in");
    f >> dim;
    vector = new int[dim];
    for (int i = 0; i < dim; i++)
    {
        f >> vector[i];
    }

    f.close();
}

void afisare(int *&vector, int dim)
{
    std::ofstream g("problema2.out");
    for (int i = 0; i < dim; i++)
        g << vector[i] << " ";
}

int main()
{
    int *vector;
    int dim;
    citire(vector, dim);
    quickSort(vector, 0, dim / 2, true);
    quickSort(vector, dim / 2, dim - 1, false);
    afisare(vector, dim);
    return 0;
}
