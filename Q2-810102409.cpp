#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Input(int &number_of_operator, string &phrase)
{
    cin >> number_of_operator;
    cin >> phrase;
}

int Calculate(int left, char op, int right)
{
    int result;

    switch (op)
    {
    case '+':
        return left + right;

    case '-':
        return left - right;

    case '*':
        return left * right;
    }
}

vector<int> SolveProblem(string phrase)
{
    vector<int> result;

    if (phrase.find('+') == string::npos && phrase.find('-') == string::npos && phrase.find('*') == string::npos)
    {
        result.push_back(stoi(phrase));
        return result;
    }

    for (int i = 0; i < phrase.size(); i++)
    {
        if (phrase[i] == '+' || phrase[i] == '-' || phrase[i] == '*')
        {
            vector<int> left_vector = SolveProblem(phrase.substr(0, i));
            vector<int> right_vector = SolveProblem(phrase.substr(i + 1));

            for (int left = 0; left < left_vector.size(); left++)
            {
                for (int right = 0; right < right_vector.size(); right++)
                {
                    result.push_back(Calculate(left_vector[left], phrase[i], right_vector[right]));
                }
            }
        }
    }
}

int main()
{
    int number_of_operators;
    string phrase;
    vector<int> results;

    Input(number_of_operators, phrase);

    results = SolveProblem(phrase);
}