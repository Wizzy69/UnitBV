// Problema 1

#include <iostream>
#include <vector>
#include <fstream>

void citireDate(std::vector<int> &v1, std::vector<int> &v2, int &nr1, int &nr2)
{
    std::ifstream f("date.in");
    f >> nr1;
    for (int i = 0; i < nr1; i++)
    {
        int x;
        f >> x;
        v1.push_back(x);
    }
    f >> nr2;
    for (int i = 0; i < nr2; i++)
    {
        int x;
        f >> x;
        v2.push_back(x);
    }
    f.close();
}

std::vector<int> interclasare(std::vector<int> v1, std::vector<int> v2)
{
    std::vector<int> v3;
    int i = 0, j = v2.size()-1;
    while (i < v1.size() && j >= 0)
    {
        if (v1[i] < v2[j])
        {
            v3.push_back(v1[i]);
            i++;
        }
        else{
            v3.push_back(v2[j]);
            j--;
        }
    }

    while (i < v1.size())
    {
        v3.push_back(v1[i]);
        i++;
    }
    while (j >=0)
    {
        v3.push_back(v2[j]);
        j++;
    }
    return v3;
}

int main()
{
    std::vector<int> v1, v2;
    int nr1, nr2;
    citireDate(v1, v2, nr1, nr2);

    // v1 = crescator
    // v2 = descrescator

    std::vector<int> v3 = interclasare(v1, v2);
    for (int i = 0; i < v3.size(); i++)
        std::cout << v3[i] << " ";
    std::cout << std::endl;

    return 0;
}