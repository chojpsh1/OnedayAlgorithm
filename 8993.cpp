#include <stdio.h>
#include <iostream>

using namespace std;

int64_t N;

bool IsEnd()
{
    while (N > 1)
    {
        if (N % 2 == 0)
        {
            N /= 2;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
    int T;
    cin >> T;
    for(int testCase = 1; testCase <= T; testCase++)
    {
        cin >> N;
        cout << "#" << testCase << " ";
        if (IsEnd())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
