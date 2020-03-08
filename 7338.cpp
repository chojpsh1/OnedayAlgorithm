#include <stdio.h>
#include <iostream>

using namespace std;

int64_t Y;
int M;

void init()
{
    scanf("%lld %d", &Y, &M);
}

void CalcThirteenth()
{
    if ((Y - 2016) % 13 == 0)
    {
        Y -= ((Y - 2016) / 13);
    }
    else
    {
        M = M - ((Y - 2016) % 13);
        if (M <= 0)
        {
            Y -= 1;
            M = 13 + M;
        }
        Y -= ((Y - 2016) / 13);
    }
}
int main(int argc, char** argv)
{
    int T;
    scanf("%d", &T);
    
    for(int testCase = 1; testCase <= T; testCase++)
    {
        init();
        CalcThirteenth();
        printf("#%d %lld %d\n", testCase, Y, M);
    }
    return 0;
}
