#include <iostream>

using namespace std;

int Result;
int PrevX, PrevY;
int W, H, N;

void init()
{
    Result = 0;
    cin >> W >> H >> N;
    cin >> PrevX >> PrevY;
}

int CalcCostDFS(int curX, int curY)
{
    int x = curX - PrevX;
    int y = curY - PrevY;
    int tmpX = PrevX;
    int tmpY = PrevY;
    int d = 0;
    
    if (x * y > 0)
    {
        if (x > 0)
        {
            if (x < y)
            {
                d = x;
                tmpX += x;
                tmpY += x;
            }
            else
            {
                d = y;
                tmpX += y;
                tmpY += y;
            }
        }
        else
        {
            if (x < y)
            {
                d = y;
                tmpX += y;
                tmpY += y;
            }
            else
            {
                d = x;
                tmpX += x;
                tmpY += x;
            }
        }
    }
    if (curX > tmpX)
    {
        tmpX = curX - tmpX;
    }
    else
    {
        tmpX = tmpX - curX;
    }
    if (curY > tmpY)
    {
        tmpY = curY - tmpY;
    }
    else
    {
        tmpY = tmpY - curY;
    }
    if (d < 0)
    {
        d = -d;
    }
    return tmpX + tmpY + d;
}

int main()
{
    int T;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        for (int i=1; i<N; i++)
        {
            int curX, curY;
            cin >> curX >> curY;
            Result += CalcCostDFS(curX, curY);
            PrevX = curX;
            PrevY = curY;
        }
        cout << "#" << testCase << " " << Result << endl;
    }
    return 0;
}
