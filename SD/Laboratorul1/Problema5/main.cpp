#include <iostream>
#include <fstream>
#include <vector>

std::vector<float> citireMedii(std::string fileName)
{
    std::ifstream file(fileName);
    std::vector<float> medii;
    float medie;
    while(!file.eof())
    {
        file>>medie;
        medii.push_back(medie);
    }

    file.close();

    return medii;
}

int main()
{
    auto medii = citireMedii("medii.txt");
    // 1-5
    // 5-5.50
    // 5.50 - 6.50
    // 6.50 - 7.50
    // 7.50 - 8.50
    // 8.50 - 9.50
    // 9.50 - 10

    // 7 intervale
    int fr[7] = {0};
    for(int i = 0;i<medii.size();++i)
    {
        if(medii[i]>=1 && medii[i]<5)
            fr[0]++;
        else if(medii[i]>=5 && medii[i]<5.50)
            fr[1]++;
        else if(medii[i]>=5.50 && medii[i]<6.50)
            fr[2]++;
        else if(medii[i]>=6.50 && medii[i]<7.50)
            fr[3]++;
        else if(medii[i]>=7.50 && medii[i]<8.50)
            fr[4]++;
        else if(medii[i]>=8.50 && medii[i]<9.50)
            fr[5]++;
        else if(medii[i]>=9.50 && medii[i]<=10)
            fr[6]++;
    }

    printf("Media\t\tNr elevi\n");
    printf("1-5\t\t%d\n", fr[0]);
    printf("5-5.50\t\t%d\n", fr[1]);
    printf("5.50-6.50\t%d\n", fr[2]);
    printf("6.50-7.50\t%d\n", fr[3]);
    printf("7.50-8.50\t%d\n", fr[4]);
    printf("8.50-9.50\t%d\n", fr[5]);
    printf("9.50-10\t\t%d\n", fr[6]);

    return 0;
}