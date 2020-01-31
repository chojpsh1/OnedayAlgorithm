#include <iostream>
#include <memory.h>
#include <string>

#define MAXSIZE 2000

using namespace std;

int Price[26];
int Graph[MAXSIZE][MAXSIZE];
int K;
string Str;

void init()
{
    memset(Price, 0, sizeof(Price));
    memset(Graph, 0, sizeof(Graph));
    int L;
    cin >> L >> K;
    cin >> Str;
    for (int i=0; i<K; i++)
    {
        int add, del;
        cin >> add >> del;
        Price[i] = (add < del) ? add : del;
    }
    
    for (int i=0; i<Str.length(); i++)
    {
        for (int j=i; j<Str.length(); j++)
        {
            Graph[i][j] = (i == j) ? 0 : 20000001;
        }
    }
}

int CalcMinCost()
{
    for (int i=1; i<Str.length(); i++)
    {
        int x = i;
        int y = 0;
        //y번째부터 x번째까지의 문자를 가지고 팰린드롬
        for (int k=0; k<Str.length()-i; k++)
        {
            Graph[y][x] = (Graph[y][x] < Graph[y][x-1] + Price[Str.at(x) - 97]) ?
                                Graph[y][x] : Graph[y][x-1] + Price[Str.at(x) - 97];
            Graph[y][x] = (Graph[y][x] < Graph[y+1][x] + Price[Str.at(y) - 97]) ?
                                Graph[y][x] : Graph[y+1][x] + Price[Str.at(y) - 97];
            //y번째부터 x번째까지 부분 문자열에서 첫 문자, 끝 문자가 같으면 양 끝을 제외한 부분 문자열(y+1번째부터 x-1번째까지)을 팰린드롬으로 만드는 비용과 위에서 측정한 비용을 비교
            if (Str.at(x) == Str.at(y))
            {
                Graph[y][x] = (Graph[y][x] < Graph[y+1][x-1]) ? Graph[y][x] : Graph[y+1][x-1];
            }
            x++;
            y++;
        }
    }
    return Graph[0][Str.length()-1];
}

int main()
{
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        cout << "#" << testCase << " "  << CalcMinCost() << endl;
    }
    return 0;
}
