#include <stdio.h>
#include <stdbool.h> 

void printSquare(int square[3][3])
{
    int row, column, current;
    for(row = 0; row < 3; row ++)
    {
        printf("[");
        for(column = 0; column < 3; column++)
        {
            current = square[row][column];
            printf(" %d ",  current);
        }
        printf("]\n");
    }
}

bool testSquare(int square [3][3])
{
    int row, column;
    int current = 0;
    bool Msquare = true;
    for(row = 0; row < 3; row ++)
    {
        for(column = 0; column < 3; column++)
        {
            current =  current + square[row][column];
        }
        if(current != 15)
        {
            Msquare = false;
            break;
        }
        current = 0;
    }

    current = 0;
    for(column = 0; column < 3; column ++)
    {
        for(row = 0; row < 3; row++)
        {
            current =  current + square[row][column];
        }
        if(current != 15)
        {
            Msquare = false;
            break;
        }
        current = 0;
    }

    int cross1 = square[0][0] + square[1][1] + square[2][2];
    int cross2 = square[0][2] + square[1][1] + square[2][0];
    if(cross1 != cross2)
    {
        Msquare = false;
    }
    return Msquare;
}

int main()
{
    int NmagicSquare[3][3] = {{4,9,1},
                             {3,5,7},
                             {8,1,6}};
    int magicSquare[3][3] = {{4,9,2},
                              {3,5,7},
                              {8,1,6}};


    if(testSquare(magicSquare))
        printf("is a magic square\n");
    else
        printf("is NOT a magic square\n");

    printSquare(magicSquare);

        if(testSquare(NmagicSquare))
        printf("is a magic square\n");
    else
        printf("is NOT a magic square\n");

    printSquare(NmagicSquare);
    return 0;
}