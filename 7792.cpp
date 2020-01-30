#include <iostream>
#include <memory.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<string> Names;

void init()
{
    Names.clear();
    cin >> N;
    getchar();
    for (int i=0; i<N; i++)
    {
        string name;
        getline(cin, name);
        Names.push_back(name);
    }
    sort(Names.begin(), Names.end());
}

string SelectLeader()
{
    int maxCount = 0;
    int maxIndex = 0;
    for (int i=0; i<Names.size(); i++)
    {
        bool countChar[128];
        memset(countChar, false, sizeof(countChar));
        int curCount = 0;
        for (int j=0; j<Names.at(i).length(); j++)
        {
            char tmp = Names.at(i).at(j);
            if (tmp == ' ')
            {
                continue;
            }
            else if (!countChar[(int)tmp])
            {
                curCount++;
                countChar[(int)tmp] = true;
            }
        }
        if (curCount > maxCount)
        {
            maxCount = curCount;
            maxIndex = i;
        }
    }
    return Names.at(maxIndex);
}

int main()
{
    int T;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        cout << "#" << testCase << " " << SelectLeader() << endl;
    }
    return 0;
}
