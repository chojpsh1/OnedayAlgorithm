#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
    int T;
    scanf("%d", &T);
    
    for (int testCase=1; testCase<=T; testCase++)
    {
        int N;
        scanf("%d", &N);
        
        int result = 0;
        for (int i=0; i*i<=N; i++)
        {
            for (int j=i; i*i+j*j<=N; j++)
            {
                for (int r=j; i*i+j*j+r*r<=N; r++)
                {
                    int sum = i*i + j*j + r*r;
                    int remain = N - sum;
                    int tmp = sqrt(remain);
                    if (tmp * tmp == remain && tmp >= r)
                    {
                        result++;
                    }
                }
            }
        }
        printf("#%d %d\n", testCase, result);
    }
    return 0;
}
