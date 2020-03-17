#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <stdlib.h>

using namespace std;

int CoordX[102];
int CoordY[102];
bool Visit[100];
int N;
int Answer;

void init()
{
    memset(CoordX, 0, sizeof(CoordX));
    memset(CoordY, 0, sizeof(CoordY));
    memset(Visit, false, sizeof(Visit));
    Answer = 987654321;
    cin >> N;
    for (int i=0; i<N+2; i++)
    {
        cin >> CoordX[i] >> CoordY[i];
    }
}

void CalcMinCost(int depth, int idx, int xSum, int ySum)
{
    Visit[idx] = true;
    if (depth == N)
    {
        xSum += abs(CoordX[1] - CoordX[idx]);
        ySum += abs(CoordY[1] - CoordY[idx]);
        if (Answer > xSum + ySum)
        {
            Answer = xSum + ySum;
        }
        return;
    }
    for (int i=2; i<N+2; i++)
    {
        if (!Visit[i] && idx != i)
        {
            CalcMinCost(depth+1, i, xSum + abs(CoordX[idx] - CoordX[i]), ySum + abs(CoordY[idx] - CoordY[i]));
            Visit[i] = false;
        }
    }
}

int main(int argc, char** argv)
{
    int T;
    cin >> T;
    for(int testCase = 1; testCase <= T; testCase++)
    {
        init();
        CalcMinCost(0, 0, 0, 0);
        cout << "#" << testCase << " " << Answer << endl;
    }
    return 0;
}
