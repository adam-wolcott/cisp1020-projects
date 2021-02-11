// Exercise #8
// The Lo Shu Magic Square is a grid with 3 rows and 3 columns shown in Figure 7-19.
// The Lo Shu Magic Square has the following properties:
//
// * The grid contains the numbers 1 through 9 exactly.
// * The sum of each row, each column, and each diagonal all add up to the same number.
//   This is shown in Figure 7-20
//
// In a program, you can simulate a magic square using a two-dimensional array.
// Write a function that accepts a two-dimensional array as an argument, and determines whether the array is a Lo Shu Magic Square.
// Test the function in a program.

#include <iostream>

bool functionThatDertimnesWhetherArrayIsLoShuMagicSquare(int array[3][3]);
void printArray(int array[3][3]);

int main()
{
    //initialize
    int my_square[3][3] = { 4, 9, 2,
                            3, 5, 7,
                            8, 1, 6 };

    //display my square and determine whether it is a Lo Shu Magic Square
    std::cout << "\nThis program determines whether a two-dimensional array is a Lo Shu Magic Square.";
    std::cout << "\n\nCurrent Array: ";
    printArray(my_square);
    if (functionThatDertimnesWhetherArrayIsLoShuMagicSquare(my_square)) //bool function checks my square
        std::cout << "\nThis is a Lo Shu Magic Square." << std::endl; //yes
    else
        std::cout << "\nThis is not a Lo Shu Magic Square." << std::endl; //no

    return 0;
}

void printArray(int array[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n               ";
    }
}

bool functionThatDertimnesWhetherArrayIsLoShuMagicSquare(int array[3][3])
{
                 // R1 R2 R3 C1 C2 C3 D1 D2
    int index[8] = { 0, 0, 0, 0, 0, 0, 0, 0 }; // totals for each row, column, and diagonal

    // process array into each total slot
    // row
    for (int i = 0; i < 3; i++)
    {
        // column
        for (int j = 0; j < 3; j++)
        {
            index[i] += array[i][j];        // distribute rows
            index[j + 3] += array[i][j];    // distribute columns
            if (i == 0 && j == 0)           // I do not like the if statements, but I could not think of another way to distribute diagonals
                index[6] += array[i][j];
            if (i == 1 && j == 1)
            {
                index[6] += array[i][j];
                index[7] += array[i][j];
            }
            if (i == 2 && j == 2)
                index[6] += array[i][j];           
            if (i == 2 && j == 0)
                index[7] += array[i][j];
            if (i == 0 && j == 2)
                index[7] += array[i][j];
        }
    }

    // process index to check if all elements are equal
    for (int i = 1; i < 8; i++)
    {
        if (index[0] != index[i])
            return false;
    }
    return true;
}