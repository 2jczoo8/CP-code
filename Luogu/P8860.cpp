#include <bits/stdc++.h>
using namespace std;
#define pii pair <int , int>
#define fi first
#define se second
#define pb emplace_back
#define mkp make_pair
#define pip pair <int , pii>

const int N = 5e5 + 5;

int n , m , ans[N] , tim[N] , Q , f[N] , U[N];

vector <pii> G[N];

priority_queue <pip> q;

signed main() {
	cin >> n >> m >> Q;
	for (int i = 1;i <= m;i ++) tim[i] = Q + 1;
	for (int i = 1;i <= m;i ++) {
		int u , v; cin >> u >> v;
		U[i] = u;
		G[u].pb (mkp (v , i));
	} for (int i = 1;i <= Q;i ++) {
		int u; cin >> u;
		if (tim[u] > i) tim[u] = i , ans[i] = 1;
		else ans[i] = 0; 
	}
	q.push (mkp (0 , mkp (1 , m + 1)));
	while (!q.empty ()) {
		int u = q.top().se.fi , id = q.top().se.se;
		q.pop(); if (f[u]) continue; f[u] = id;
		for (pii x : G[u]) q.push (mkp (tim[x.se] , x));
	}
	for (int i = n;i;i = U[f[i]]) ans[tim[f[i]]] = 0;
	for (int i = 1;i <= Q;i ++) cout << ans[i] << '\n';
	return 0;
}