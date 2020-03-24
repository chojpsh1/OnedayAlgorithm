#include <stdio.h>
#include <iostream>

using namespace std;

int N, X;

void init()
{
    scanf("%d %d", &N, &X);
}

bool IsRange()
{
    int end = 2 * N - 1;
    if (X == 1 || X == end)
    {
        return false;
    }
    return true;
}

int main(int argc, char** argv)
{
    int T;
    scanf("%d", &T);
    for(int testCase = 1; testCase <= T; testCase++)
    {
        init();
        int answer;
        if (IsRange())
        {
            answer = 1;
        }
        else
        {
            answer = 0;
        }
        printf("#%d %d\n", testCase, answer);
    }
    return 0;
}
