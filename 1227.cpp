#include <iostream>
#include <stdio.h>
#include <string>

#define WALL 1
#define GOAL 3
#define VISIT 4
#define SIZE 100
using namespace std;

int Maze[SIZE][SIZE];
int Reachable;

void init() {
    Reachable = 0;
    for (int i = 0; i<SIZE; i++) {
        for (int j = 0; j<SIZE; j++) {
            Maze[i][j] = 0;
        }
    }
}

void createMaze() {
    
    for (int i =0; i<SIZE; i++) {
        string tmp;
        cin >> tmp;
        for (int j=0; j<tmp.size(); j++)
        {
            Maze[i][j] = tmp.at(j) - 48;
        }
    }
}

void dfs(int x, int y) {
    if (Maze[x][y] == GOAL) {
        Reachable = 1;
    }
    Maze[x][y] = VISIT;
    
    if (Maze[x][y+1] != WALL && Maze[x][y+1] != VISIT) {
        dfs(x, y+1);
    }
    if (Maze[x+1][y] != WALL && Maze[x+1][y] != VISIT) {
        dfs(x+1, y);
    }
    if (Maze[x][y-1] != WALL && Maze[x][y-1] != VISIT) {
        dfs(x, y-1);
    }
    if (Maze[x-1][y] != WALL && Maze[x-1][y] != VISIT) {
        dfs(x-1, y);
    }
    return;
}

int main() {
    
    for (int test_case = 0; test_case < 10; test_case++) {
        int T;
        scanf("%d", &T);
        init();
        createMaze();
        dfs(1, 1);
        printf("#%d %d\n", T, Reachable);
    }
    return 0;
}

