#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Vec2 {
    int x, y;
};

int N;
vector<vector<char>> mat;
vector<vector<bool>> visited;
vector<char> path;

// Function to check if a cell is within the lawn and is not visited
bool isValid(int x, int y, int width, int height) {
    return x >= 0 && x < height && y >= 0 && y < width && mat[x][y] != 'X' && !visited[x][y];
}

// Function to perform depth-first search to find a valid path
bool dfs(int x, int y, int width, int height) {
    visited[x][y] = true;

    if (mat[x][y] == '.') {
        path.push_back('S');
    }

    if (path.size() == width * height) {
        return true; // Path found
    }

    Vec2 directions[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // Up, Right, Down, Left

    for (Vec2 dir : directions) {
        int nx = x + dir.x;
        int ny = y + dir.y;
        if (isValid(nx, ny, width, height)) {
            if (dfs(nx, ny, width, height)) {
                return true; // Path found
            }
        }
    }

    visited[x][y] = false;
    if (mat[x][y] == '.') {
        path.pop_back();
    }

    return false; // No valid path found from this cell
}

int main() {
    ifstream in("level4_example.in");

    in << N << endl;

    for (int testcase = 0; testcase < N; ++testcase) {
        int width, height;
        in >> width >> height;

        mat.assign(height, vector<char>(width, '.'));
        visited.assign(height, vector<bool>(width, false));

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                in >> mat[i][j];
            }
        }

        path.clear();

        // Finding a valid path starting from any free cell
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (mat[i][j] == '.') {
                    if (dfs(i, j, width, height)) {
                        for (char direction : path) {
                            cout << direction;
                        }
                        cout << endl;
                        break;
                    }
                }
            }
        }
    }


    return 0;
}

