#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Num;
int N;

void init()
{
    Num.clear();
    cin >> N;
    for (int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        Num.push_back(tmp);
    }
    sort(Num.begin(), Num.end());
}

int CalcNumH()
{
    int H = 0;
    for (int i=1; i<=N; i++)
    {
        if (Num.at(N-i) >= i)
        {
            H = i;
        }
        else
        {
            break;
        }
    }
    return H;
}
// H보다 큰 자연수가 H개 이상일려면 벡터를 오름차순 정렬했을 때, 뒤에서부터 H개 앞으로 왔을 때의 값이 H 이하여야 한다.

int main(int argc, char** argv)
{
    int T;
    cin >> T;
    
    for(int testCase = 1; testCase <= T; testCase++)
    {
        init();
        cout << "#" << testCase << " " << CalcNumH() << endl;
    }
    return 0;
}
