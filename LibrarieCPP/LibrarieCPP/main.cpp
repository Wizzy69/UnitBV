#include "./Utils.cpp"

struct moneda
{
    int zile;
    int *valori;
};

int main()
{
    int n;
    std::cin >> n;
    moneda *m = new moneda[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> m[i].zile;
        m[i].valori = new int[m[i].zile];
        for (int j = 0; j < m[i].zile; j++)
        {
            std::cin >> m[i].valori[j];
        }
    }
    return 0;
}