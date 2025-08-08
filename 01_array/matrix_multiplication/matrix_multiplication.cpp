#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector <vector<int>> arr2);

int main()
{
    vector<vector<int>> arr1 = { {1, 4}, {3, 2}, {4, 1} };
    vector <vector<int>> arr2 = { {3, 3}, {3, 3} };

    solution(arr1, arr2);

    return 0;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector <vector<int>> arr2)
{
    int row1 = arr1.size();
    int col1 = arr1[0].size();
    int col2 = arr2[0].size();

    vector<vector<int>> result(row1, vector<int>(col2, 0));

    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            for (int k = 0; k < col1; ++k) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return result;
}
