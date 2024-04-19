#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>

using namespace std;

ifstream in ("level3_example.in");
ofstream out ("output3");

bool isValidPath(const vector<string>& lawn, const string& path) {
    int x = 0, y = 0;
    for (char move : path) {
        switch(move) {
            case 'S': y++; break;
            case 'W': y--; break;
            case 'A': x--; break;
            case 'D': x++; break;
        }
        // Check if out of bounds or hit the tree
        if (x < 0 || x >= lawn.size() || y < 0 || y >= lawn[0].size() || lawn[x][y] == 'X')
            return false;
    }
    // Check if reached the last cell without hitting the tree
    return x == lawn.size() - 1 && y == lawn[0].size() - 1;
}

int main() {
    int N;
    in >> N;
    
    for (int i = 0; i < N; ++i) {
        int width, height;
        in >> width >> height;
        
        vector<string> lawn(height);
        for (int j = 0; j < height; ++j)
            in >> lawn[j];
        
        string path;
        in >> path;
        
        if (isValidPath(lawn, path))
            cout << "VALID" << endl;
        else
            cout << "INVALID" << endl;
    }
    
    return 0;
}
