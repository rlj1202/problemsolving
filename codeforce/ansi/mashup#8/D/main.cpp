#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct segment {
    int id;
    int pos;
    bool open;

    bool operator<(const segment& o) const {
        if (pos == o.pos) return open > o.open;
        return pos < o.pos;
    }
};

vector<segment> segments;
int open_pos[200005];
vector<int> closeds;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        segments.clear();
        closeds.clear();

        segments.reserve(N*2);
        closeds.reserve(N);

        for (int n = 0; n < N; n++) {
            int l, r;
            scanf("%d %d", &l, &r);

            segments.push_back({ n, l, true });
            segments.push_back({ n, r, false });

            open_pos[n] = l;
        }
        sort(segments.begin(), segments.end());

        int max_overlaps = 0;

        int opens = 0;
        for (segment seg : segments) {
            if (seg.open) {
                opens++;
            } else {
                opens--;

                int overlaps =
                    opens +
                    closeds.end() - lower_bound(closeds.begin(), closeds.end(), open_pos[seg.id]);
                max_overlaps = max(max_overlaps, overlaps);

                closeds.push_back(seg.pos);
            }
        }

        printf("%d\n", N - max_overlaps - 1);
    }

    return 0;
}
