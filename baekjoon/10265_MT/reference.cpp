#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define MAX 1001
using namespace std;

int n, k;
int id, dfsn[MAX], SN, sn[MAX], sPeople[MAX];
int CN = 0, cn[MAX] = {0}; //컴포넌트 개수
int cmn[MAX], cmx[MAX];    //컴포먼트 별 최소/최대
bool finished[MAX];
vector<int> adj[MAX];
stack<int> s;

int makeSCC(int curr) {
    dfsn[curr] = ++id;
    s.push(curr);

    int parent = dfsn[curr];
    for (int next : adj[curr]) {
        if (dfsn[next] == 0)
            parent = min(parent, makeSCC(next));
        else if (!finished[next])
            parent = min(parent, dfsn[next]);
    }
    if (parent == dfsn[curr]) {
        while (1) {
            int t = s.top();
            s.pop();
            finished[t] = true;
            sn[t] = SN;
            sPeople[SN]++;
            if (t == curr)
                break;
        }
        SN++;
    }
    return parent;
}

int dp[MAX][MAX];

int knapsack(int pos, int val) {
    if (pos > CN)
        return 0;

    int &ret = dp[pos][val];
    if (ret != -1)
        return ret;

    ret = knapsack(pos + 1, val);

    if (val >= cmn[pos]) {
        for (int i = cmn[pos]; i <= cmx[pos]; i++) {
            if (i > val)
                break;
            ret = max(ret, knapsack(pos + 1, val - i) + i);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0, u; i < n; i++) {
        cin >> u;
        adj[u - 1].push_back(i);
    }

    for (int i = 0; i < n; i++)
        if (dfsn[i] == 0)
            makeSCC(i);

    vector<int> sAdj[MAX];
    int sInd[MAX] = {0};
    for (int i = 0; i < n; i++) {
        int si = sn[i];
        for (int j : adj[i]) {
            int sj = sn[j];
            if (si == sj)
                continue;
            sAdj[si].push_back(sj);
            sInd[sj]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < SN; i++)
        if (sInd[i] == 0) {
            q.push(i);
            cn[i] = ++CN;
            cmx[CN] = cmn[CN] = sPeople[i];
        }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : sAdj[curr]) {
            cn[next] = cn[curr];
            cmx[cn[next]] += sPeople[next];
            if (--sInd[next] == 0)
                q.push(next);
        }
    }

    fill(&dp[0][0], &dp[MAX - 1][MAX], -1);
    cout << knapsack(1, k) << '\n';
}