#include <iostream>
#include <cstring>

using namespace std;

char map[2003][2003];

bool recur(int left, int top, int k) {
    if (k == 1) {
        return true;
    }

    return false;
}

int main() {
    int T, K;
    cin >> T >> K;

    while (T--) {
        int a, b;
        cin >> a >> b;

        memset(map, 0, sizeof(map));
        map[a - 1][b - 1] = '@';
        recur(0, 0, K);

        int size = 1 << K;
        for (int r = 0; r < size; r++) {
            map[r][size] = '\0';
            cout << map[r] << "\n";
        }
    }

    return 0;
}
