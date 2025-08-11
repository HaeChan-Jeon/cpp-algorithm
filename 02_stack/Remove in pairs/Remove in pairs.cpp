#include <iostream>
#include <stack>

using namespace std;

int solution(string s)
{
	stack<char> stk;

	for (char c : s)
	{
		if (!stk.empty() && stk.top() == c)
		{
			stk.pop();
		}
		else
		{
			stk.push(c);
		}
	}

	return stk.empty();
}

int main()
{
	string s = "baabaa";
	cout << solution(s) << endl;

	s = "cdcd";
	cout << solution(s);

	return 0;
}
