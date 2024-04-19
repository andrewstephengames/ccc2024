#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <unordered_set>

using namespace std;

ifstream in ("level3_example.in");
ofstream out ("output3");

bool isValidPath(vector<vector<char>>& lawn, int startX, int startY, string& path) {
    int x = startX, y = startY;
    unordered_set<int> visited;
    visited.insert(startY * lawn[0].size() + startX);

    for (char dir : path) {
        if (dir == 'S') y++;
        else if (dir == 'W') x--;
        else if (dir == 'A') y--;
        else if (dir == 'D') x++;

        if (x < 0 || y < 0 || x >= lawn[0].size() || y >= lawn.size() || lawn[y][x] == 'X' || visited.count(y * lawn[0].size() + x) > 0)
            return false;

        visited.insert(y * lawn[0].size() + x);
    }

    return visited.size() == lawn.size() * lawn[0].size() - 1; // -1 for excluding the tree
}

int main() {
    int N;
    in >> N;

    for (int i = 0; i < N; ++i) {
        int width, height;
        in >> width >> height;
        vector<vector<char>> lawn(height, vector<char>(width));
        
        for (int j = 0; j < height; ++j)
            for (int k = 0; k < width; ++k)
                in >> lawn[j][k];

        bool foundValid = false;

        for (int j = 0; j < height; ++j) {
            for (int k = 0; k < width; ++k) {
                if (lawn[j][k] != 'X') {
                    for (int m = -1; m <= 1; ++m) {
                        for (int n = -1; n <= 1; ++n) {
                            int startX = k + m, startY = j + n;
                            if (startX >= 0 && startY >= 0 && startX < width && startY < height && lawn[startY][startX] != 'X') {
                                string path = "";
                                path += startX < k ? 'W' : 'E';
                                path += startY < j ? 'N' : 'S';
                                path += (abs(startX - k) + abs(startY - j)) % 2 == 0 ? 'D' : 'S';
                                if (isValidPath(lawn, startX, startY, path)) {
                                    foundValid = true;
                                    break;
                                }
                            }
                        }
                        if (foundValid) break;
                    }
                }
                if (foundValid) break;
            }
            if (foundValid) break;
        }

        if (foundValid)
            cout << "VALID" << endl;
        else
            cout << "INVALID" << endl;
    }

    return 0;
}

