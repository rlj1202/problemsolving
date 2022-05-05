#include <cstdio>

using namespace std;

int prev[2003];
int prevfront;
int prevrear;

int next[2003];
int nextlen;

int cap[2003];

int curpage;
int curcache;

int comp(int* arr, int len) {
    if (!len) return 0;

    int newlen = 1;

    for (int i = 1; i < len; i++) {
        if (arr[i - 1] != arr[i]) {
            curcache -= cap[arr[newlen]];
            curcache += cap[arr[i]];

            arr[newlen++] = arr[i];
        }
    }

    for (int i = newlen; i < len; i++) {
        curcache -= cap[arr[i]];
    }

    return newlen;
}

int main() {
    int N, Q, C;
    scanf("%d %d %d", &N, &Q, &C);
    for (int n = 1; n <= N; n++) {
        scanf("%d", cap + n);
    }
    while (Q--) {
        char cmd;
        scanf(" %c", &cmd);

        if (cmd == 'B') {
            if (prevrear - prevfront) {
                next[nextlen++] = curpage;
                curpage = prev[--prevrear];
            }
        } else if (cmd == 'F') {
            if (nextlen) {
                prev[prevrear++] = curpage;
                curpage = next[--nextlen];
            }
        } else if (cmd == 'A') {
            int page;
            scanf("%d", &page);

            if (curpage) prev[prevrear++] = curpage;

            curpage = page;
            curcache += cap[page];

            while (nextlen) {
                curcache -= cap[next[--nextlen]];
            }

            while (curcache > C && prevfront < prevrear) {
                curcache -= cap[prev[prevfront++]];
            }
        } else if (cmd == 'C') {
            prevrear = prevfront + comp(prev + prevfront, prevrear - prevfront);
        }
    }

    printf("%d\n", curpage);
    for (int i = prevrear - 1; i >= prevfront; i--) {
        printf("%d ", prev[i]);
    }
    if (!(prevrear - prevfront)) printf("-1");
    printf("\n");
    for (int i = nextlen - 1; i >= 0; i--) {
        printf("%d ", next[i]);
    }
    if (!nextlen) printf("-1");
    printf("\n");

    return 0;
}
