#include <cstdio>

using namespace std;

int arr[1000006];
int tmp[1000006];
int tmplen;

void swap(int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void sort(int l, int r) {
    if (r - l == 1) {
        return;
    } else if (r - l == 2) {
        if (arr[l] > arr[l + 1])
            swap(l, l + 1);
        return;
    }

    int mid = (l + r) / 2;
    sort(l, mid);
    sort(mid, r);

    int p = l;
    int q = mid;

    int tmplen = 0;
    while (p < mid || q < r) {
        if (p < mid && q < r) {
            if (arr[p] <= arr[q]) {
                tmp[tmplen++] = arr[p++];
            } else {
                tmp[tmplen++] = arr[q++];
            }
        } else if (p < mid) {
            tmp[tmplen++] = arr[p++];
        } else if (q < r) {
            tmp[tmplen++] = arr[q++];
        }
    }

    for (int i = 0; i < tmplen; i++)
        arr[l + i] = tmp[i];
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++)
        scanf("%d", arr + n);

    sort(0, N);

    for (int n = 0; n < N; n++)
        printf("%d\n", arr[n]);

    return 0;
}