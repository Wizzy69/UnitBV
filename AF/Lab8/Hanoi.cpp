#include <iostream>

void Hanoi(int n, char A, char B, char C)
{
    if (n == 1)
        std::cout << "Muta discul " << n << " de pe " << A << " pe " << C << std::endl;
    else
    {
        Hanoi(n - 1, A, C, B);
        std::cout << "Muta discul " << n << " de pe " << A << " pe " << C << std::endl;
        Hanoi(n - 1, B, A, C);
    }
}

int main()
{
    int numarDiscuri;
    int numarTotalMutari;
}