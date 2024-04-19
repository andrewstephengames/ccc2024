#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

//sqrt((x2-x1)^2 - (y2-y1)^2)

ifstream in ("level2_example.in");
ofstream out ("output2");

struct Vec2 {
    int x, y;
} pos, mn, mx;

//pos.x = 0
//pos.y = 0

int main (void) {
    int N, w, h;
    string row;
    in >> N;
    for (int i = 0; i < N; ++i) {
        in >> row;
        pos.x = pos.y = 0;
        mn.x = mn.y = 0;
        mx.x = mx.y = 0;
        for (int j = 0; j < row.length(); ++j) {
            switch (row.at(j)) {
                case 'W': {
                    pos.y++;
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
        if (pos.x < mn.x) {
            mn.x = pos.x;
        }
        if (pos.x > mx.x) {
            mx.x = pos.x;
        }
        if (pos.y < mn.y) {
            mn.y = pos.y;
        }
        if (pos.y > mx.y) {
            mx.y = pos.y;
        }
        w = mx.x - mn.x+1;
        h = mx.y - mn.y+1;
        cout << w << " " << h << endl;
        out << w << " " << h << endl;
    }
    return 0;
}
