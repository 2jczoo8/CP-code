#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define pii pair <int , int>
#define fi first
#define se second 

const int N = 1e5 + 5;

int n , k , a[N] , vis[N];

priority_queue <pii> q;

vector <int> G[N];

signed main() {
    cin >> n;
    for (int i = 1;i < n;i ++) {
        int u , v; cin >> u >> v;
        G[u].pb (v); G[v].pb (u);
    }
    cin >> k;
    for (int i = 1;i <= k;i ++) {
        int u , x; cin >> u >> x;
        a[u] = x; q.push ({-x , u});
        vis[u] = 1;
    }
    while (!q.empty ()) {
        int u = q.top().se; q.pop();
        for (int v : G[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                a[v] = a[u] + 1;
                q.push ({-a[v] , v});
            }
        }
    }
    for (int i = 1;i <= n;i ++) for (int u : G[i]) if (abs (a[i] - a[u]) != 1) return puts("No") , 0;
    cout << "Yes\n"; for (int i = 1;i <= n;i ++) cout << a[i] << '\n'; 
    return 0;
}