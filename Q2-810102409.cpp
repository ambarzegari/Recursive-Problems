#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Input(int& number_of_operator, vector<string>& phrase)
{
    string input_phrase;
    cin >> number_of_operator;
    cin >> input_phrase;
}

int main()
{
    int number_of_operators;
    vector<string> phrase;
    Input(number_of_operators, phrase);
}