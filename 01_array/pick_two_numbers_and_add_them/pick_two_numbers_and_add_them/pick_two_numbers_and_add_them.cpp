#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers);

int main()
{
    int count;

    cin >> count;

    vector<int> numbers(count);

    for (int i = 0; i < count; i++)
    {
        int temp;
        cin >> temp;
        numbers[i] = temp;
    }

    vector<int> result = solution(numbers);

    for (const auto it : result)
    {
        cout << it << " ";
    }

    return 0;
}

vector<int> solution(vector<int> numbers)
{
    set<int> arr;

    for (int i = 0; i < numbers.size(); ++i)
    {
        for (int j = i+1; j < numbers.size(); j++)
        {
            arr.insert(numbers[i] + numbers[j]);
        }
    }

    vector<int> result(arr.begin(), arr.end());

    //vector<int> result;

    //for (const auto it : arr)
    //{
    //    result.push_back(it);
    //}

    return result;
}