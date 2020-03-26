#include <stdio.h>
#include <iostream>
#include <memory.h>

#define MAXSIZE 91
using namespace std;

int K;
int64_t A[MAXSIZE];
int64_t B[MAXSIZE];

void init()
{
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    A[0] = 1;
    B[0] = 0;
    A[1] = 2;
    B[1] = 1;
    for (int i=2; i<=90; i++)
    {
        B[i] = A[i-1];
        A[i] = A[i-1] + B[i-1];
    }
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    cin >> T;
    init();
    for(int testCase = 1; testCase <= T; testCase++)
    {
        cin >> K;
        cout << "#" << testCase << " " << A[K] << " " << B[K] << '\n';
    }
    return 0;
}
