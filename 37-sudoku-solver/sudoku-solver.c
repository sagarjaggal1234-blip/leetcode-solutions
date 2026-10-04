#include <stdbool.h>

bool isValid(char board[9][9], int row, int col, char num)
{
    // Check row
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
            return false;
    }

    // Check column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
            return false;
    }

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

bool solve(char board[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            // Find empty cell
            if (board[row][col] == '.')
            {
                // Try numbers 1 to 9
                for (char num = '1'; num <= '9'; num++)
                {
                    if (isValid(board, row, col, num))
                    {
                        board[row][col] = num;

                        // Recursively solve
                        if (solve(board))
                            return true;

                        // Backtrack
                        board[row][col] = '.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize)
{
    // Convert char** board to the format used by solve()
    char temp[9][9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            temp[i][j] = board[i][j];
        }
    }

    solve(temp);

    // Copy solved board back
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i][j] = temp[i][j];
        }
    }
}