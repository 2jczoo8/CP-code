#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back

const int N = 1e6 + 5;

int n , a[N] , b[N] , d[N] , p1 , p2 , x[N];
int cnt;

vector <int> G[N];

void dfs (int u , int fa) {
    d[u] = d[fa] ^ 1;
    for (int v : G[u]) if (v != fa) dfs (v , u);
}

void dfs1 (int u , int fa) {
    x[++ cnt] = u;
    for (int v : G[u]) if (v != fa) dfs1 (v , u);
}

void solve () {
    cin >> n; int mx = 0; p1 = 0; p2 = 0; cnt = 0;
    for (int i = 1;i <= n;i ++) G[i].clear();
    for (int i = 1;i <= n;i ++) {
        char c; cin >> c;
        a[i] = c - '0';
    }
    for (int i = 1;i <= n;i ++) {
        char c; cin >> c;
        b[i] = c - '0';
    }
    for (int i = 1;i < n;i ++) {
        int u , v; cin >> u >> v;
        G[u].pb (v); G[v].pb (u);
    }
    int h = 1;
    for (int i = 2;i <= n;i ++) h &= (a[i] == a[i - 1]);
    if (h) {
        for (int i = 1;i <= n;i ++) h &= (b[i] == a[1]);
        if (h) cout << "TAK\n";
        else cout << "NIE\n";
        return ;
    }
    for (int i = 1;i <= n;i ++) mx = max (mx , (int) G[i].size());
    if (mx <= 2) {
        int st = 1;
        for (int i = 1;i <= n;i ++) if (G[i].size() == 1) st = i;
        dfs1 (st , 0);
        for (int i = 1;i < n;i ++) {
            if (b[x[i]] != b[x[i + 1]]) p1 ++;
            if (a[x[i]] != a[x[i + 1]]) p2 ++;
        }
        if (p1 < p2) cout << "TAK\n";
        else if (p1 == p2 && b[st] == a[st]) cout << "TAK\n";
        else cout << "NIE\n";
    }
    else {
        dfs (1 , 0);
        int f = 1;
        for (int i = 1;i <= n;i ++) f &= (a[i] == b[i]);
        if (f) {
            cout << "TAK\n";
            return ;
        }
        f = 1;
        for (int i = 2;i <= n;i ++) f &= ((d[i - 1] ^ b[i - 1]) == (d[i] ^ b[i]));
        if (f) cout << "NIE\n";
        else cout << "TAK\n";
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T; while (T --) solve ();
    return 0;
}