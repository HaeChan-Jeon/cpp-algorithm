#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    int priceNum = prices.size();

    vector<int> answer(priceNum);

    stack<int> s;

    for (int i = 0; i < priceNum; ++i)
    {
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }

        s.push(i);
    }

    while (!s.empty())
    {
        answer[s.top()] = priceNum - s.top() - 1;
        s.pop();
    }

    return answer;
}

int main()
{
    vector<int> prices = { 1, 6, 9, 5, 6, 5, 3, 1, 7, 4, 7, 4 };

    vector<int> answer = solution(prices);

    for (int i : answer)
    {
        cout << i << " ";
    }

    return 0;
}