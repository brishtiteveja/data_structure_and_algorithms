#include <iostream>

using namespace std;

bool isCorrect(int sudoku[9][9]) {
    int squareDigits[9] = { -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int rowDigits[9]    = { -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int colDigits[9]    = { -1, -1, -1, -1, -1, -1, -1, -1, -1};

    for (int sx=0; sx<3; sx++)
    {
        for(int sy=0; sy<3; sy++)
        {
            int m = 3 * sx;
            int n = 3 * sy;
            for (int i=0+m ; i<3+m; i++)
            {
                for (int j=0+n; j<3+n; j++)
                {
                    int n = sudoku[i][j];
                    squareDigits[n-1] = 1;
                    rowDigits[n-1] = 1;
                    colDigits[n-1] = 1;
                }
            }
        }

        // Check whether previous subsquare satisfied the condition
        for(int k=0; k<9; k++)
        {
            if(squareDigits[k] == -1 || rowDigits[k] == -1 || colDigits[k] == -1)
                return false;
        }

        // reset after moving to each subsquare
        for(int k=0; k<9; k++)            
        {
            squareDigits[k] = -1;
            rowDigits[k] = -1;
            colDigits[k] = -1;
        }
    }

    return true;
}

bool solveSudokuNaive(int sudoku[9][9]) {
    for (int sx=0; sx<3; sx++)
    {
        for(int sy=0; sy<3; sy++)
        {
            int m = 3 * sx;
            int n = 3 * sy;
            for (int i=0+m ; i<3+m; i++)
            {
                for (int j=0+n; j<3+n; j++)
                {
                    // some value already assigned
                    if (sudoku[i][j] != -1)
                        continue;

                    for(int k=1; k<=9; k++) {
                        int prev = sudoku[i][j]
                        sudoku[i][j] = k;

                        bool correct = solveSudokuNaive(sudoku);
                        if (correct)
                            return true;

                        sudoku[i][j] = prev;
                    }
                }
            }
        }
    } 

    if (isCorrect(sudoku))
        return true;
}


void printSudoku(int sudoku[9][9])
{

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            printf("%3d ", sudoku[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return;
}

int main() {
    int sudoku[9][9] = 
    {
        {  3, -1,  6,   5, -1,  8,   4, -1, -1 },
        {  5,  2, -1,  -1, -1, -1,  -1, -1, -1 },
        { -1,  8,  7,  -1, -1, -1,  -1,  3,  1 },
        { -1, -1,  3,  -1,  1, -1,  -1,  8, -1 },
        {  9, -1, -1,   8,  6,  3,  -1, -1,  5 },
        { -1,  5, -1,  -1, -1, -1,   6, -1, -1 },
        {  1,  3, -1,  -1, -1, -1,   2,  5, -1 },
        { -1, -1, -1,  -1, -1, -1,  -1,  7,  4 },
        { -1, -1,  5,   2, -1,  6,   3, -1, -1 }
    };

    //solveSudoku(sudoku);

    printSudoku(sudoku);

    return 0;
}
