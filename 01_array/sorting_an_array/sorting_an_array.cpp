#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    return arr;
}

int main()
{
    int num;

    cin >> num;
    vector<int> arr(num);

    for (int i = 0; i < num; ++i)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    solution(arr);

    for (const auto &it : arr)
    {
        cout << it << " ";
    }

    return 0;
}