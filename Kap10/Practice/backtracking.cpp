#include<bits/stdc++.h>
using namespace std;


void printAllPath{int maze[][4], int row, int col, int srcX, int srcY, string &output, vector<vector<bool>> &visited } {

    if(srcX == row-1 && srcY == col-1) {
        cout << output << endl;
        return;
    }

    


}

int main() {

    int maze[4][4] = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };

    int row = 4;
    int col = 4;

    int srcX = 0;
    int srcY = 0;
    string output = "";

    vector<vector<bool>> visited(row, vector<bool>(col, false));

    if(maze[0][0]) {
        cout << "No Path Exists" << endl;
    } else {
        visited[srcX][srcY] = true;
        printAllPath(maze, row, col, srcX, srcY, output, visted);
    }
    return 0;
}