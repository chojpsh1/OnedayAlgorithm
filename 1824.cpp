#include <iostream>
#include <memory.h>
#include <string>

#define MAXSIZE 20
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

using namespace std;

int R, C;
bool Path[MAXSIZE][MAXSIZE][16][4];
char Program[MAXSIZE][MAXSIZE+1];
int Directions[2][4] = {{-1, 1, 0, 0,}, {0, 0, -1, 1}};
bool IsExit;

void init()
{
    memset(Path, false, sizeof(Path));
    IsExit = false;
    memset(Program, '\n', sizeof(Program));
    cin >> R >> C;
    for (int i=0; i<R; i++)
    {
        for (int j=0; j<C; j++)
        {
            cin >> Program[i][j];
            if (Program[i][j] == '@')
            {
                IsExit = true;
            }
        }
    }
}

bool FindExit(char current, int x, int y, int val, int dir)
{
    int toX, toY, toVal, toDir;
    if (0 <= current - '0' && current - '0' <= 9)
    {
        toX = x + Directions[0][dir];
        toY = y + Directions[1][dir];
        if (toX >= C)
        {
            toX = 0;
        }
        else if (toX < 0)
        {
            toX = C - 1;
        }
        if (toY >= R)
        {
            toY = 0;
        }
        else if (toY < 0)
        {
            toY = R - 1;
        }
        toVal = current - '0';
        toDir = dir;
    }
    else if (current == '<')
    {
        toX = x-1;
        if (toX < 0)
        {
            toX = C - 1;
        }
        toY = y;
        toVal = val;
        toDir = LEFT;
    }
    else if (current == '>')
    {
        toX = x+1;
        if (toX >= C)
        {
            toX = 0;
        }
        toY = y;
        toVal = val;
        toDir = RIGHT;
    }
    else if (current == '^')
    {
        toX = x;
        toY = y-1;
        if (toY < 0)
        {
            toY = R - 1;
        }
        toVal = val;
        toDir = UP;
    }
    else if (current == 'v')
    {
        toX = x;
        toY = y+1;
        if (toY >= R)
        {
            toY = 0;
        }
        toVal = val;
        toDir = DOWN;
    }
    else if (current == '_')
    {
        if (val == 0)
        {
            toX = x+1;
            if (toX >= C)
            {
                toX = 0;
            }
            toY = y;
            toVal = val;
            toDir = RIGHT;
        }
        else
        {
            toX = x-1;
            if (toX < 0)
            {
                toX = C - 1;
            }
            toY = y;
            toVal = val;
            toDir = LEFT;
        }
    }
    else if (current == '|')
    {
        if (val == 0)
        {
            toX = x;
            toY = y+1;
            if (toY >= R)
            {
                toY = 0;
            }
            toVal = val;
            toDir = DOWN;
        }
        else
        {
            toX = x;
            toY = y-1;
            if (toY < 0)
            {
                toY = R - 1;
            }
            toVal = val;
            toDir = UP;
        }
    }
    else if (current == '?')
    {
        for (int i=0; i<4; i++)
        {
            toX = x + Directions[0][i];
            toY = y + Directions[1][i];
            if (toX >= C)
            {
                toX = 0;
            }
            else if (toX < 0)
            {
                toX = C - 1;
            }
            if (toY >= R)
            {
                toY = 0;
            }
            else if (toY < 0)
            {
                toY = R - 1;
            }
            toVal = val;
            toDir = i;
            if (Path[toY][toX][toVal][toDir])
            {
                return false;
            }
            Path[toY][toX][toVal][toDir] = true;
            bool tmp = FindExit(Program[toY][toX], toX, toY, toVal, toDir);
            if (tmp)
            {
                return true;
            }
            else
            {
                continue;
            }
        }
        return false;
    }
    else if (current == '.')
    {
        toX = x + Directions[0][dir];
        toY = y + Directions[1][dir];
        if (toX >= C)
        {
            toX = 0;
        }
        else if (toX < 0)
        {
            toX = C - 1;
        }
        if (toY >= R)
        {
            toY = 0;
        }
        else if (toY < 0)
        {
            toY = R - 1;
        }
        toVal = val;
        toDir = dir;
    }
    else if (current == '+')
    {
        toX = x + Directions[0][dir];
        toY = y + Directions[1][dir];
        if (toX >= C)
        {
            toX = 0;
        }
        else if (toX < 0)
        {
            toX = C - 1;
        }
        if (toY >= R)
        {
            toY = 0;
        }
        else if (toY < 0)
        {
            toY = R - 1;
        }
        toVal = (val == 15) ? 0 : val+1;
        toDir = dir;
    }
    else if (current == '-')
    {
        toX = x + Directions[0][dir];
        toY = y + Directions[1][dir];
        if (toX >= C)
        {
            toX = 0;
        }
        else if (toX < 0)
        {
            toX = C - 1;
        }
        if (toY >= R)
        {
            toY = 0;
        }
        else if (toY < 0)
        {
            toY = R - 1;
        }
        toVal = (val == 0) ? 15 : val-1;
        toDir = dir;
    }
    else
    {
        return true;
    }
    
    if (Path[toY][toX][toVal][toDir])
    {
        return false;
    }
    Path[toY][toX][toVal][toDir] = true;
    return FindExit(Program[toY][toX], toX, toY, toVal, toDir);
}

int main()
{
    int T;
    cin >> T;
    
    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        cout << "#" << testCase << " ";
        if (!IsExit)
        {
            cout << "NO" << endl;
        }
        else
        {
            if (FindExit(Program[0][0], 0, 0, 0, RIGHT))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
