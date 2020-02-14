#include <iostream>
#include <memory.h>

#define MAXSIZE 50

using namespace std;

int Raisin[MAXSIZE][MAXSIZE];
int Cut[MAXSIZE+1][MAXSIZE+1][MAXSIZE+1][MAXSIZE+1];
int RaiSum[MAXSIZE][MAXSIZE];
int N, M;

void init()
{
    memset(Cut, -1, sizeof(Cut));
    memset(Raisin, 0, sizeof(Raisin));
    memset(RaiSum, 0, sizeof(RaiSum));
    cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            cin >> Raisin[i][j];
        }
    }
    RaiSum[0][0] = Raisin[0][0];
    for (int i=1; i<M; i++)
    {
        RaiSum[0][i] = RaiSum[0][i-1] + Raisin[0][i];
    }
    for (int i=1; i<N; i++)
    {
        RaiSum[i][0] = RaiSum[i-1][0] + Raisin[i][0];
    }
    for (int i=1; i<N; i++)
    {
        for (int j=1; j<M; j++)
        {
            RaiSum[i][j] = RaiSum[i-1][j] + RaiSum[i][j-1] - RaiSum[i-1][j-1] + Raisin[i][j];
        }
    }
}

int CalcMinRaisin(int rowCut, int colCut, int below, int right)
{
    if (below == 1 && right == 1)
    {
        return 0;
    }
    int &minRaisin = Cut[rowCut][colCut][below][right];
    if (minRaisin != -1)
    {
        return minRaisin;
    }
    minRaisin = 987654321;
    int sum = RaiSum[rowCut + below - 1][colCut + right -1];
    bool row = false;
    bool col = false;
    if (rowCut >= 1)
    {
        sum -= RaiSum[rowCut - 1][colCut + right - 1];
        row = true;
    }
    if (colCut >= 1)
    {
        sum -= RaiSum[rowCut + below - 1][colCut - 1];
        col = true;
    }
    if (row && col)
    {
        sum += RaiSum[rowCut-1][colCut-1];
    }
    for (int i=1; i<below; i++)
    {
        minRaisin = min(minRaisin, sum + CalcMinRaisin(rowCut, colCut, i, right)
                        + CalcMinRaisin(rowCut + i, colCut, below - i, right));
    }
    for (int i=1; i<right; i++)
    {
        minRaisin = min(minRaisin, sum + CalcMinRaisin(rowCut, colCut, below, i) +
                        CalcMinRaisin(rowCut, colCut + i, below, right - i));
    }
    
    return minRaisin;
}
int main()
{
    int T;
    cin >> T;
    
    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        cout << "#" << testCase << " " << CalcMinRaisin(0, 0, N, M) <<endl;
    }
    return 0;
}

