#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e6 + 5;

struct node {
	int knd , l , r , x;
}a[N];

int n , m , tr[N] , ans[N];

bool cmp (node a , node b) {
	if (a.r != b.r) return a.r < b.r;
	return a.knd > b.knd;
}

void mdf (int x) {
	for (;x;x -= x & (-x)) tr[x] ++;
}

int qry (int x) {
	int res = 0;
	for (;x <= m;x += x & (-x)) res += tr[x];
	return res;
}

signed main() {
	cin >> n >> m; int tt = 0;
	for (int i = 1;i <= m;i ++) {
		for (int j = i;j <= m + i;j += i) {
			a[++ tt] = (node) {1 , 0 , j , i};
		}
	}
	for (int i = 1;i <= n;i ++) {
		int l , r; cin >> l >> r;
		a[++ tt] = (node) {0 , l , r , 0};
	}
	sort (a + 1 , a + 1 + tt , cmp);
	for (int i = 1;i <= tt;i ++) {
		if (a[i].knd) ans[a[i].x] += qry (a[i].r - a[i].x + 1);
		else mdf (a[i].l);
	}
	for (int i = 1;i <= m;i ++) cout << n - ans[i] << '\n';
	return 0;
}