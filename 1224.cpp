#include <iostream>
#include <string>
#include <stack>

using namespace std;

string Formula;
stack<char> S;
stack<int> NumS;

void init()
{
    Formula.clear();
    cin >> Formula;
}

bool IsNum(char aChar)
{
    return ('0' <= aChar && aChar <= '9');
}

int GetPrior(char aChar)
{
    if (aChar == '(')
    {
        return 1;
    }
    else if (aChar == '*')
    {
        return 3;
    }
    else
    {
        return 2;
    }
}

string MakePostfix()
{
    string postfix;
    for (int i=0; i<Formula.length(); i++)
    {
        if (IsNum(Formula.at(i)))
        {
            postfix.push_back(Formula.at(i));
        }
        else
        {
            if (Formula.at(i) == ')')
            {
                char tmp = S.top();
                S.pop();
                while (tmp != '(')
                {
                    postfix.push_back(tmp);
                    tmp = S.top();
                    S.pop();
                }
            }
            else if (Formula.at(i) == '*' || Formula.at(i) == '+')
            {
                char tmp;
                while (!S.empty())
                {
                    tmp = S.top();
                    if (GetPrior(tmp) < GetPrior(Formula.at(i)))
                    {
                        break;
                    }
                    S.pop();
                    postfix.push_back(tmp);
                }
                S.push(Formula.at(i));
            }
            else
            {
                S.push('(');
            }
        }
    }
    while (!S.empty())
    {
        postfix.push_back(S.top());
        S.pop();
    }
    return postfix;
}

int CalcPostfix()
{
    string postfix = MakePostfix();
    for (int i=0; i<postfix.length(); i++)
    {
        if (IsNum(postfix.at(i)))
        {
            NumS.push(postfix.at(i) - '0');
        }
        else
        {
            int a = NumS.top();
            NumS.pop();
            int b = NumS.top();
            NumS.pop();
            if (postfix.at(i) == '+')
            {
                NumS.push(a + b);
            }
            else
            {
                NumS.push(a * b);
            }
        }
    }
    int result = NumS.top();
    NumS.pop();
    return result;
}

int main()
{
    for (int testCase = 1; testCase <= 10; testCase++)
    {
        int len;
        cin >> len;
        init();
        cout << "#" << testCase << " " << CalcPostfix() << endl;
    }
    return 0;
}
