#include <bits/stdc++.h>
using namespace std;
#define int long long
#define db double
#define pid pair <int , double>
#define pdi pair <db , int>
#define pb emplace_back
#define fi first
#define se second

const int N = 1e3 + 5;

int n , s , t , vis[N];

db x[N] , y[N] , r[N];
db xs , ys , xt , yt , dis[N];

vector <pid> G[N];

priority_queue <pdi> q;

db Dis (int i , int j) {
    db d = sqrt ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    d -= r[i] + r[j]; d = max (d , 0.0); return d;
}

void dijkstra () {
    memset (dis , 127 , sizeof dis); dis[0] = 0; q.push ({0 , 0});
    while (!q.empty ()) {
        int u = q.top().se; q.pop(); if (vis[u]) continue; vis[u] = 1;
        for (auto X : G[u]) {
            if (dis[X.fi] > dis[u] + X.se) {
                dis[X.fi] = dis[u] + X.se;
                q.push ({-dis[X.fi] , X.fi});
            } 
        } 
    }
}

signed main() {
    cin >> x[0] >> y[0] >> xt >> yt >> n;
    s = 0; t = n + 1;  x[n + 1] = xt; y[n + 1] = yt;
    for (int i = 1;i <= n;i ++) cin >> x[i] >> y[i] >> r[i];
    for (int i = 0;i <= n + 1;i ++) for (int j = 0;j <= n + 1;j ++) if (i != j)
        G[i].pb ((pid){j , Dis (i , j)});
    dijkstra ();
    cout << fixed << setprecision(10) << dis[t];
    return 0;
}