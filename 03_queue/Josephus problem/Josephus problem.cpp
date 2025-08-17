﻿#include <iostream>
#include <queue>

using namespace std;

int solution(int N, int K)
{
    queue<int> q;

    // 1부터 N까지의 번호를 큐에 추가

    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    // 큐에 하나의 요소가 남을 때까지 순회
    while (q.size() > 1)
    {
        for (int i = 0; i < K - 1; i++)
        {
            // K번째 사람을 찾기 위해 앞부터 제거하고 뒤에 추가
            q.push(q.front());
            q.pop();
        }
        // K번째 사람 제거
        q.pop();
    }
    return q.front();
}

int main()
{
    cout << solution(5, 2);
    return 0;
}