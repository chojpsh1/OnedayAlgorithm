#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

#define MAXSIZE 500000

using namespace std;

int Cows[MAXSIZE];
int Horses[MAXSIZE];
int N, M;
int Xdist;
int MinDist;

void init()
{
    memset(Cows, 0, sizeof(Cows));
    memset(Horses, 0, sizeof(Horses));
    MinDist = 987654321;
    scanf("%d %d", &N, &M);
    int x1, x2;
    scanf("%d %d", &x1, &x2);
    Xdist = x1 - x2;
    if (Xdist < 0)
    {
        Xdist *= -1;
    }

    for (int i=0; i<N; i++)
    {
        scanf("%d", &Cows[i]);
    }
    for (int i=0; i<M; i++)
    {
        scanf("%d", &Horses[i]);
    }
    sort(Cows, Cows + N);
    sort(Horses, Horses + M);
}

int CalcMinDistPair()
{
    int cIdx = 0;
    int hIdx = 0;
    int countPair = 0;
    
    while (cIdx < N && hIdx < M)
    {
        int tmp = Cows[cIdx] - Horses[hIdx];
        if (tmp > 0)
        {
            hIdx++;
        }
        else if (tmp < 0)
        {
            cIdx++;
            tmp *= -1;
        }
        else
        {
            if (cIdx + 1 < N && hIdx + 1 < M)
            {
                if (Cows[cIdx+1] < Horses[hIdx+1])
                {
                    cIdx++;
                }
                else
                {
                    hIdx++;
                }
            }
            else
            {
                if (cIdx + 1 != N)
                {
                    cIdx++;
                }
                else
                {
                    hIdx++;
                }
            }
        }
        if (tmp == MinDist)
        {
            countPair++;
        }
        else if (tmp < MinDist)
        {
            MinDist = tmp;
            countPair = 1;
        }
    }
    return countPair;
}

int main(int argc, char** argv)
{
    int T;
    cin >> T;
    for(int testCase = 1; testCase <= T; testCase++)
    {
        init();
        printf("#%d %d %d\n", testCase, Xdist+MinDist, CalcMinDistPair());
    }
    return 0;
}
