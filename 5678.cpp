#include<iostream>
#include <string>

using namespace std;

int solution(string s)
{
    int answer=0;
    
    for (int i=0; i<s.length(); i++)
    {
        int j=1;
        int tmpLen = 1;
        while ((i-j >= 0) && (i+j < s.length()))
        {
            if (s.at(i-j) == s.at(i+j))
            {
                tmpLen += 2;
                j++;
            }
            else
            {
                break;
            }
        }
        if (answer < tmpLen)
        {
            answer = tmpLen;
        }
    }
    
    for (int i=0; i<s.length(); i++)
    {
        int j=1;
        int tmpLen = 0;
        while ((i-j+1 >= 0) && (i+j < s.length()))
        {
            if (s.at(i-j+1) == s.at(i+j))
            {
                tmpLen += 2;
                j++;
            }
            else
            {
                break;
            }
        }
        if (answer < tmpLen)
        {
            answer = tmpLen;
        }
    }
    return answer;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string str;
        cin >> str;
        cout << "#" << test_case << " " << solution(str) << endl;
    }
    return 0;
}
