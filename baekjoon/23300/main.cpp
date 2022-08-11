#include <bits/stdc++.h>

using namespace std;

deque<int> prev_pages;
deque<int> next_pages;
int cur_page = -1;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    while (Q--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'B') {
            if (!prev_pages.empty()) {
                next_pages.push_back(cur_page);
                cur_page = prev_pages.back(); prev_pages.pop_back();
            }
        } else if (cmd == 'F') {
            if (!next_pages.empty()) {
                prev_pages.push_back(cur_page);
                cur_page = next_pages.back(); next_pages.pop_back();
            }
        } else if (cmd == 'A') {
            int i;
            cin >> i;

            next_pages.clear();

            if (cur_page != -1) prev_pages.push_back(cur_page);
            cur_page = i;
        } else if (cmd == 'C') {
            deque<int> new_pages;

            while (!prev_pages.empty()) {
                int cur = prev_pages.front(); prev_pages.pop_front();

                if (new_pages.empty() || new_pages.back() != cur) {
                    new_pages.push_back(cur);
                }
            }

            prev_pages.swap(new_pages);
        }
    }

    cout << cur_page << '\n';
    if (prev_pages.empty()) cout << -1;
    while (!prev_pages.empty()) {
        cout << prev_pages.back() << ' ';
        prev_pages.pop_back();
    }
    cout << '\n';
    if (next_pages.empty()) cout << -1;
    while (!next_pages.empty()) {
        cout << next_pages.back() << ' ';
        next_pages.pop_back();
    }
    cout << '\n';

    return 0;
}
