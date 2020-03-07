#include <iostream>
#include <memory.h>

#define MAXSIZE 50
#define WHITE 0
#define BLUE 1
#define RED 2

using namespace std;

char Flag[MAXSIZE][MAXSIZE];
int N, M;
int MinCount;

void init()
{
    memset(Flag, '\n', sizeof(Flag));
    MinCount = 987654321;
    cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            cin >> Flag[i][j];
        }
    }
}

void PaintFlag(int remainRow, int w, int b, int r, int countPaint)
{
    if (countPaint > MinCount)
    {
        return;
    }
    if (remainRow == 0)
    {
        MinCount = countPaint;
        return;
    }
    int wCount = 0;
    int bCount = 0;
    int rCount = 0;
    for (int i=0; i<M; i++)
    {
        char tmp = Flag[N-remainRow][i];
        if (tmp == 'W')
        {
            wCount++;
        }
        else if (tmp == 'B')
        {
            bCount++;
        }
        else
        {
            rCount++;
        }
    }
    
    if (w == 0)
    {
        PaintFlag(remainRow-1, w+1, b, r, countPaint + bCount + rCount);
    }
    else
    {
        if (remainRow == 1)
        {
            PaintFlag(remainRow-1, w, b, r+1, countPaint + wCount + bCount);
        }
        else
        {
            if (b == 0)
            {
                if (remainRow == 2)
                {
                    PaintFlag(remainRow-1, w, b+1, r, countPaint + wCount + rCount);
                }
                else
                {
                    PaintFlag(remainRow-1, w+1, b, r, countPaint + bCount + rCount);
                    PaintFlag(remainRow-1, w, b+1, r, countPaint + wCount + rCount);
                }
            }
            else
            {
                if (r == 0)
                {
                    PaintFlag(remainRow-1, w, b+1, r, countPaint + wCount + rCount);
                    PaintFlag(remainRow-1, w, b, r+1, countPaint + wCount + bCount);
                }
                else
                {
                    PaintFlag(remainRow-1, w, b, r+1, countPaint + wCount + bCount);
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    int T;
    cin >> T;
    
    for(int testCase = 1; testCase <= T; testCase++)
    {
        init();
        PaintFlag(N, 0, 0, 0, 0);
        cout << "#" << testCase << " " << MinCount << endl;
    }
    return 0;
}
