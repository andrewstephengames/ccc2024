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

        if(mat[pos.x][pos.y] == '.' && mat[pos.x][pos.y] != '0')
        {
            mat[pos.x][pos.y] = '0';

            switch (path.at(i)) {
                case 'W': {
                    if(mat[pos.x][pos.y + 1] == 'X' || mat[pos.x][pos.y + 1] == '0'){
                        cout << "INVALID";
                        return;
                    }
                    else{
                        pos.y++;
                    }
                } break;
                case 'D': {
                    if(mat[pos.x + 1][pos.y] == 'X' || mat[pos.x + 1][pos.y] == '0'){
                        cout << "INVALID";
                        return;
                    }
                    else{
                        pos.x++;
                    }
                } break;
                case 'S': {
                    if(mat[pos.x][pos.y - 1] == 'X' || mat[pos.x][pos.y - 1] == '0'){
                        cout << "INVALID";
                        return;
                    }
                    else{
                        pos.y--;
                    }
                } break;
                case 'A': {
                    if(mat[pos.x - 1][pos.y] == 'X' || mat[pos.x - 1][pos.y] == '0'){
                        cout << "INVALID";
                        return;
                    }
                    else{
                        pos.x--;
                    }
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
    int width, height;
    for(int i = 1 ; i <= N ; i++)
    {
        in >> width >> height;

        mat = new char*[height];
        for(int j = 0 ; j < height ; ++j)
        {
            mat[j] = new char[width];
        }

        for(int j = 0 ; j < height ; ++j)
        {
            for(int k = 0 ; k < width ; ++k)
            {
                in >> mat[j][k];
            }
        }

        in >> path;


        cout<<w<<" "<<h<<endl;
        for(int j = 0 ; j < height ; ++j)
        {
            for(int k = 0 ; k < width ; ++k)
                cout<<mat[j][k]<<" ";

            cout<<endl;
        }
        cout<<path;

        cout<<endl<<endl;
    }
}
