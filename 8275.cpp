#include <iostream>
#include <memory.h>

using namespace std;

int Cage[7];
int Command[10][3];
int Result[7];
int N, X, M;

void init()
{
    memset(Cage, 0, sizeof(Cage));
    memset(Command, 0 ,sizeof(Command));
    memset(Result, -1, sizeof(Result));
    cin >> N >> X >> M;
    for (int i=0; i<M; i++)
    {
        cin >> Command[i][0] >> Command[i][1] >> Command[i][2];
    }
}

void CalcHamster(int start)
{
    if (start > N)
    {
        for (int i=0; i<M; i++)
        {
            int tmp = 0;
            for (int j=Command[i][0] ; j<=Command[i][1]; j++)
            {
                tmp += Cage[j];
            }
            if (tmp != Command[i][2])
            {
                return;
            }
        }
        if (Result[1] == -1)
        {
            for (int i=1; i<=N; i++)
            {
                Result[i] = Cage[i];
            }
        }
        else
        {
            int totalTmp = 0;
            int totalResult = 0;
            for (int i=1; i<=N; i++)
            {
                totalTmp += Cage[i];
                totalResult += Result[i];
            }
            if (totalTmp > totalResult)
            {
                for (int i=1; i<=N; i++)
                {
                    Result[i] = Cage[i];
                }
            }
            else if (totalTmp == totalResult)
            {
                int order = 1;
                for (int i=1; i<=N; i++)
                {
                    if (Result[i] > Cage[i])
                    {
                        order = 1;
                        break;
                    }
                    else if (Result[i] < Cage[i])
                    {
                        order = 2;
                        break;
                    }
                }
                if (order == 1)
                {
                    for (int i=1; i<=N; i++)
                    {
                        Result[i] = Cage[i];
                    }
                }
            }
        }
    }
    else
    {
        for (int i=0; i<=X; i++)
        {
            Cage[start] = i;
            CalcHamster(start + 1);
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
        cout << "#" << testCase;
        CalcHamster(1);
        if (Result[1] == -1)
        {
            cout << " -1" << endl;
        }
        else
        {
            for (int i=1; i<=N; i++)
            {
                cout << " " << Result[i];
            }
            cout << endl;
        }
    }
    return 0;
}

