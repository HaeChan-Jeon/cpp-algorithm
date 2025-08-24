#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//string solution(vector<string> participant, vector<string> completion)
//{
//    for (int i = 0; i < participant.size(); i++)
//    {
//        auto ptr = find(completion.begin(), completion.end(), participant[i]);
//
//        if (ptr != completion.end())
//        {
//            completion.erase(ptr);
//        }
//        else
//        {
//            return participant[i];
//        }
//    }
//}

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> ph;

    for (int i = 0; i < participant.size(); i++)
    {
        ph[participant[i]]++;
    }

    for (int i = 0; i < completion.size(); i++)
    {
        ph[completion[i]]--;

        if (ph[completion[i]] == 0)
        {
            ph.erase(ph.find(completion[i]));
        }
    }

    return ph.begin()-> first;
}

int main(void)
{
    vector<string> participant;
    vector<string> completion;

    participant = { "leo", "kiki", "eden" };
    completion = { "kiki", "eden" };

    cout << solution(participant, completion);

    return 0;
}