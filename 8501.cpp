#include <iostream>
#include <memory.h>
#include <vector>

#define MAXSIZE 1001

using namespace std;

int64_t Factorial[MAXSIZE];
int64_t Result[MAXSIZE];

void init()
{
    memset(Factorial, 0, sizeof(Factorial));
    memset(Result, 0, sizeof(Result));
    Factorial[0] = 1;
    Result[0] = 0;
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    for (int i=1; i<MAXSIZE; i++)
    {
        Factorial[i] = (Factorial[i-1] * i) % 1000000007;
        Result[i] = (i * Result[i-1]) % 1000000007 + ((i/2) * Factorial[i-1]) % 1000000007;
        //추가되는 숫자는 무조건 이전 조합의 숫자들보다 제일 큰 숫자이다. 따라서 일단 이전 조합이 추가되는 숫자 수만큼 반복되므로
        //i * Result[i-1]을 한다. 여기서 이전 조합 경우에서 사이사이에 추가 숫자를 넣어 비교해 보면 추가 숫자가 뒤집히는 경우가 i/2
        //이다. 이게 이전 조합의 경우의 수(n-1)! 만큼 반복되므로 (i/2)*Factorial[i-1]을 더한다.
    }
    for (int testCase=1; testCase<=T; testCase++)
    {
        int N;
        cin >> N;
        cout << "#" << testCase << " " << Result[N] % 1000000007 << endl;
    }
    return 0;
}
