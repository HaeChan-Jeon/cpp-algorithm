#include <iostream>
#include <vector>

using namespace std;

void mapping(vector<int>& hash, const vector<int>& arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > target)
        {
            continue; // target 보다 큰 값은 담지 않음 (답이 될 가능성 없음)
        }
        hash[arr[i]] = 1; // 현재 원소 값을 hash 인덱스로 활용, 해당 위치의 값을 1로 설정
    }
}

bool solution(vector<int> arr, int target)
{
    vector<int> hash(target + 1, 0); // target + 1개의 공간이 있는 hash 벡터 선언
    mapping(hash, arr, target); // arr의 원소 값에 대해서 hash table 생성

    for (int i = 0; i < arr.size(); i++)
    {
        int num = target - arr[i]; // target에서 arr[i]을 뺀 값이 있는지 확인하기 위해 num 선언

        if (arr[i] == num) // arr[i]가 num과 같으면 오답(제약 조건에 중복 숫자는 없음)
        {
            continue;
        }
        if (num < 0) // 음수는 없으므로 오답
        {
            continue;
        }
        if (hash[num]) // num이 없다면 합이 target이 되는 변수를 찾았으므로 true 반환
        {
            return true;
        }
    }
    return false; // 두 수의 합이 target인 경우를 찾지 못하면 false 반환
}

int main(void)
{
    vector<int> arr;
    int target;

    arr = { 1, 2, 3, 4, 8 };
    target = 6;

    bool answer = solution(arr, target);

    std::cout << answer;

    return 0;
}