#include <cstdio>
#include <queue>

using namespace std;

int arr[200005];
bool received[200005];

deque<int> blanks;
deque<int> q;

int main() {
    int N;
    scanf("%d", &N);

    for (int n = 1; n <= N; n++) {
        scanf("%d", arr + n);

        if (arr[n]) received[arr[n]] = true;
        if (arr[n] == 0) blanks.push_back(n);
    }

    for (int n = 1; n <= N; n++) {
        if (received[n] == false) {
            q.push_back(n);
        }
    }

    for (int n = 1; n <= N; n++) {
        if (arr[n] == 0) {
            arr[n] = q.back();
            q.pop_back();
        }
    }

    for (auto it = blanks.begin(); it != blanks.end(); it++) {
        int n = *it;

        if (n == arr[n]) {
            int m;
            if (it + 1 == blanks.end()) {
                m = *(it - 1);
            } else {
                m = *(it + 1);
            }

            int tmp = arr[n];
            arr[n] = arr[m];
            arr[m] = tmp;
        }
    }

    for (int n = 1; n <= N; n++) {
        printf("%d ", arr[n]);
    }
    printf("\n");

    return 0;
}
