#include <iostream>
#include <vector>
#include <queue>

#define PAIR pair<int,int>
#define INF 0xfffffffffffffff-1

using namespace std;

long long int dist[100001];
bool visit[100001];
vector<PAIR> Graph[100001];

void Init(int N)
{
    for (int i=0; i<=N; i++)
    {
        Graph[i].clear();
        dist[i] = INF;
        visit[i] = false;
    }
}

long long int Dijkstra()
{
    int N, M, Depart, Dest;
    scanf("%d %d %d %d", &N, &M, &Depart, &Dest);
    Init(N);
    for (int i=0; i<M; i++)
    {
        int a, b, weight;
        scanf("%d %d %d", &a, &b, &weight);
        Graph[a].push_back({weight, b});
        Graph[b].push_back({weight, a});
    }
    dist[Depart] = 0;
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> q;
    q.push({0, Depart});
    while (!q.empty())
    {
        PAIR tmp = q.top();
        q.pop();
        long long int next = tmp.second;
        long long int w = tmp.first;
        if (dist[next] < w)
        {
            continue;
        }
        visit[next] = true;
        for (int i=0; i<Graph[next].size(); i++)
        {
            long long int v = Graph[next][i].second;
            long long int nextTov = Graph[next][i].first;
            if (!visit[v] && dist[v] > dist[next] + nextTov)
            {
                dist[v] = dist[next] + nextTov;
                q.push({dist[v], v});
            }
        }
    }
    return dist[Dest];
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int testCase = 1; testCase <= T; testCase++)
    {
        cout << "#" << testCase << " " << Dijkstra() << endl;
    }
    return 0;
}

