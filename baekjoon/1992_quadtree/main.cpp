#include <cstdio>
#include <string>

using namespace std;

struct data {
    string str;
    int type;
};

int grid[64][64];

data compress(int offset_r, int offset_c, int size) {
    if (size == 1) {
        int type = grid[offset_r][offset_c];
        return {string(1, '0' + type), type};
    }

    data d[4];
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 2; c++) {
            int new_size = size / 2;
            d[c + r * 2] = compress(
                offset_r + new_size * r,
                offset_c + new_size * c,
                new_size);
        }
    }

    int prevType = d[0].type;
    bool identical = true;
    for (int i = 1; i < 4; i++) {
        if (prevType != d[i].type) {
            identical = false;
            break;
        }
    }

    if (identical && prevType != -1) {
        return {string(1, '0' + prevType), prevType};
    } else {
        string result = "";
        result.append("(");
        for (int i = 0; i < 4; i++) {
            result.append(d[i].str);
        }
        result.append(")");
        return {result, -1};
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            char bit;
            scanf(" %c", &bit);
            grid[r][c] = bit - '0';
        }
    }

    string result = compress(0, 0, N).str;
    printf("%s\n", result.c_str());

    return 0;
}