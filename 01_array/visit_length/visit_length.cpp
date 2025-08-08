#include <string>
#include <vector>
using namespace std;

bool check[11][11][4];

int answer = 0;

int curX;
int curY;

void U()
{
    if (curY == 10)
    {
        return;
    }
    else
    {
        int px = curX, py = curY;
        curY++;

        if (check[px][py][0] == true)
        {
            return;
        }

        check[px][py][0] = true;
        check[curX][curY][1] = true;

        answer++;
    }

    return;
}

void D()
{
    if (curY == 0)
    {
        return;
    }
    else
    {
        int px = curX, py = curY;
        curY--;

        if (check[px][py][1] == true)
        {
            return;
        }

        check[px][py][1] = true;
        check[curX][curY][0] = true;

        answer++;
    }

    return;
}

void R()
{
    if (curX == 10)
    {
        return;
    }
    else
    {
        int px = curX, py = curY;
        curX++;

        if (check[px][py][3] == true)
        {
            return;
        }

        check[px][py][3] = true;
        check[curX][curY][2] = true;

        answer++;
    }

    return;
}

void L()
{
    if (curX == 0)
    {
        return;
    }
    else
    {
        int px = curX, py = curY;
        curX--;

        if (check[px][py][2] == true)
        {
            return;
        }

        check[px][py][2] = true;
        check[curX][curY][3] = true;

        answer++;
    }

    return;
}

int solution(string dirs) {
    answer = 0;
    curX = 5; curY = 5;

    for (char dir : dirs)
    {
        if (dir == 'U')
        {
            U();
        }

        if (dir == 'D')
        {
            D();
        }

        if (dir == 'R')
        {
            R();
        }

        if (dir == 'L')
        {
            L();
        }
    }

    return answer;
}
