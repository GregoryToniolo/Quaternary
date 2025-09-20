#include "g-quaternary.h"
#include <stdio.h>

int main(void)
{
    quaternary test[] = {Low, Mid, High, Max};

    printf("Inputs:\t\tSQI:\tIQI:\tNQI:\tPQI:\n");

    for (int i = 0; i < 4; i++)
    {
        printf("\t%d\t", test[i]);
        printf("%d\t", SQI_invert(test[i]));
        printf("%d\t", IQI_invert(test[i]));
        printf("%d\t", NQI_invert(test[i]));
        printf("%d\n\n\n", PQI_invert(test[i]));
    }

    printf("A:\tB:\tAND\tOR\tXOR\tNAND\tNOR\tXNOR\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t%d\t", i, j);
            printf("%d\t%d\t%d\t%d\t%d\t%d\n", AND(test[i], test[j]), OR(test[i], test[j]), XOR(test[i], test[j]), NAND(test[i], test[j]), NOR(test[i], test[j]), XNOR(test[i], test[j]));
        }
    }
}
