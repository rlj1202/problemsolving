#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX_BLOCKS = 5;

int arr[10004];

struct block { int start, end; };

block blocks[MAX_BLOCKS];
int top;

void swap(block *arr, int i, int j) {
    block tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void flip(block *arr, int i, int j) {
    int range = j - i;

    if (range == 1) {
        int tmp = arr[i].start;
        arr[i].start = arr[i].end;
        arr[i].end = tmp;
    } else {
        for (int k = 0; k < (range + 1) / 2; k++) {
            int l = i + k;
            int r = j - k - 1;
            swap(arr, l, r);
            flip(arr, l, l + 1);
            if (l != r) flip(arr, r, r + 1);
        }
    }
}

int find_index(block *arr, int i) {
    int result = 0;

    for (int j = 0; j < i; j++) {
        result += abs(arr[j].end - arr[j].start) + 1;
    }

    return result;
}

bool is_valid(block *arr, int len) {
    if (len == 1) return arr->start < arr->end;

    for (int i = 0; i < len - 1; i++) {
        if ((arr[i].start > arr[i].end) ||
            (arr[i].end + 1 != arr[i + 1].start)) {
            return false;
        }
    }
    return true;
}

int main() {
    // [5, 1e4]
    int N;
    scanf("%d", &N);
    for (int n = 1; n <= N; n++) {
        // [1, N]
        scanf("%d", arr + n);
    }
    arr[N + 1] = 0x3f3f3f3f;

    int start = 1;
    bool inc = arr[1] < arr[2];
    for (int n = 2; n <= N + 1; n++) {
        if (arr[n] != arr[n - 1] + (inc ? 1 : -1)) {
            blocks[top++] = {arr[start], arr[n - 1]};

            start = n;
            inc = arr[n] < arr[n + 1];
        }
    }

    // for (int i = 0; i < top; i++) printf("(%d %d) ", blocks[i].start, blocks[i].end); printf("\n");

    if (is_valid(blocks, top)) {
        printf("1 1\n");
        printf("2 2\n");
        return 0;
    }

    for (int i = 1; i < top + 1; i++) {
        for (int j = 0; j < i; j++) {
            block flip_once[MAX_BLOCKS];
            memcpy(flip_once, blocks, sizeof(blocks));
            flip(flip_once, j, i);

            if (is_valid(flip_once, top)) {
                printf("1 1\n");
                printf("%d %d\n", find_index(blocks, j) + 1, find_index(blocks, i));
                return 0;
            }

            // for (int i = 0; i < top; i++) printf("(%d %d) ", flip_once[i].start, flip_once[i].end); printf("\n");

            for (int m = 1; m < top + 1; m++) {
                for (int n = 0; n < m; n++) {
                    block flip_twice[MAX_BLOCKS];
                    memcpy(flip_twice, flip_once, sizeof(blocks));
                    flip(flip_twice, n, m);

                    // for (int i = 0; i < top; i++) printf("(%d %d) ", flip_once[i].start, flip_once[i].end); printf("\n");
                    // for (int i = 0; i < top; i++) printf("(%d %d) ", flip_twice[i].start, flip_twice[i].end); printf("\n");
                    // printf("\n");

                    if (is_valid(flip_twice, top)) {
                        // for (int i = 0; i < top; i++) printf("(%d %d) ", flip_once[i].start, flip_once[i].end); printf("\n");
                        // for (int i = 0; i < top; i++) printf("(%d %d) ", flip_twice[i].start, flip_twice[i].end); printf("\n");

                        printf("%d %d\n", find_index(blocks, j) + 1, find_index(blocks, i));
                        printf("%d %d\n", find_index(flip_once, n) + 1, find_index(flip_once, m));
                        return 0;
                    }

                }
            }
        }
    }

    return 0;
}