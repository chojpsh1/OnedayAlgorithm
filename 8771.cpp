#include <stdio.h>
#include <iostream>

using namespace std;

int N;
int64_t A, B;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    cin >> T;
    for(int testCase = 1; testCase <= T; testCase++)
    {
        cin >> N >> A >> B;
        int64_t Answer;
        if (A > B)
        {
            Answer = 0;
        }
        else if (N == 1)
        {
            if (A == B)
            {
                Answer = 1;
            }
            else
            {
                Answer = 0;
            }
        }
        else
        {
            Answer = (B-A) * (N-2) + 1;
            //B * (N-2) - A * (N-2) + 1 -> 가장 최대 합 - 가장 최소 합 (가능한 합들이 최대 합과 최소 합 사이에서 1씩 증가됨)
        }
        cout << "#" << testCase << " " << Answer << '\n';
    }
    return 0;
}
