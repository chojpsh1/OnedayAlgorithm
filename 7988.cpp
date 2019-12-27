#include <iostream>
#include <memory.h>
#include <string>
#include <vector>

#define MAXSIZE 100
using namespace std;

int Graph[MAXSIZE][MAXSIZE];
vector<string> Gamer;
int Team[MAXSIZE];
bool CanMatch;

void init()
{
    memset(Graph, 0, sizeof(Graph));
    Gamer.clear();
    memset(Team, 0, sizeof(Team));
    CanMatch = true;
}

void DFS(int start, int depth, int teamId)
{
    if (depth == Gamer.size())
    {
        return;
    }
    Team[start] = teamId;
    for (int i=0; i<Gamer.size(); i++)
    {
        if (Graph[start][i] == 1)
        {
            if (Team[i] != 0 && Team[i] == teamId)
            {
                CanMatch = false;
                return;
            }
            if (Team[i] == 0)
            {
                DFS(i, depth + 1, teamId * -1);
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    for (int testCase=1; testCase<=T; testCase++)
    {
        init();
        int K;
        cin >> K;
        string a, b;
        for (int synergy=0; synergy<K;  synergy++)
        {
            cin >> a >> b;
            int indexA = -1;
            int indexB = -1;
            
            for (int i=0; i<Gamer.size(); i++)
            {
                if (Gamer.at(i) == a)
                {
                    indexA = i;
                }
                if (Gamer.at(i) == b)
                {
                    indexB = i;
                }
            }
            if (indexA == -1)
            {
                indexA = Gamer.size();
                Gamer.push_back(a);
            }
            if (indexB == -1)
            {
                indexB = Gamer.size();
                Gamer.push_back(b);
            }
            Graph[indexA][indexB] = 1;
            Graph[indexB][indexA] = 1;
        }
        DFS(0, 0, -1);
        cout << "#" << testCase << " ";
        if (CanMatch)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
