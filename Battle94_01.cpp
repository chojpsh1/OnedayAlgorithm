#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

#define MAXSIZE 100
using namespace std;

int Parking[2][MAXSIZE];
vector<int> Car;
queue<int> Waiting;
int N, M;
int total;

void init()
{
    memset(Parking, 0, sizeof(Parking));
    Car.clear();
    total = 0;
    while (!Waiting.empty())
    {
        Waiting.pop();
    }
    
    cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        cin >> Parking[0][i];
    }
    for (int i=0; i<M; i++)
    {
        int tmp;
        cin >> tmp;
        Car.push_back(tmp);
    }
}

bool IsParking(int carIndex)
{
    for (int spot=0; spot<N; spot++)
    {
        if (Parking[1][spot] == 0)
        {
            Parking[1][spot] = carIndex;
            total += Parking[0][spot] * Car.at(carIndex - 1);
            return true;
        }
    }
    return false;
}

void CalcTotal()
{
    for (int cmd=0; cmd<2*M; cmd++)
    {
        int x;
        cin >> x;
        if (x > 0)
        {
            if (!IsParking(x))
            {
                Waiting.push(x);
            }
        }
        else
        {
            x *= -1;
            for (int i=0; i<N; i++)
            {
                if (Parking[1][i] == x)
                {
                    Parking[1][i] = 0;
                    break;
                }
            }
            if (!Waiting.empty())
            {
                int inCar = Waiting.front();
                Waiting.pop();
                IsParking(inCar);
            }
        }
    }
}

int main() {
    
    int T;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++) {
        init();
        CalcTotal();
        cout << "#" << testCase << " " << total << endl;
    }
    return 0;
}

