#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in ("level2_5.in");
ofstream out ("output2_5");

pair<int, int> calculateLawnSize(const string& path) {
    int x = 0, y = 0;
    int minX = 0, maxX = 0, minY = 0, maxY = 0;

    for (char c : path) {
        switch (c) {
            case 'W':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'A':
                x--;
                break;
            case 'D':
                x++;
                break;
        }

        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }
    int width = maxX - minX + 1;
    int height = maxY - minY + 1;
    return make_pair(width, height);
}

int main() {
    int N;
    in >> N;
    vector<string> paths(N);
    for (int i = 0; i < N; ++i) {
        in >> paths[i];
    }
    for (const string& path : paths) {
        pair<int, int> lawnSize = calculateLawnSize(path);
        cout << lawnSize.first << " " << lawnSize.second << endl;
        out << lawnSize.first << " " << lawnSize.second << endl;
    }
    return 0;
}
