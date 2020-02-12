#include <iostream>
#include <memory.h>
#include <stdlib.h>

#define MAXSZE 100001

using namespace std;

int N, K;
int Diamonds[MAXSZE];
int Start = MAXSZE;
int End = 0;

void init()
{
    memset(Diamonds, 0, sizeof(Diamonds));
    cin >> N >> K;
    for (int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp > End)
        {
            End = tmp;
        }
        if (tmp < Start)
        {
            Start = tmp;
        }
        Diamonds[tmp]++;
    }
}

int CalcMaxSize()
{
    int maxCount = 0;
    for (int i=Start; i<=End; i++)
    {
        int countNum = 0;
        if (Diamonds[i] == 0)
        {
            continue;
        }
        for (int j=0; j<=K; j++)
        {
            countNum += Diamonds[i+j];
        }
        if (countNum > maxCount)
        {
            maxCount = countNum;
        }
    }
    return maxCount;
}

int main()
{
    int T;
    cin >> T;
    
    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        cout << "#" << testCase << " " << CalcMaxSize() << endl;
    }
    return 0;
}
