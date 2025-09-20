#include "g-quaternary.h"
#include <iostream>

int main()
{
    Quaternary test[] = {Quaternary::Low(), Quaternary::Mid(), Quaternary::High(), Quaternary::Max()};

    std::cout << "Inputs:\t\tSQI:\tIQI:\tNQI:\tPQI:\n";

    for (int i = 0; i < 4; i++)
    {
        std::cout << '\t' << test[i].State() << '\t';
        std::cout << (!test[i]) << '\t';
        std::cout << (~test[i]) << '\t';
        std::cout << (+test[i]) << '\t';
        std::cout << (-test[i]) << "\n\n\n";
    }

    std::cout << "A:\tB:\tAND\tOR\tXOR\tNAND\tNOR\tXNOR\n";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << i << '\t' << j << '\t';
            std::cout << (test[i] && test[j]) << '\t' << (test[i] || test[j]) << '\t' << (test[i] ^ test[j]) << '\t' << (test[i] & test[j]) << '\t' << (test[i] | test[j]) << '\t' << (test[i] % test[j]) << '\n';
        }
    }
}
