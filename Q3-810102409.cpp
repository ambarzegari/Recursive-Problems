#include <iostream>
#include <vector>
#include <cmath>

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

int Minsweet(vector<int> num_of_student, int college_num)
{
    if (college_num == num_of_student.size() - 1)
    {
        return 0;
    }
    
    if (college_num == num_of_student.size() - 2)
    {
        return abs(num_of_student[college_num]-num_of_student[college_num + 1]);
    }

    int cost_1 = abs(num_of_student[college_num] - num_of_student[college_num + 1]) + Minsweet(num_of_student, college_num + 1);
    int cost_2 = abs(num_of_student[college_num] - num_of_student[college_num + 2]) + Minsweet(num_of_student, college_num + 2);
    
    return min(cost_1, cost_2);
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