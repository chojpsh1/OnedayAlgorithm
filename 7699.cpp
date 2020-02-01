#include <iostream>
#include <memory.h>
#include <string>

#define MAXSIZE 20

using namespace std;

bool Visit['Z'+1];
int R, C;
char Island[MAXSIZE][MAXSIZE];
int MaxDepth;

void init()
{
    memset(Visit, false, sizeof(Visit));
    memset(Island, '0', sizeof(Island));
    MaxDepth = 0;
    cin >> R >> C;
    for (int i=0; i<R; i++)
    {
        for (int j=0; j<C; j++)
        {
            cin >> Island[i][j];
        }
    }
}

bool IsRange(int x, int y)
{
    if ((0 <= x && x < C) && (0 <= y && y < R))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CalcMaxVisit(int x, int y, int depth)
{
    Visit[Island[y][x] - 65] = true;
    bool isEnd = true;
    if (IsRange(x+1, y) && !Visit[Island[y][x+1] - 65])
    {
        isEnd = false;
        CalcMaxVisit(x+1, y, depth+1);
        Visit[Island[y][x+1] - 65] = false;
    }
    if (IsRange(x-1, y) && !Visit[Island[y][x-1] - 65])
    {
        isEnd = false;
        CalcMaxVisit(x-1, y, depth+1);
        Visit[Island[y][x-1] - 65] = false;
    }
    if (IsRange(x, y+1) && !Visit[Island[y+1][x] - 65])
    {
        isEnd = false;
        CalcMaxVisit(x, y+1, depth+1);
        Visit[Island[y+1][x] - 65] = false;
    }
    if (IsRange(x, y-1) && !Visit[Island[y-1][x] - 65])
    {
        isEnd = false;
        CalcMaxVisit(x, y-1, depth+1);
        Visit[Island[y-1][x] - 65] = false;
    }
    if (isEnd)
    {
        MaxDepth = (MaxDepth < depth) ? depth : MaxDepth;
        return;
    }
}

int main()
{
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        CalcMaxVisit(0, 0, 1);
        cout << "#" << testCase << " " << MaxDepth << endl;
    }
    return 0;
}
