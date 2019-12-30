#include <iostream>
#include <memory.h>
#include <vector>

#define MAXSIZE 100

using namespace std;

int Elements[MAXSIZE][MAXSIZE];
bool Visit[MAXSIZE][MAXSIZE];
vector<int> Information;
int N;

void init()
{
    cin >> N;
    memset(Elements, 0, sizeof(Elements));
    memset(Visit, false, sizeof(Visit));
    Information.clear();
    
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cin >> Elements[i][j];
        }
    }
}

void SetVisit(int row, int col, int x, int y)
{
    for (int i=0; i<col; i++)
    {
        for (int j=0; j<row; j++)
        {
            Visit[y+i][x+j] = true;
        }
    }
}

void GatherInfo()
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (Elements[i][j] != 0 && !Visit[i][j])
            {
                int row = 1;
                int tmpX = j;
                Visit[i][j] = true;
                
                while (Elements[i][tmpX+1] != 0)
                {
                    row++;
                    tmpX++;
                }
                int tmpY = i;
                int col = 1;
                while (Elements[tmpY+1][j] != 0)
                {
                    col++;
                    tmpY++;
                }
                SetVisit(row, col, j, i);
                j = tmpX;
                Information.push_back(row*col);
                Information.push_back(col);
                Information.push_back(row);
            }
        }
    }
}

void SortInform()
{
    int tmp;
    int tmpCol, tmpRow;
    for (int i=3; i<Information.size(); i=i+3)
    {
        tmp = Information.at(i);
        tmpCol = Information.at(i+1);
        tmpRow = Information.at(i+2);
        int j = i - 3;
        while ((j >= 0) && (tmp <= Information.at(j)))
        {
            if (tmp == Information.at(j))
            {
                if (tmpCol > Information.at(j+1))
                {
                    break;
                }
            }
            Information.at(j+3) = Information.at(j);
            Information.at(j+4) = Information.at(j+1);
            Information.at(j+5) = Information.at(j+2);
            j = j - 3;
        }
        Information.at(j+3) = tmp;
        Information.at(j+4) = tmpCol;
        Information.at(j+5) = tmpRow;
    }
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    for (int testCase=1; testCase<=T; testCase++)
    {
        init();
        cout << "#" << testCase << " ";
        GatherInfo();
        SortInform();
        cout << Information.size() / 3;
        for (int i=1; i<Information.size(); i=i+3)
        {
            cout << " " << Information.at(i) << " " << Information.at(i+1);
        }
        cout << endl;
        
    }
    return 0;
}
