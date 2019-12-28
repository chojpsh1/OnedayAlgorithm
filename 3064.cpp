#include <iostream>
#include <memory.h>
#include <cmath>
#include <vector>

#define MAXSIZE 100000
#define TREEMAX 265000
using namespace std;

int Tree[TREEMAX];
int Elements[MAXSIZE];
int N, M;

int BuildTree(int index, int start, int end)
{
    if (start == end)
    {
        Tree[index] = Elements[start];
    }
    else
    {
        Tree[index] = BuildTree(index*2, start, (start+end)/2) + BuildTree(index*2+1, (start+end)/2+1, end);
    }
    return Tree[index];
}

void init()
{
    memset(Tree, 0, sizeof(Tree));
    memset(Elements, 0, sizeof(Elements));
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++)
    {
        scanf("%d", &Elements[i]);
    }
    BuildTree(1, 1, N);
}

void Update(int currentIndex, int index, int start, int end, int value)
{
    if (index < start || index > end)
    {
        return;
    }
    else
    {
        Tree[currentIndex] = Tree[currentIndex] + value;
        if (start != end)
        {
            Update(currentIndex*2, index, start, (start+end)/2, value);
            Update(currentIndex*2+1, index, (start+end)/2+1, end, value);
        }
    }
}

int Sum(int index, int start, int end, int left, int right)
{
    if (left > end || right < start)
    {
        return 0;
    }
    else if (left <= start && end <= right)
    {
        return Tree[index];
    }
    else
    {
        return Sum(index*2, start, (start+end)/2, left, right) + Sum(index*2+1, (start+end)/2+1, end, left, right);
    }
}
int main(int argc, const char * argv[])
{
    int T;
    scanf("%d", &T);
    for (int testCase=1; testCase<=T; testCase++)
    {
        init();
        printf("#%d ", testCase);
        for (int cmd=0; cmd<M; cmd++)
        {
            int type, a, b;
            scanf("%d %d %d", &type, &a, &b);
            if (type == 1)
            {
                Update(1, a, 1, N, b);
            }
            else
            {
                printf("%d ", Sum(1, 1, N, a, b));
            }
        }
        printf("\n");
    }
    return 0;
}
