#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    string answer;

    queue<string> oneQ;
    for (int i = 0; i < cards1.size(); i++)
    {
        oneQ.push(cards1[i]);
    }

    queue<string> twoQ;
    for (int i = 0; i < cards2.size(); i++)
    {
        twoQ.push(cards2[i]);
    }

    for (int i = 0; i < goal.size(); i++)
    {
        if (!oneQ.empty() && goal[i] == oneQ.front())
        {
            oneQ.pop();

            if (i == goal.size() - 1)
            {
                answer = "Yes";
                break;
            }

            continue;
        }
        else if (!twoQ.empty() && goal[i] == twoQ.front())
        {
            twoQ.pop();

            if (i == goal.size() - 1)
            {
                answer = "Yes";
                break;
            }

            continue;
        }

        answer = "No";
        break;
    }

    return answer;
}

int main()
{

    vector<string> card1 = { "i", "drink", "water" };
    vector<string> card2 = { "want", "to" };
    vector<string> goal = { "i", "want", "to", "drink", "water" };

    cout << solution(card1, card2, goal);

    return 0;
}