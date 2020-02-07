#include <iostream>
#include <memory.h>

using namespace std;

int P[3][3];
int N;

void init()
{
    memset(P, 0, sizeof(P));
    cin >> N;
    for (int i=1; i<=N; i++)
    {
        int pi;
        cin >> pi;
        if (pi % 3 != i % 3)
        {
            P[pi%3][i%3]++;
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
        //1. 먼저 [0][1] <-> [1][0] 서로 바꿀 수 있는 거, [0][2] <-> [2][0] 서로 바꿀 수 있는거.
        //2. 그리고 [1][2] <-> [2][1] 서로 바꿀 수 있는 거
        //3. [1][0]나 [2][0] 에서 1단계에서 충족되는 게 없어서 남은 애들은 ex. [0][1] -> [1][2] -> [2][0] 이런 식으로 옮겨야 하기에 2단계에서 서로 바꿀 수 있는 거 제외하고 남은 횟수가 중간다리 역할 해주는 애들의 횟수. 그렇기 때문에 중간다리 역할하는 [1][2]나 [2][1] 중에 제일 최대값을 가져와야함.
        cout << "#" << testCase << " " << P[1][0] + P[2][0] + max(P[1][2], P[2][1]) << endl;
    }
    return 0;
}
