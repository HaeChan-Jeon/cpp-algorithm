#include <iostream>
#include <stack>
#include <string>

using namespace std;

string solution(int decimal);

int main()
{
    string result = solution(10);
    cout << result << endl;

    result = solution(27);
    cout << result << endl;

    result = solution(12345);
    cout << result << endl;

    return 0;
}

string solution(int decimal)
{
    int temp;

    stack<int> stk;

    while (decimal != 0)
    {
        temp = decimal % 2;

        stk.push(temp);

        decimal /= 2;
    }

    string result = "";

    while (!stk.empty())
    {
        result += to_string(stk.top());
        stk.pop();
    }

    return result;
}