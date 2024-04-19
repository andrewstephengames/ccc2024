#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct Vec2 {
    int x, y;
} pos;

int N, w, h;
char **mat, **clone;
string path;
bool exista = true;

ifstream in ("level3_example.in");
ofstream out ("output3");

void giveRoad(int x, int y) { // dont translate into romanian

    pos.x = x;
    pos.y = y;

    for (int i = 0; i < path.length(); ++i) {

        if(clone[pos.x][pos.y] == '.' && clone[pos.x][pos.y] != 'P')
        {
            clone[pos.x][pos.y] = 'P';

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
    int width, height;
    for(int i = 1 ; i <= N ; i++)
    {
        in >> width >> height;

        mat = new char*[height];
        for(int j = 0 ; j < height ; ++j)
        {
            mat[j] = new char[width];
        }

        clone == new char*[height];
        for(int j = 0 ; j < height ; ++j)
        {
            clone[j] = new char[width];
        }

        for(int j = 0 ; j < height ; ++j)
        {
            for(int k = 0 ; k < width ; ++k)
            {
                in >> mat[j][k];
            }
        }


        in >> path;


        cout<<width<<" "<<height<<endl;
        for(int j = 0 ; j < height ; ++j)
        {
            for(int k = 0 ; k < width ; ++k)
                cout<<mat[j][k]<<" ";

            cout<<endl;
        }
        cout<<path;

        cout<<endl;

        for(int j = 0 ; j < height ; j++)
        {
            for(int k = 0 ; k < width ; k++)
            {
                /*
                for(int p = 0 ; p < height ; p++)
                {
                    for(int t = 0 ; t < width ; t++)
                    {
                        clone[p][t] = mat[p][t];
                    }
                } */


                //giveRoad(j,k);
            }
        }
        if(exista)cout<<"VALID"<<endl<<endl;
        else cout<<"INVALID"<<endl<<endl;

    }
}
