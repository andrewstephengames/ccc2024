#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct Vec2 {
    int x, y;
} pos;

int N, w, h;
char **mat;
string path;

ifstream in ("level3_example.out");
ofstream out ("output3");

void giveRoad(int x, int y) { // dont translate into romanian
    for (int i = 0; i < path.length(); ++i) {
        switch (path.at(i)) {
           case 'W': {
                if (mat[x, y+1] == 'X')
                    return;
           } break;
           case 'D': {
               pos.x++;
           } break;
           case 'S': {
               pos.y--;
           } break;
           case 'A': {
               pos.x--;
           } break;
           default: {
               cerr << "Unreachable\n";
               exit(EXIT_FAILURE);
           }
        }
    }
}

int main (void) {
    in >> N;
    for (int i = 0; i < N; ++i) {
        in >> w >> h;
        mat = new char[w+2][h+2];
            for (int j = 1; j <= w; ++j) {
                mat[j][h+1] = 'X';
                mat[j][0] = 'X';
            }
            for (int j = 1; j <= h; ++j) {
                mat[w+1][j] = 'X';
                mat[0][j] = 'X';
            }
            for (int j = 1; j <= w; ++j) {
                for (int k = 1; k <= h; ++j) {
                    in >> mat[j][k];
                }
            }
            in >> path;
            for (int j = 0; j < path.length; ++j) {
            }           
        delete mat;
    }
}
