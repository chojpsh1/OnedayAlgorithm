#include <iostream>

using namespace std;

int x1, y1;
int x2, y2;

void init()
{
    cin >> x1 >> y1 >> x2 >> y2;
}

int CalcMinMovement()
{
    int tmpx = x2 - x1;
    int tmpy = y2 - y1;
    if (tmpx < 0)
    {
        tmpx *= -1;
    }
    if (tmpy < 0)
    {
        tmpy *= -1;
    }
    int base = (tmpx > tmpy) ? tmpx : tmpy;
    if ((tmpx + tmpy) % 2 == 0)
    {
        return base *2;
    }
    else
    {
        return base * 2 - 1;
    }
}

int main()
{
    int T;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        cout << "#" << testCase << " " << CalcMinMovement()<< endl;
    }
    return 0;
}

