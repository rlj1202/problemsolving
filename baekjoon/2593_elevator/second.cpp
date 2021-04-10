#include <cstdio>
#include <vector>

using namespace std;

int xs[102];
int ys[102];

vector<int> elevators[100005];

int visited[102];
int queue[102];
int l, r;

int stack[102];
int top;

bool can_take_elevator(int fl, int el) {
    if (xs[el] > fl) return false;
    return (fl - xs[el]) % ys[el] == 0;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int m = 1; m <= M; m++) {
        scanf("%d %d", xs + m, ys + m);
    }
    int A, B;
    scanf("%d %d", &A, &B);

    for (int m = 1; m <= M; m++) {
        for (int f = xs[m]; f <= N; f += ys[m]) {
            elevators[f].push_back(m);
        }
    }

    for (int m = 1; m <= M; m++) {
        if (can_take_elevator(A, m)) {
            visited[m] = -1;
            queue[r++] = m;
        }
    }

    while (r - l) {
        int curEl = queue[l++];

        if (can_take_elevator(B, curEl)) {
            int tmp = curEl;
            while (tmp != -1) {
                stack[top++] = tmp;
                tmp = visited[tmp];
            }

            break;
        }

        for (int f = xs[curEl]; f <= N; f += ys[curEl]) {
            for (int nextEl : elevators[f]) {
               if (visited[nextEl] != 0) continue;

               visited[nextEl] = curEl;
               queue[r++] = nextEl;
            }
        }
    }

    if (!top) {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", top);
    for (int i = 0; i < top; i++) {
        printf("%d\n", stack[top - i - 1]);
    }

    return 0;
}