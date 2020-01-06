#include <iostream>
#include <string>
#include <queue>
#include <memory.h>

#define MAXSIZE 500

using namespace std;

string Sound;
bool Frog[MAXSIZE][5];
queue<int> EndSounds;

void init() {
    memset(Frog, false, sizeof(Frog));
    while (!EndSounds.empty())
    {
        EndSounds.pop();
    }
    cin >> Sound;
}

int CalcMinFrogNum()
{
    int frogIndex = 0;
    int startSound = 0;
    int endSound = 0;
    for (int i=0; i<Sound.length(); i++)
    {
        int soundIndex;
        if (Sound.at(i) == 'c')
        {
            startSound++;
            if (!EndSounds.empty())
            {
                int idx = EndSounds.front();
                EndSounds.pop();
                Frog[idx][0] = true;
                continue;
            }
            Frog[frogIndex++][0] = true;
            continue;
        }
        else if (Sound.at(i) == 'r')
        {
            soundIndex = 1;
        }
        else if (Sound.at(i) == 'o')
        {
            soundIndex = 2;
        }
        else if (Sound.at(i) == 'a')
        {
            soundIndex = 3;
        }
        else
        {
            endSound++;
            soundIndex = 4;
        }
        bool isImpos = true;
        for (int j=0; j<frogIndex; j++)
        {
            if (Frog[j][soundIndex - 1] && !Frog[j][soundIndex])
            {
                Frog[j][soundIndex] = true;
                isImpos = false;
                if (soundIndex == 4)
                {
                    EndSounds.push(j);
                    for (int r=0; r<5; r++)
                    {
                        Frog[j][r] = false;
                    }
                }
                break;
            }
        }
        if (isImpos)
        {
            return -1;
        }
    }
    if (startSound == endSound)
    {
        return frogIndex;
    }
    else
    {
        return -1;
    }
}

int main() {
    
    int T;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++) {
        init();
        cout << "#" << testCase << " " << CalcMinFrogNum() << endl;
    }
    return 0;
}

