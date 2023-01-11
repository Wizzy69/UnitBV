/*
Se dă o bucată de hârtie de dimensiune A x B. Hârtia se taie în pătrate de orice
dimensiune. Găsiți numărul minim de pătrate în care poate tăia.
Exemplu 13 x 29 = 2 (13x13) + 4 (3x3) + 3 (1x1) = 9 bucăți
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream f("date.in");
    int A, B, nr = 0;
    f >> A >> B;
    while (A != B)
    {
        if (A > B)
        {
            nr += A / B;
            A = A % B;
        }
        else
        {
            nr += B / A;
            B = B % A;
        }
    }
    nr += A;
    cout << nr;
    return 0;
}