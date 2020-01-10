#include <iostream>
#include <string>

using namespace std;

string Str;
int Bar;
int Frag;

void init()
{
    Str.clear();
    Bar = 0;
    Frag = 0;
    cin >> Str;
}

void CalcFragment()
{
    for (int i=0; i<Str.length(); i++)
    {
        if (Str.at(i) == '(')
        {
            if (Str.at(i+1) == ')')
            {
                Frag += Bar;
                i++;
            }
            else
            {
                Bar++;
            }
        }
        else
        {
            Frag++;
            Bar--;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        CalcFragment();
        cout << "#" << testCase << " " << Frag << endl;
    }
    return 0;
}
