#include <iostream>
#include <vector>

using namespace std;

void Input(int &number_of_college, vector<int> &number_of_student_in_college)
{
    cin >> number_of_college;
    int input;
    for (int i = 0; i < number_of_college; i++)
    {
        cin >> input;
        number_of_student_in_college.push_back(input);
    }
}

int main()
{
    int number_of_college;
    vector<int> number_of_student_in_college;

    Input(number_of_college, number_of_student_in_college);

    for (int i = 0; i < number_of_college; i++)
    {
        cout << i+1 << " : " << number_of_student_in_college[i] << endl;
    }
    
}