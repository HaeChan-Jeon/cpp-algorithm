#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int n = progresses.size();
    vector<int> days_left(n);

    for (int i = 0; i < n; ++i)
    {
        days_left[i] = ceil((100.0 - progresses[i]) / speeds[i]);
    }

    int count = 0;
    int max_day = days_left[0];

    for (int i = 0; i < n; ++i)
    {
        if (days_left[i] <= max_day)
        {
            count++;
        }
        else
        {
            answer.push_back(count);
            count = 1;
            max_day = days_left[i];
        }
    }

    answer.push_back(count);

    return answer;
}

int main()
{
    vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds = { 1, 1, 1, 1, 1, 1 };

    vector<int> answer = solution(progresses, speeds);

    for (int n : answer)
    {
        cout << n << " ";
    }

    return 0;
}