#include <iostream>
#include <memory.h>

#define MAXSIZE 100

using namespace std;

int Delicious[MAXSIZE][MAXSIZE];
int CheeseType[MAXSIZE][MAXSIZE];
bool BeEaten[MAXSIZE][MAXSIZE];
int MaxNum;
int N;

void init()
{
    memset(Delicious, 0, sizeof(Delicious));
    memset(CheeseType, 0, sizeof(CheeseType));
    MaxNum = 0;
    cin >> N;
}

bool IsRange(int y, int x)
{
    if (y < 0 || y >= N)
    {
        return false;
    }
    if (x < 0 || x >= N)
    {
        return false;
    }
    return true;
}

void VisitNeighbor(int y, int x, int BlockIdx)
{
    CheeseType[y][x] = BlockIdx;
    if (IsRange(y-1, x) && CheeseType[y-1][x] == 0)
    {
        VisitNeighbor(y-1, x, BlockIdx);
    }
    if (IsRange(y+1, x) && CheeseType[y+1][x] == 0)
    {
        VisitNeighbor(y+1, x, BlockIdx);
    }
    if (IsRange(y, x-1) && CheeseType[y][x-1] == 0)
    {
        VisitNeighbor(y, x-1, BlockIdx);
    }
    if (IsRange(y, x+1) && CheeseType[y][x+1] == 0)
    {
        VisitNeighbor(y, x+1, BlockIdx);
    }
}

void CalcRemainBlock()
{
    int numOfBlock = 0;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (CheeseType[i][j] == 0)
            {
                numOfBlock++;
                VisitNeighbor(i, j, numOfBlock);
            }
        }
    }
    if (numOfBlock > MaxNum)
    {
        MaxNum = numOfBlock;
    }
}

void EatCheese()
{
    for (int day=0; day<MAXSIZE; day++)
    {
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                if (Delicious[i][j] == day)
                {
                    CheeseType[i][j] = -1;
                }
            }
        }
        CalcRemainBlock();
        for (int i=0; i<N;i++)
        {
            for (int j=0; j<N; j++)
            {
                if (CheeseType[i][j] != -1)
                {
                    CheeseType[i][j] = 0;
                }
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
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                cin >> Delicious[i][j];
            }
        }
        EatCheese();
        cout << "#" << testCase << " " << MaxNum << endl;
    }
    return 0;
}
