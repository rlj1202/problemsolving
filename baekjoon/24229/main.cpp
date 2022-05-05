#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct segment {
    int l, r;

    bool operator<(const segment& o) const {
        if (l == o.l) return r > o.r;
        return l < o.l;
    }
};

segment segments[200005];
vector<segment> combined;

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        int l, r;
        scanf("%d %d", &l, &r);

        segments[n] = { l, r };
    }
    sort(segments, segments + N);

    segment cur = { 0, 0 };
    for (int n = 0; n < N; n++) {
        segment next = segments[n];
        if (next.l <= cur.r && next.r >= cur.l) {
            cur.l = min(cur.l, next.l);
            cur.r = max(cur.r, next.r);
        } else {
            combined.push_back(cur);

            cur = next;
        }
    }
    combined.push_back(cur);

    int result = 0;

    int max_jump = 0;
    for (int i = 0; i < combined.size(); i++) {
        segment cur = combined[i];

        if (cur.l <= max_jump) {
            int jump = cur.r + (cur.r - cur.l);

            if (max_jump < jump) {
                max_jump = jump;
            }

            result = cur.r;
        } else {
            break;
        }
    }

    printf("%d\n", result);

    return 0;
}
