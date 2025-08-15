#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5 + 5;

int n , a[N] , b[N] , m , ans;

bool check (int mid) {
	int mx = 0;
	for (int i = 1;i <= mid;i ++) mx = max (mx , (a[i] + b[-i + mid + 1]) % m);
	for (int i = mid + 1;i <= n;i ++) {
		int tmp = a[i] + b[n - i + mid + 1];
		if (tmp < m) return 0;
		mx = max (mx , tmp - m);
	}
	ans = min (ans , mx); return 1;
}

void solve () {
	cin >> n >> m; ans = 1e10;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	for (int i = 1;i <= n;i ++) cin >> b[i];
	sort (a + 1 , a + 1 + n);
	sort (b + 1 , b + 1 + n);
	int l = 0 , r = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check (mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << '\n';
}

signed main () {
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	int T; cin >> T; while (T --) solve (); return 0;
}