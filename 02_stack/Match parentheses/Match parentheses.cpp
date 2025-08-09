#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s);

int main()
{
    string s = "(())()";

    bool result = solution(s);

    cout << result;

    return 0;
}

bool solution(string s)
{
    stack<bool> stk;

    for (char temp : s)
    {
        if (temp == ')')
        {
            if (stk.empty())
            {
                return false;
            }
            else
            {
                stk.pop();
            }
        }
        else
        {
            stk.push(true);
        }
    }

    if (!stk.empty())
    {
        return false;
    }

    return true;
}