#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Vec2
{
    int x, y;
};

int main()
{
    ifstream in("level3_example.in");
    ofstream out("output3");

    if (!in.is_open() || !out.is_open())
    {
        cerr << "Error opening files." << endl;
        return 1;
    }

    int N;
    in >> N;

    for (int i = 0; i < N; ++i)
    {
        int w, h;
        in >> w >> h;

        const int width = w + 2;
        const int height = h + 2;

        char **mat = new char *[width];
        for (int j = 0; j < width; ++j)
        {
            mat[j] = new char[height];
        }

        // Initialize the matrix with 'X'
        for (int j = 0; j < width; ++j)
        {
            for (int k = 0; k < height; ++k)
            {
                mat[j][k] = 'X';
            }
        }

        // Read the maze
        for (int j = 1; j <= w; ++j)
        {
            for (int k = 1; k <= h; ++k)
            {
                in >> mat[j][k];
            }
        }

        string path;
        in >> path;

        Vec2 pos;
        pos.x = 1;
        pos.y = 1;

        bool exista = true;

        for (char direction : path)
        {
            switch (direction)
            {
            case 'W':
                if (mat[pos.x][pos.y - 1] == 'X' || mat[pos.x][pos.y - 1] == '0')
                {
                    out << "INVALID" << endl;
                    cout << "INVALID" << endl;
                    exista = false;
                }
                else
                {
                    pos.y--;
                }
                break;
            case 'D':
                if (mat[pos.x + 1][pos.y] == 'X' || mat[pos.x + 1][pos.y] == '0')
                {
                    out << "INVALID" << endl;
                    cout << "INVALID" << endl;
                    exista = false;
                }
                else
                {
                    pos.x++;
                }
                break;
            case 'S':
                if (mat[pos.x][pos.y + 1] == 'X' || mat[pos.x][pos.y + 1] == '0')
                {
                    out << "INVALID" << endl;
                    cout << "INVALID" << endl;
                    exista = false;
                }
                else
                {
                    pos.y++;
                }
                break;
            case 'A':
                if (mat[pos.x - 1][pos.y] == 'X' || mat[pos.x - 1][pos.y] == '0')
                {
                    cout << "INVALID" << endl;
                    out << "INVALID" << endl;
                    exista = false;
                }
                else
                {
                    pos.x--;
                }
                break;
            default:
                cerr << "Invalid direction!" << endl;
                break;
            }

            if (!exista)
                break;
        }

        if (exista) {
            cout << "VALID" << endl;
            out << "VALID" << endl;
        }

        // Deallocate memory
        for (int j = 0; j < width; ++j)
        {
            delete[] mat[j];
        }
        delete[] mat;
    }

    in.close();
    out.close();

    return 0;
}
