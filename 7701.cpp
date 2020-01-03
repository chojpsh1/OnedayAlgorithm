#include <iostream>
#include <set>
#include <cstring>

using namespace std;

set<string> NameSet;
int N;
int MaxLen;

void init()
{
    NameSet.clear();
    MaxLen = 0;
    scanf("%d", &N);
    
    for (int i=0; i<N; i++)
    {
        char str[50];
        scanf("%s", str);
        string tmp(str);
        if (tmp.length() > MaxLen)
        {
            MaxLen = (int)tmp.length();
        }
        NameSet.insert(tmp);
    }
}

void PrintName()
{
    for (int i=1; i<=MaxLen; i++)
    {
        set<string>::iterator iter;
        for (iter=NameSet.begin(); iter!=NameSet.end(); iter++)
        {
            if ((*iter).length() == i)
            {
                printf("%s", (*iter).c_str());
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int T;
    scanf("%d", &T);
    
    for (int testCase=1; testCase<=T; testCase++)
    {
        init();
        printf("#%d\n", testCase);
        PrintName();
    }
    return 0;
}
