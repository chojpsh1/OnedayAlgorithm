#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Number;

void init()
{
    Number.clear();
}

int CalcOriginal()
{
    sort(Number.begin(), Number.end());
    int mid = (int)Number.size() / 2;
    if (Number.size() % 2 == 0)
    {
        return Number.at(mid - 1) * Number.at(mid);
    }
    else
    {
        return Number.at(mid) * Number.at(mid);
    }
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    for (int testCase=1; testCase<=T; testCase++)
    {
        init();
        int N;
        cin >> N;
        for (int i=0; i<N; i++)
        {
            int tmp;
            cin >> tmp;
            Number.push_back(tmp);
        }
        cout << "#" << testCase << " " << CalcOriginal() << endl;
    }
    return 0;
}
