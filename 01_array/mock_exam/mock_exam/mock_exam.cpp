#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers);

int main()
{
    int count;
    cin >> count;

    vector<int> answers;
    int temp;

    for (int i = 0; i < count; ++i)
    {
        cin >> temp;
        answers.push_back(temp);
    }

    vector<int> results = solution(answers);

    for (int result : results)
    {
        cout << result << " ";
    }

    return 0;
}

vector<int> solution(vector<int> answers)
{
    vector<int> score(3, 0);

    vector<int> a{ 1, 2, 3, 4, 5 };
    vector<int> b{ 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> c{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    for (int i = 0; i < answers.size(); ++i)
    {
        if (answers[i] == a[i % a.size()])
        {
            score[0]++;
        }
        else if (answers[i] == b[i % b.size()])
        {
            score[1]++;
        }
        else if (answers[i] == c[i % c.size()])
        {
            score[2]++;
        }
    }

    int maxScore = *max_element(score.begin(), score.end());

    vector<int> result;

    for (int i = 0; i < 3; ++i)
    {
        if (score[i] == maxScore)
        {
            result.push_back(i + 1);
        }
    }

    return result;
}
