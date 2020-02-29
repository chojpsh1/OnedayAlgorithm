#include<iostream>
#include<memory.h>

#define MAXSIZE 1000001

using namespace std;

int64_t Arr[MAXSIZE];
int64_t Sum[MAXSIZE*2];

void init()
{
    memset(Arr, 0, sizeof(Arr));
    for (int i=1; i<MAXSIZE; i++)
    {
        if (i%2 == 1)
        {
            Arr[i] += i;
            for (int j=i*2; j<MAXSIZE; j+=i)
            {
                Arr[j] += i;
            }
        }
        if (i == 1)
        {
            Sum[i] = Arr[1];
        }
        else
        {
            Sum[i] = Sum[i-1] + Arr[i];
        }
    }
    
}

int main(int argc, char** argv)
{
    int testCase;
    int T;
    
    scanf("%d", &T);
    
    init();
    for(testCase = 1; testCase <= T; testCase++)
    {
        int L, R;
        scanf("%d %d", &L, &R);
        int64_t answer = Sum[R] - Sum[L-1];
        printf("#%d %lld\n", testCase, answer);
    }
    return 0;
}
