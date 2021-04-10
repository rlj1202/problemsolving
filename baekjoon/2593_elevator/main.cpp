#include <cstdio>

using namespace std;

int xs[102];
int ys[102];

int visited[100005];
int ele[100005];
int queue[100005];
int l, r;

bool can_take_elevator(int floor, int elevator) {
    if (xs[elevator] > floor) return false;

    return (floor - xs[elevator]) % ys[elevator] == 0;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int m = 1; m <= M; m++) {
        scanf("%d %d", xs + m, ys + m);
    }
    int A, B;
    scanf("%d %d", &A, &B);

    visited[A] = -1;
    queue[r++] = A;

    while (r - l) {
        int cur = queue[l++];

        if (cur == B) {
            break;
        }

        for (int m = 1; m <= M; m++) {
            if (can_take_elevator(cur, m)) {
                for (int next = xs[m]; next <= N; next += ys[m]) {
                    if (visited[next] == 0) {
                        visited[next] = cur;
                        ele[next] = m;
                        queue[r++] = next;
                    }
                }
            }
        }
    }

    if (visited[B] == 0) {
        printf("-1\n");
        return 0;
    }

    int count = 0;

    r = 0;

    int cur = visited[B];
    int elevator = ele[B];
    while (cur != -1) {
        count++;
        queue[r++] = elevator;

        elevator = ele[cur];
        cur = visited[cur];
    }

    printf("%d\n", count);
    while (r--) {
        printf("%d\n", queue[r]);
    }

    return 0;
}