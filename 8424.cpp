#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

vector<vector<int>> Graph;
int N;
int Cycle[1001];
int Answer;

void init()
{
    Answer = 0;
    for (int i=0; i<Graph.size(); i++)
    {
        Graph[i].clear();
    }
    memset(Cycle, 0, sizeof(Cycle));
    cin >> N;
    for (int i=0; i<=N; i++)
    {
        vector<int> tmp;
        Graph.push_back(tmp);
    }
    
    for (int i=0; i<N; i++)
    {
        int x, y;
        cin >> x >> y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }
}

void CalcCycleLength(int prev, int cur, int depth)
{
    Cycle[cur] = depth;
    for (int i=0; i<Graph[cur].size(); i++)
    {
        if (Answer != 0)
        {
            return;
        }
        int idx = Graph[cur][i];
        if (Cycle[idx] != 0)
        {
            if (idx != prev)
            {
                Answer = Cycle[cur] - Cycle[idx] + 1;
                return;
            }
        }
        else
        {
            CalcCycleLength(cur, idx, depth+1);
        }
    }
}

int main(int argc, char** argv)
{
    int T;
    cin >> T;
    for(int testCase = 1; testCase <= T; testCase++)
    {
        init();
        CalcCycleLength(-1, 1, 1);
        cout << "#" << testCase << " " << Answer << endl;
    }
    return 0;
}
