#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct Vec2 {
    int x, y;
} pos;

int N;
char **mat, **cl;
string path;
bool exista = true;

ifstream in ("level3_1.in");
ofstream out ("output3_1");

bool giveRoad(int x, int y, int width, int height) {
    pos.x = x;
    pos.y = y;

    for (int i = 0; i < path.length(); ++i) {
        char current = path.at(i);

        cl[pos.x][pos.y] = 'P';

        switch (current) {
            case 'W':
                if (pos.x - 1 < 0 || cl[pos.x-1][pos.y] == 'X' || cl[pos.x-1][pos.y] == 'P') {
                    return false;
                } else {
                    pos.x--;
                }
                break;
            case 'D':
                if (pos.y + 1 >= width || cl[pos.x][pos.y+1] == 'X' || cl[pos.x][pos.y+1] == 'P') {

                    return false;
                } else {
                    pos.y++;
                }
                break;
            case 'S':
                if (pos.x + 1 >= height || cl[pos.x+1][pos.y] == 'X' || cl[pos.x+1][pos.y] == 'P') {

                    return false;
                } else {
                    pos.x++;
                }
                break;
            case 'A':
                if (pos.y - 1 < 0 || cl[pos.x][pos.y-1] == 'X'|| cl[pos.x][pos.y-1] == 'P') {

                    return false;
                } else {
                    pos.y--;
                }
                break;
            default:
                cerr << "Unreachable\n";
                exit(EXIT_FAILURE);
        }
    }

    return true;
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

        cl = new char*[height];
        for(int j = 0 ; j < height ; ++j)
        {
            cl[j] = new char[width];
        }

        for(int j = 0 ; j < height ; ++j)
        {
            for(int k = 0 ; k < width ; ++k)
            {
                in >> mat[j][k];
            }
        }


        in >> path;


       /* cout<<width<<" "<<height<<endl;
        for(int j = 0 ; j < height ; ++j)
        {
            for(int k = 0 ; k < width ; ++k)
                cout<<mat[j][k]<<" ";

            cout<<endl;
        }
        cout<<path;

        cout<<endl; */



        bool exista = true;
        for(int j = 0; j < height; j++)
        {
            for (int k = 0; k < width; k++)
            {
                for (int p = 0; p < height; p++)
                {
                    for (int t = 0; t < width; t++)
                    {
                        cl[p][t] = mat[p][t];
                    }
                }
                if(cl[j][k] != 'X')
                {
                    if(giveRoad(j, k, width, height))
                    {
                        bool altu = true;
                        cl[height-1][width-1] = 'P';

                        for(int p = 0 ; p < height ; p++)
                        {
                            for(int t = 0 ; t < width ; t++)
                            {
                                if(cl[p][t] == '.')
                                    altu = false;
                            }
                        }

                        if(altu)
                        {
                            out<<"VALID"<<endl;
                            cout<<"VALID"<<endl;
                            j = height-1;
                            k = width-1;
                            exista = false;
                        }
                    }
                }
            }
        }
        if(exista){
            cout<<"INVALID"<<endl;
            out<<"INVALID"<<endl;
        }
        for (int j = 0; j < height; ++j) {
            delete[] mat[j];
            delete[] cl[j];
        }
        delete[] mat;
        delete[] cl;

    }
}
