#include <cstdio>
#include <algorithm>

using namespace std;

int dates[1003];

int main() {
    int birthday;
    scanf("%d", &birthday);
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%d", dates + n);
    }
    sort(dates, dates + N);

    int max_rythm = 0;
    int answer = 0;

    for (int n = 0; n < N; n++) {
        int A = birthday;
        int B = dates[n];

        int date = 0;
        for (int i = 0; i < 2; i++) {
            int delta = (A % 10) - (B % 10);
            date += delta * delta;
            A /= 10;
            B /= 10;
        }
        int month = 0;
        for (int i = 0; i < 2; i++) {
            int delta = (A % 10) - (B % 10);
            month += delta * delta;
            A /= 10;
            B /= 10;
        }
        int year = 0;
        for (int i = 0; i < 4; i++) {
            int delta = (A % 10) - (B % 10);
            year += delta * delta;
            A /= 10;
            B /= 10;
        }

        int rythm = date * month * year;

        if (max_rythm < rythm) {
            max_rythm = rythm;
            answer = dates[n];
        }
    }

    printf("%d\n", answer);

    return 0;
}
