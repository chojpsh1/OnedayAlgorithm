#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int PosNum[10];
int PosIndex;
int Answer;

void init()
{
    memset(PosNum, 0, sizeof(PosNum));
    PosIndex = 0;
    Answer = 9999999;
}

int CalcMakeCount(int num)
{
    int makeCount = 0;
    while (num != 0)
    {
        int i;
        for (i=0; i<PosIndex; i++)
        {
            if (PosNum[i] == num % 10)
            {
                num /= 10;
                makeCount++;
                break;
            }
        }
        if (i == PosIndex)
        {
            return 0;
        }
    }
    return makeCount;
}

void DFS(int num, int mulCount)
{
    int tmp = CalcMakeCount(num);
    if (tmp != 0)
    {
        Answer = min(Answer, tmp + mulCount);
        return;
    }
    for (int i=2; i*i<=num; i++)
    {
        if (num % i == 0)
        {
            tmp = CalcMakeCount(i);
            if (tmp != 0)
            {
                DFS(num / i, tmp + mulCount + 1);
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    for (int testCase=1; testCase<=T; testCase++)
    {
        init();
        for (int i=0; i<10; i++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
            {
                PosNum[PosIndex++] = i;
            }
        }
        int goal;
        cin >> goal;
        DFS(goal, 1);
        if (Answer == 9999999)
        {
            Answer = -1;
        }
        cout << "#" << testCase << " " << Answer << endl;
    }
    return 0;
}
