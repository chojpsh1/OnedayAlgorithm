#include <iostream>
#include <memory.h>
#include <string>

#define MAXSIZE 20
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

using namespace std;

int Tile[MAXSIZE][MAXSIZE];
int N;

void init()
{
    cin >> N;
    memset(Tile, 0, sizeof(Tile));
}

void PushEmpty(int type)
{
    int lastZero = 0;
    if (type == LEFT)
    {
        for (int i=0; i<N; i++)
        {
            bool check = false;
            for (int j=0; j<N; j++)
            {
                if (Tile[i][j] == 0)
                {
                    if (!check)
                    {
                        lastZero = j;
                        check = true;
                    }
                    while (Tile[i][j+1] != 0 && j < N-1)
                    {
                        Tile[i][lastZero] = Tile[i][j+1];
                        lastZero++;
                        Tile[i][j+1] = 0;
                        j++;
                    }
                }
            }
        }
    }
    else if (type == RIGHT)
    {
        for (int i=0; i<N; i++)
        {
            bool check = false;
            for (int j=N-1; j>=0; j--)
            {
                if (Tile[i][j] == 0)
                {
                    if (!check)
                    {
                        lastZero = j;
                        check = true;
                    }
                    while (Tile[i][j-1] != 0 && j > 0)
                    {
                        Tile[i][lastZero] = Tile[i][j-1];
                        lastZero--;
                        Tile[i][j-1] = 0;
                        j--;
                    }
                }
            }
        }
    }
    else if (type == UP)
    {
        for (int i=0; i<N; i++)
        {
            bool check = false;
            for (int j=0; j<N; j++)
            {
                if (Tile[j][i] == 0)
                {
                    if (!check)
                    {
                        lastZero = j;
                        check = true;
                    }
                    while (Tile[j+1][i] != 0 && j < N-1)
                    {
                        Tile[lastZero][i] = Tile[j+1][i];
                        lastZero++;
                        Tile[j+1][i] = 0;
                        j++;
                    }
                }
            }
        }
    }
    else
    {
        for (int i=0; i<N; i++)
        {
            bool check = false;
            for (int j=N-1; j>=0; j--)
            {
                if (Tile[j][i] == 0)
                {
                    if (!check)
                    {
                        lastZero = j;
                        check = true;
                    }
                    while (Tile[j-1][i] != 0 && j > 0)
                    {
                        Tile[lastZero][i] = Tile[j-1][i];
                        lastZero--;
                        Tile[j-1][i] = 0;
                        j--;
                    }
                }
            }
        }
    }
}

void Merge(int type)
{
    if (type == LEFT)
    {
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                if (Tile[i][j] == Tile[i][j+1])
                {
                    Tile[i][j] *= 2;
                    Tile[i][j+1] = 0;
                    j++;
                }
            }
        }
    }
    else if (type == RIGHT)
    {
        for (int i=0; i<N; i++)
        {
            for (int j=N-1; j>=0; j--)
            {
                if (Tile[i][j] == Tile[i][j-1])
                {
                    Tile[i][j] *= 2;
                    Tile[i][j-1] = 0;
                    j--;
                }
            }
        }
    }
    else if (type == UP)
    {
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                if (Tile[j][i] == Tile[j+1][i])
                {
                    Tile[j][i] *= 2;
                    Tile[j+1][i] = 0;
                    j++;
                }
            }
        }
    }
    else
    {
        for (int i=0; i<N; i++)
        {
            for (int j=N-1; j>=0; j--)
            {
                if (Tile[j][i] == Tile[j-1][i])
                {
                    Tile[j][i] *= 2;
                    Tile[j-1][i] = 0;
                    j--;
                }
            }
        }
    }
    PushEmpty(type);
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    for (int testCase=1; testCase<=T; testCase++)
    {
        init();
        cout << "#" << testCase << endl;
        string type;
        cin >> type;
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                cin >> Tile[i][j];
            }
        }
        if (type == "left")
        {
            PushEmpty(LEFT);
            Merge(LEFT);
        }
        else if (type == "right")
        {
            PushEmpty(RIGHT);
            Merge(RIGHT);
        }
        else if (type == "up")
        {
            PushEmpty(UP);
            Merge(UP);
        }
        else
        {
            PushEmpty(DOWN);
            Merge(DOWN);
        }
        
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                cout << Tile[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
