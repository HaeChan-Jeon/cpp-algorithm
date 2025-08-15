#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;

    stack<int> stk;

    int xSize = board[0].size();
    int ySize = board.size();

    vector<int> topPos(xSize);

    for (int i = 0; i < xSize; i++)
    {
        for (int j = 0; j < ySize; j++)
        {
            if (board[j][i] == 0)
            {
                topPos[i]++;
            }
            else
            {
                break;
            }
        }
    }

    int target;

    for (int it : moves)
    {
        if (topPos[it - 1] == ySize)
        {
            continue;
        }

        target = board[topPos[it - 1]][it - 1];

        if (stk.empty())
        {
            stk.push(target);
        }
        else
        {
            if (target == stk.top())
            {
                stk.pop();
                answer += 2;
            }
            else
            {
                stk.push(target);
            }
        }

        topPos[it - 1]++;
    }

    return answer;
}

int main()
{
    vector <vector<int>> board;
    vector <int> moves;

    board = {
        { 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 3 },
        { 0, 2, 5, 0, 1 },
        { 4, 2, 4, 4, 2 },
        { 3, 5, 1, 3, 1 }
    };

    moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

    int result = solution(board, moves);

    std::cout << result;
}
