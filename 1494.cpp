#include <iostream>
#include <memory.h>
#include <limits.h>

#define MAXINDEX 20

using namespace std;

int N;
int Worms[2][MAXINDEX];
int64_t MinVector;
bool IsMatch[MAXINDEX];

void init()
{
    memset(Worms, 0, sizeof(Worms));
    memset(IsMatch, false, sizeof(IsMatch));
    MinVector = LLONG_MAX;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> Worms[0][i] >> Worms[1][i];
    }
}

void CalcMinVector(int index, int depth)
{
    if (depth == N / 2)
    {
        int64_t xSum = 0;
        int64_t ySum = 0;
        for (int i=0; i<N; i++)
        {
            if (IsMatch[i])
            {
                xSum += Worms[0][i];
                ySum += Worms[1][i];
            }
            else
            {
                xSum -= Worms[0][i];
                ySum -= Worms[1][i];
            }
        }
        if (xSum * xSum + ySum * ySum < MinVector)
        {
            MinVector = xSum * xSum + ySum * ySum;
        }
        return;
    }
    for (int i=index; i<N; i++)
    {
        if (!IsMatch[i])
        {
            IsMatch[i] = true;
            CalcMinVector(i + 1, depth + 1);
            IsMatch[i] = false;
        }
    }
}
int main()
{
    int T;
    cin >> T;
    
    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        CalcMinVector(0, 0);
        cout << "#" << testCase << " " << MinVector <<endl;
    }
    return 0;
}
