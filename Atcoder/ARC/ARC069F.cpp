#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair <int , int>
#define fi first
#define se second
#define mkp make_pair
#define pb emplace_back

const int N = 5e5 + 5;
const int inf = 1e9 + 7;

int n , cnt , id[N] , dfn[N] , low[N];
int flag[N] , tim , in[N] , idx , nid[N];

pii a[N];

vector <int> e[N];

stack <int> s;

void add (int p , int l , int r , int tal , int tar , int pos) {
	if (tal > tar) return ;
    if (l >= tal && r <= tar) return e[pos].pb (id[p]) , void();
    int mid = l + r >> 1;
    if (mid >= tal) add (p << 1 , l , mid , tal , tar , pos);
    if (mid < tar) add (p << 1 | 1 , mid + 1 , r , tal , tar , pos);
}

void dfs (int u) {
//	cout << u << '\n';
//	if (u == 11) cout << e[u].size() << '\n';
    dfn[u] = low[u] = ++ tim; flag[u] = 1; s.push (u);
    for (int v : e[u]) {
        if (!dfn[v]) {
            dfs (v);
            low[u] = min(low[u] , low[v]);
        } else if (flag[v]) low[u] = min(dfn[v] , low[u]);
    }
    if (dfn[u] == low[u]) {
        int k; ++ idx;
        do {
            k = s.top(); s.pop();
            flag[k] = 0; in[k] = idx;
        } while (k != u);
    }
}

void build (int p , int l , int r) {
    id[p] = ++ cnt; 
    if (l == r) {
    	int x = a[l].se; if (x > n) x -= n;
    	else x += n;
    	return e[id[p]].pb (nid[x]) , void();
	} 
    int mid = l + r >> 1;
    build (p << 1 , l , mid);
    build (p << 1 | 1 , mid + 1 , r);
    e[id[p]].pb (id[p << 1]);
    e[id[p]].pb (id[p << 1 | 1]);
}

bool check (int dis) {
    for (int i = 1;i <= cnt;i ++) e[i].clear();
    while (!s.empty()) s.pop(); tim = 0; cnt = 2 * n;
    build (1 , 1 , 2 * n); idx = 0;
    for (int i = 1;i <= cnt;i ++) dfn[i] = low[i] = flag[i] = 0;
    for (int i = 1;i <= 2 * n;i ++) {
        int l = upper_bound (a + 1 , a + 1 + 2 * n , (pii) {a[i].fi - dis , inf}) - a;
        int r = lower_bound (a + 1 , a + 1 + 2 * n , (pii) {a[i].fi + dis , 0}) - a - 1;
        add (1 , 1 , 2 * n , l , i - 1 , i); add (1 , 1 , 2 * n , i + 1 , r , i);
    } for (int i = 1;i <= 2 * n;i ++) if (!dfn[i]) dfs (i);
    for (int i = 1;i <= n;i ++) if (in[i] == in[nid[a[i].se > n ? a[i].se - n : a[i].se + n]]) return 0;
    return 1; 
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i ++) {
        int x , y; cin >> x >> y;
        a[++ cnt] = {x , i};
        a[++ cnt] = {y , i + n};
    }
    sort (a + 1 , a + 1 + cnt);
    for (int i = 1;i <= 2 * n;i ++) nid[a[i].se] = i;
    int l = 0 , r = inf , ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (!check (mid)) r = mid - 1;
        else l = mid + 1 , ans = mid;
    } cout << ans;
    return 0;
}