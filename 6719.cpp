#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Lectures;
int N, K;

void init()
{
    Lectures.clear();
    cin >> N >> K;
    for (int i=0; i<N; i++)
    {
        int tmp;
        cin >> tmp;
        Lectures.push_back(tmp);
    }
    sort(Lectures.begin(), Lectures.end());
}

float CalcMaxCapacity()
{
    float capacity = 0;
    for (int i=0; i<K; i++)
    {
        capacity = (capacity + Lectures.at(N - K + i)) / 2;
    }
    return capacity;
}

int main()
{
    int T;
    cin >> T;
    
    for (int testCase = 1; testCase <= T; testCase++)
    {
        init();
        cout << "#" << testCase << " ";
        cout << fixed;
        cout.precision(6);
        cout << CalcMaxCapacity() << endl;
    }
    return 0;
}
