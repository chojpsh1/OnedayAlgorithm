#include <iostream>
#include <string>

#define MAXSIZE 1000001

using namespace std;

int Group[MAXSIZE];
int N, M;

void init()
{
    for (int i=0; i<MAXSIZE; i++)
    {
        Group[i] = i;
    }
    cin >> N >> M;
}

int GetGroupId(int num)
{
    if (Group[num] == num)
    {
        return num;
    }
    else
    {
        return Group[num] = GetGroupId(Group[num]);
    }
}

void MergeGroup(int a, int b)
{
    int aGroup = GetGroupId(a);
    int bGroup = GetGroupId(b);
    
    if (aGroup == bGroup)
    {
        return;
    }
    if (aGroup < bGroup)
    {
        Group[bGroup] = aGroup;
    }
    else
    {
        Group[aGroup] = bGroup;
    }
}

int main()
{
    int T;
    cin >> T;
    
    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        string result = "";
        for (int i=0; i<M; i++)
        {
            int cmd;
            int a, b;
            cin >> cmd >> a >> b;
            if (cmd == 0)
            {
                MergeGroup(a, b);
            }
            else
            {
                if (GetGroupId(a) == GetGroupId(b))
                {
                    result += "1";
                }
                else
                {
                    result += "0";
                }
            }
        }
        cout << "#" << testCase << " " << result << endl;
    }
    return 0;
}
