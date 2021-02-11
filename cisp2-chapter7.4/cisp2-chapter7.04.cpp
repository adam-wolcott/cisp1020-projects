// Exercise #4
// In a program, write a function that accepts three arguments: an array, the size of an array, and a number n.
// Assume the array contains intergers.
// The function should display all of the numbers in the array that are grater than the number n.

#include <iostream>

void greater_than_n(double yourArray[], const int SIZE, double n);

int main()
{
    // Initialize variables
    const int SIZE = 5;
    double myArray[SIZE] = { 1, 16, 2, 3, 55 };
    double n = 11.5;

    greater_than_n(myArray, SIZE, n);

    return 0;
}

// displays all numbers contianed in an array that are greater than the number n.
void greater_than_n(double yourArray[], const int SIZE, double n)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (yourArray[i] > n)
            std::cout << yourArray[i] << "\n";
    }
}