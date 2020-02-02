#include <iostream>
#include <memory.h>
#include <stdlib.h>

using namespace std;

int64_t Color[1000];
int X, Y, Z;
int A, B, C;
int N;

void init()
{
    memset(Color, 0, sizeof(Color));
    cin >> X >> Y >> Z >> A >> B >> C >> N;
}
//(A, B, C) 좌표가 있는 곳의 xz 평면만 일단 본다. xz평면에서 x축에 평행한 z=C선 위의 점들에 대해서 (A, C)와의 거리를 가지고 일단 색을 칠해준다. (%N)
//이걸 z=C선 위, 아래로 각각 N번 반복하는 부분은 전체 합, 나머지 부분은 이전 번호 칠한 개수와 똑같다.
//그럼 xz평면에 대해서는 칠해준거임. 이걸 똑같이 y축으로도 적용시키면 입체로 칠해준 것.
void FillColor(int coord, int std, int64_t base[])
{
    int mul = (coord - 1 - std) / N;
    int64_t sum = 0;
    for (int i=0; i<N; i++)
    {
        sum += base[i];
    }
    for (int i=0; i<N; i++)
    {
        Color[i] += mul * sum + base[i];
    }
    int remain = (coord - 1 - std) % N;
    if (remain > 0)
    {
        for (int i=0; i<N; i++)
        {
            int64_t rSum = 0;
            for (int j=1; j<=remain; j++)
            {
                int idx = i - j;
                if (idx < 0)
                {
                    idx += N;
                }
                rSum += base[idx];
            }
            Color[i] += rSum;
        }
    }
    mul = std / N;
    for (int i=0; i<N; i++)
    {
        Color[i] += mul * sum;
    }
    remain = std % N;
    if (remain > 0)
    {
        for (int i=0; i<N; i++)
        {
            int64_t rSum = 0;
            for (int j=1; j<=remain; j++)
            {
                int idx = i - j;
                if (idx < 0)
                {
                    idx += N;
                }
                rSum += base[idx];
            }
            Color[i] += rSum;
        }
    }
}

void PaintCube()
{
    int64_t base[N];
    memset(base, 0, sizeof(base));
    
    for (int i=0; i<X; i++)
    {
        int xDiff = abs(i - A);
        base[xDiff % N]++;
    }
    FillColor(Z, C, base);
    for (int i=0; i<N; i++)
    {
        base[i] = Color[i];
    }
    memset(Color, 0, sizeof(Color));
    FillColor(Y, B, base);
}

void PrintResult()
{
    for (int i=0; i<N; i++)
    {
        cout << " " << Color[i];
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    
    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        PaintCube();
        cout << "#" << testCase;
        PrintResult();
    }
    return 0;
}
