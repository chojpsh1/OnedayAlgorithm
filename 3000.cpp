#include <iostream>
#include <set>

#define BASE 20171109
using namespace std;

int N;
multiset<int> Set;

void init()
{
    Set.clear();
    cin >> N;
}

int64_t CalcMiddleNum()
{
    int num;
    cin >> num;
    Set.insert(num);
    multiset<int>::iterator it = Set.begin();
    int64_t mdlSum = 0;
    int mdl = num;
    for (int i=0; i<N; i++)
    {
        int a, b;
        cin >> a >> b;
        Set.insert(a);
        Set.insert(b);
        if (a >= mdl && b >= mdl)
        {
            it++;
        }
        else if (a <= mdl && b <= mdl)
        {
            it--;
        }
        mdlSum += (*it);
        mdlSum %= BASE;
        mdl = (*it);
    }
    return mdlSum;
}

int main()
{
    int T;
    cin >> T;
    
    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        cout << "#" << testCase << " " << CalcMiddleNum() << endl;
    }
    return 0;
}
