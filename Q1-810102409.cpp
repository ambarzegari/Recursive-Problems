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

void PrintBoard(vector<vector<char>> Board)
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            cout << Board[row][col] << " ";
        }
        cout << endl;
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
}

int main()
{
    vector<vector<char>> Board(SIZE);

    InputBoard(Board);

    PrintBoard(Board);

    return 1;
}