#include <bits/stdc++.h>

using namespace std;

int tree[100005 * 4];
int cnt;

void push(int value) {
    // 트리에 완전이진트리 형태를 유지하면서 새로운 노드를 생성합니다.
    // 생성한 노드에 추가하고자 하는 값을 넣습니다.
    tree[++cnt] = value;

    int cur = cnt; // 추가한 노드의 인덱스부터 시작합니다.

    while (cur > 1) { // 루트를 만날 때 까지 진행합니다.
        int parent = cur / 2;

        // 이미 트리가 힙의 형태를 유지하고 있다면 반복문을 종료합니다.
        if (tree[cur] <= tree[parent]) break;

        // 현재 노드의 값과 부모 노드의 값을 바꿉니다.
        int temp = tree[parent];
        tree[parent] = tree[cur];
        tree[cur] = temp;

        // 현재 노드를 부모 노드로 바꿉니다.
        cur = parent;
    }
}

int top() {
    return tree[1];
}

void pop() {
    // 트리에서 완전이진트리 형태를 유지하면서 맨 마지막 노드를 제거한 후,
    // 트리의 루트에 집어넣습니다.
    tree[1] = tree[cnt--];

    int cur = 1; // 루트 노트부터 시작합니다.

    while (cur * 2 <= cnt) { // 자식 노드가 없을 때 까지 진행합니다.
        int left = cur * 2;
        int right = cur * 2 + 1;

        // 현재 나의 노드와 왼쪽 자식 노드, 만약 있는 경우 오른쪽 노드 중에서
        // 가장 큰 값을 가진 노드를 찾습니다.
        int biggest = cur;
        if (tree[biggest] < tree[left]) biggest = left;
        if (right <= cnt && tree[biggest] < tree[right]) biggest = right;

        // 가장 큰 노드가 자기 자신이라면, 반복문을 종료합니다.
        if (biggest == cur) break;

        // 현재 노드와 가장 큰 노드의 값을 바꿉니다.
        int temp = tree[biggest];
        tree[biggest] = tree[cur];
        tree[cur] = temp;

        // 현재 노드를 값을 바꿔치기 한 노드로 바꿉니다.
        cur = biggest;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        int x;
        cin >> x;

        if (x == 0) {
            if (cnt == 0) {
                cout << 0 << '\n';
            } else {
                cout << top() << '\n';
                pop();
            }
        } else {
            push(x);
        }
    }

    return 0;
}
