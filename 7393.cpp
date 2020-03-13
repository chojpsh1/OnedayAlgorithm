#include <stdio.h>
#include <iostream>
#include <memory.h>

#define MOD 1000000000

using namespace std;

int Dp[101][10][1<<10];

void init()
{
    memset(Dp, -1, sizeof(Dp));
}
int CalcCount(int len, int num, int status)
{
    if (num < 0 || num > 9)
    {
        return 0;
    }
    if (len == 1)
    {
        if ((1 << num | status) == 1023)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int &tmp = Dp[len][num][status];
    if (tmp != -1)
    {
        return tmp;
    }
    status |= (1 << num);
    tmp = (CalcCount(len-1, num-1, status) + CalcCount(len-1, num+1, status)) % MOD;
    return tmp;
}

int main(int argc, char** argv)
{
    int T;
    cin >> T;
    init();
    for(int testCase = 1; testCase <= T; testCase++)
    {
        int N;
        cin >> N;
        int answer = 0;
        for (int i=1; i<10; i++)
        {
            answer = (answer + CalcCount(N, i, 0)) % MOD;
        }
        cout << "#" << testCase << " " << answer << endl;
    }
    return 0;
}
