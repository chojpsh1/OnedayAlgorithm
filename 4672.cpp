#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

string W;
int CountChar[256];

void init()
{
    W.clear();
    memset(CountChar, 0, sizeof(CountChar));
    cin >> W;
    sort(W.begin(), W.end()); //정렬 후 문자열의 부분 문자열들이 만들 수 있는 팰린드롬 갯수가 결국 최대 갯수이다.
    for (int i=0; i<W.length(); i++)
    {
        int idx = ((int)W.at(i)) - 97;
        CountChar[idx]++;
    }
}

int CalcPalindrome()
{
    int answer = 0;
    for (int i=0; i<256; i++)
    {
        int tmp = CountChar[i];
        if (tmp > 0)
        {
            answer += (tmp * (tmp + 1)) / 2;
        }
    }
    return answer;
}

int main(int argc, char** argv)
{
    int T;
    cin >> T;
    
    for(int testCase = 1; testCase <= T; testCase++)
    {
        init();
        cout << "#" << testCase << " " << CalcPalindrome() << endl;
    }
    return 0;
}
