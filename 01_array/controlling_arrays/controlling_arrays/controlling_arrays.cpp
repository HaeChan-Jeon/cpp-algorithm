#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> &lst);

int main()
{
    int count;
    cin >> count;
    vector<int> lst(count);

    int temp;
    for (int i = 0; i < count; ++i)
    {
        cin >> temp;
        lst[i] = temp;
    }

    solution(lst);

    for (int it : lst) {
        cout << it;
    }

    return 0;
}

vector<int> solution(vector<int> &lst) {
    sort(lst.begin(), lst.end(), greater<int>());
    lst.erase(unique(lst.begin(), lst.end()), lst.end());
    return lst;
}