#include <iostream>
#include <memory.h>

#define MAXSIZE 100001

using namespace std;

int Factor[MAXSIZE];
int MaxFactorIndex[MAXSIZE];
void init()
{
    memset(Factor, 0, sizeof(Factor));
    memset(MaxFactorIndex, 0, sizeof(MaxFactorIndex));
    Factor[1] = 1;
    for (int i=2; i<=50000; i++)
    {
        for (int j=1; i*j < MAXSIZE; j++)
        {
            Factor[i*j]++;
        }
    }
    int max = 3;
    int maxIndex = 4;
    MaxFactorIndex[1] = 1;
    MaxFactorIndex[2] = 2;
    MaxFactorIndex[3] = 3;
    for (int i=4; i<MAXSIZE; i=i+2)
    {
        if (max <= Factor[i])
        {
            MaxFactorIndex[i] = i;
            max = Factor[i];
            maxIndex = i;
        }
        else
        {
            MaxFactorIndex[i] = maxIndex;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    init();
    for (int testCase = 1; testCase <= T; testCase++)
    {
        int N;
        scanf("%d", &N);
        printf("#%d %d\n", testCase, MaxFactorIndex[N]);
    }
    return 0;
}
