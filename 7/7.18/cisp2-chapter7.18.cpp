// Exercise #18
// Write a program that allows two players to play a game of tic-tac-toe.
// Use a two-dimensional char array with three rows and three columns as the game board.
// Each element of the array should be initialized with an asterisk (*).
// The program should run a loop that does the following:
//
// * Displays the contents of the board array.
// * Allows player 1 to select a location on the board for an X.
//   The program should ask the user to enter the row and column numbers.
// * Allows player 2 to select a location on the board for an O.
//   The program should ask the user to enter the row and column numbers.
// * Determines wheteher a player has won, or a tie has occured.
//   If a player has won, the program should declare that player the winner and end.
//   If a tie has occured, the program should display an appropriate message and end.
//
// Player 1 wins when there are three Xs in a row on the game board.
// The Xs can appear in a row, in a column, or diagonally across the board.
// Player 2 wins when there are three Os in a row on the game board.
// The Os can appear in a row, in a column, or diagonally across the board.
// A tie occurs when all of the locations on the board are full, but there is no winner.

#include <iostream>

void print3x3Board(char board[3][3]);
void playerTurn(char& current_player, char board[3][3]);
bool checkWinner(char board[3][3]);

int main()
{
    const int SIZE = 3;
    int turns = 0;
    char current_player = 'X';
    char board[SIZE][SIZE] = { '*', '*', '*',
                               '*', '*', '*', 
                               '*', '*', '*' };

    

    while (turns < 9)
    {
        print3x3Board(board);

        playerTurn(current_player, board);

        if (checkWinner(board) == 0)
        {
            turns++;
            switch (current_player)
            {
            case 'X':
                current_player = 'O';
                break;
            case 'O':
                current_player = 'X';
                break;
            }
        }
        else
        {
            print3x3Board(board);

            switch (current_player)
            {
            case 'X':
                std::cout << "\n\nThe winner is Player 1!";
                turns = 10;
                break;
            case 'O':
                std::cout << "\n\nThe winner is Player 2!";
                turns = 10;
                break;
            }
        }
        
    }
    
    switch(turns)
        case 9:
            std::cout << "\n\nThis game was a tie!";

    std::cout << std::endl;
    return 0;
}

void print3x3Board(char board[3][3])
{
    std::cout << "\n\n  0   1   2  ";
    std::cout << "\n ___________\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "| " << board[i][j] << " ";
        }
        std::cout << "|  " << i << "\n|___|___|___|\n";
    }
}

void playerTurn(char& current_player, char board[3][3])
{
    int row = 0,
        column = 0;
    bool valid = 0;

    switch (current_player)
    {
    case 'X':
        while (!valid)
        {
            while ((std::cout << "\nPlayer 1 Column: ") && (!(std::cin >> column) || column < 0 || column > 2))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again. ";
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            while ((std::cout << "\nPlayer 1 Row: ") && (!(std::cin >> row) || row < 0 || row > 2))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again. ";
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (board[row][column])
            {
            case 'X':
                valid = 0;
                std::cout << "\nThis spot is already taken. Try again.";
                break;
            case 'O':
                valid = 0;
                std::cout << "\nThis spot is already taken. Try again.";
                break;
            default:
                valid = 1;
                board[row][column] = current_player;
            }
        }
        break;

    case 'O':
        while (!valid)
        {
            while ((std::cout << "\nPlayer 2 Column: ") && (!(std::cin >> column) || column < 0 || column > 2))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again. ";
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            while ((std::cout << "\nPlayer 2 Row: ") && (!(std::cin >> row) || row < 0 || row > 2))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again. ";
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (board[row][column])
            {
            case 'X':
                valid = 0;
                std::cout << "\nThis spot is already taken. Try again.";
                break;
            case 'O':
                valid = 0;
                std::cout << "\nThis spot is already taken. Try again.";
                break;
            default:
                valid = 1;
                board[row][column] = current_player;
            }
        }
        break;
    }
}

bool checkWinner(char board[3][3])
{
//                  R1 R2 R3 C1 C2 C3 D1 D2 
    int index[8] = { 0, 0, 0, 0, 0, 0, 0, 0 },
        n = 0;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            switch (board[i][j])
            {
            case 'X':
                if (i == 0 && j == 0)
                {
                    index[0] += 10;
                    index[3] += 10;
                    index[6] += 10;
                }
                if (i == 0 && j == 1)
                {
                    index[0] += 10;
                    index[4] += 10;
                }
                if (i == 0 && j == 2)
                {
                    index[0] += 10;
                    index[5] += 10;
                    index[7] += 10;
                }

                if (i == 1 && j == 0)
                {
                    index[1] += 10;
                    index[3] += 10;
                }
                if (i == 1 && j == 1)
                {
                    index[1] += 10;
                    index[4] += 10;
                    index[6] += 10;
                    index[7] += 10;
                }
                if (i == 1 && j == 2)
                {
                    index[1] += 10;
                    index[5] += 10;
                }

                if (i == 2 && j == 0)
                {
                    index[2] += 10;
                    index[3] += 10;
                    index[7] += 10;
                }
                if (i == 2 && j == 1)
                {
                    index[2] += 10;
                    index[4] += 10;
                }
                if (i == 2 && j == 2)
                {
                    index[2] += 10;
                    index[5] += 10;
                    index[6] += 10;
                }

                break;
            case 'O':

                if (i == 0 && j == 0)
                {
                    index[0] += 2;
                    index[3] += 2;
                    index[6] += 2;
                }
                if (i == 0 && j == 1)
                {
                    index[0] += 2;
                    index[4] += 2;
                }
                if (i == 0 && j == 2)
                {
                    index[0] += 2;
                    index[5] += 2;
                    index[7] += 2;
                }

                if (i == 1 && j == 0)
                {
                    index[1] += 2;
                    index[3] += 2;
                }
                if (i == 1 && j == 1)
                {
                    index[1] += 2;
                    index[4] += 2;
                    index[6] += 2;
                    index[7] += 2;
                }
                if (i == 1 && j == 2)
                {
                    index[1] += 2;
                    index[5] += 2;
                }

                if (i == 2 && j == 0)
                {
                    index[2] += 2;
                    index[3] += 2;
                    index[7] += 2;
                }
                if (i == 2 && j == 1)
                {
                    index[2] += 2;
                    index[4] += 2;
                }
                if (i == 2 && j == 2)
                {
                    index[2] += 2;
                    index[5] += 2;
                    index[6] += 2;
                }

                break;
            }
        }
        n += 3;
    }

    for (int i = 0; i < 8; i++)
    {
        switch (index[i])
        {
        case 6:
            return 1;
        case 30:
            return 1;
        default:
            break;
        }
    }
    return 0;
}
    

    