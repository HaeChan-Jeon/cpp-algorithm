#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int result = 0;
    int totalNumber = 0;
    unordered_map<string, int> wantMap;

    for (int i = 0; i < want.size(); ++i) {
        totalNumber += number[i];
        wantMap[want[i]] = number[i];
    }

    for (int i = 0; i < discount.size(); ++i) {
        if (wantMap.find(discount[i]) == wantMap.end()) {
            continue;
        }

        unordered_map<string, int> tempMap = wantMap;

        int tempCount = 0;

        for (int j = i; j < discount.size(); j++) {
            if (tempMap.find(discount[j]) == tempMap.end()) {
                break;
            }

            tempMap[discount[j]]--;

            if (tempMap[discount[j]] < 0) {
                break;
            }

            tempCount++;

            if (tempCount == totalNumber)
            {
                result++;
                break;
            }
        }
    }

    return result;
}

int main()
{
    vector<string> want = { "banana", "apple", "rice", "pork", "pot"};
    vector<int> number = {3, 2, 2, 2, 1};
    vector<string> discount =
    {
        "chicken", "apple", "apple", "banana", "rice", "apple", "pork",
        "banana", "pork", "rice", "pot", "banana", "apple", "banana"
    };

    cout << solution(want, number, discount);

    return 0;
}