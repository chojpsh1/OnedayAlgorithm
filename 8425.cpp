#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> S;
int N;

void init()
{
    S.clear();
    cin >> N;
    for (int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        S.push_back(tmp);
    }
}

int CalcXorSum()
{
    int sum = 0;
    for (int i=0; i<N; i++)
    {
        sum ^= S.at(i);
    }
    return sum;
}

int CalcWinCase()
{
    int win = 0;
    int sum = CalcXorSum();
    if (sum == 0)
    {
        return 0;
    }
    else
    {
        for (int i=0; i<N; i++)
        {
            if ((sum ^ S.at(i)) <= S.at(i))
            {
                win++;
            }
        }
    }
    return win;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    cin >> T;
    for(int testCase = 1; testCase <= T; testCase++)
    {
        init();
        cout << "#" << testCase << " " << CalcWinCase() << '\n';
    }
    return 0;
}
