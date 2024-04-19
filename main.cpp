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
bool exista = true;

ifstream in ("level3_example.in");
ofstream out ("output3");

void giveRoad(int x, int y) { // dont translate into romanian

    pos.x = x;
    pos.y = y;

    for (int i = 0; i < path.length(); ++i) {

        if(mat[pos.x][pos.y] == '.' && mat[pos.x][pos.y] != 'P')
        {
            mat[pos.x][pos.y] = 'P';

            switch (path.at(i)) {
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
        else
        {
            exista = false;
            return;
        }
    }

}

int main (void) {
    in >> N;

    for (int i = 0; i < N; ++i) {
        in >> w >> h;
        const int height = h+2;
        const int width = w+2;


        mat = new char*[width];
        for(int i = 0; i <  width ; ++i)
        {
            mat[i] = new char[height];
        }


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

        exista = true;
        for(int j = 1 ; j <= w ; ++j)
        {
            for(int k = 1 ; k <= h ; ++k)
            {
                giveRoad(j,k);
                if(exista == false)cout<<"INVALID";
            }
        }
        if(exista)cout<<"VALID";

        delete mat;
    }
}
