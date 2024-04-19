#include <fstream>
#include <iostream>

using namespace std;

ifstream in ("level1_example.in");
ofstream out ("output");

int f[128];

int main (void) {
    int N;
    string path;
    for (int i = 0; i < N; ++i) {
        in >> path;
        for (int i = 0; i < 128; ++i) {
            f[i] = 0;
        }
        for (int j = 0; j < path.length(); ++j) {
            if (path.at(j) == 'W') {
                f['W']++;
            } else if (path.at(j) == 'A') {
                f['A']++;
            } else if (path.at(j) == 'S') {
                f['S']++;
            } else if (path.at(j) == 'D') {
                f['D']++;
            }
        }
        cout << f['W'] << " " << f['D'] << " " << f['S'] << " " << f['A'] << endl;
        out << f['W'] << " " << f['D'] << " " << f['S'] << " " << f['A'] << endl;
    }
    return 0;
}
