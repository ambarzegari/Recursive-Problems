#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int SIZE = 8;

void InputBoard(vector<vector<char>> &Board)
{
    string input;

    for (int row = 0; row < SIZE; row++)
    {
        getline(cin, input);

        for (int col = 0; col < SIZE; col++)
        {
            Board[row].push_back(input[col]);
        }
    }
}

int Queen_Colmn_In_Row(vector<vector<char>> Board, int row)
{
    int queen_colmn_in_row;

    for (int col = 0; col < SIZE; col++)
    {
        if (Board[row][col] == 'Q')
        {
            return col;
        }
    }
    return 0;
}

bool Threat(vector<vector<char>> Board, int row, int col)
{
    int queen_colmn_in_row;

    for (int i = 0; i < row; i++)
    {
        queen_colmn_in_row = Queen_Colmn_In_Row(Board, i);

        if (queen_colmn_in_row == col || i == row || abs(queen_colmn_in_row - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

bool BeingObstacle(vector<vector<char>> Board, int row, int col)
{
    if (Board[row][col] != '*')
    {
        return true;
    }
    return false;
}

void Solve(vector<vector<char>> Board, int row, int &solutions_count)
{
    if (row == SIZE)
    {
        solutions_count++;
        return;
    }

    for (int col = 0; col < SIZE; col++)
    {
        if (Threat(Board, row, col) && BeingObstacle(Board, row, col))
        {
            Board[row][col] = 'Q';
            Solve(Board, row + 1, solutions_count);
            Board[row][col] = '-';
        }
    }
}

int main()
{
    int solutions_count = 0;
    vector<vector<char>> Board(SIZE);

    InputBoard(Board);

    Solve(Board, 0, solutions_count);

    cout << solutions_count;

    return 1;
}