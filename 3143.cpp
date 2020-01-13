#include <iostream>
#include <string>

using namespace std;

string A, B;

void init()
{
    A.clear();
    B.clear();
}

int CalcWordCount()
{
    int count = 0;
    int index = (int)A.find(B);
    while (index != -1)
    {
        count++;
        A.replace(index, B.length(), "");
        index = (int)A.find(B);
    }
    count += A.length();
    return count;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        cin >> A >> B;
        cout << "#" << testCase << " " << CalcWordCount() << endl;
    }
    return 0;
}
