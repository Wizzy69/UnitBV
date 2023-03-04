// Problema 2

#include <iostream>
#include <fstream>
#include <vector>

int celMaiMareNumarCuCifrePare(std::vector<int> vector, int dimensiuneVector)
{
    int fr[5] = {0};
    for(int i = 0;i<vector.size();++i)
    {
        if(vector[i]==0)
            fr[0]++;
        while(vector[i]>0)
        {
            if(vector[i]%2==0)
                fr[(vector[i]%10)/2]++;
            vector[i]/=10;
        }
    }

    int numar = 0;
    for(int i = 4;i>=0;--i)
        while(fr[i])
        {
            numar = numar*10 + i*2;
            fr[i]--;
        }
    return numar;
}

int main()
{
    int nr;
    std::vector<int> vector;

    std::cin>>nr;
    for(int i = 0;i<nr;++i)
    {
        int numar;
        std::cin>>numar;
        vector.push_back(numar);
    }

    std::cout<<celMaiMareNumarCuCifrePare(vector, nr);
    return 0;
}