#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair <int , int>
#define fi first
#define se second
#define mkp make_pair
#define pb emplace_back

const int N = 2005;
const int mod = 1e9 + 7;

int n , m , a[N];

int qpow (int a , int n) {
	int res = 1; for (;n;n >>= 1) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
	} return res;
}

int C (int m , int n) {
	int res = 1;
	for (int i = m;i > m - n;i --) res = res * i % mod;
	for (int i = 2;i <= n;i ++) res = res * qpow (i , mod - 2) % mod;
	return res;
}

void solve () {
	cin >> n >> m; int sum = n;
	for (int i = 1;i <= n;i ++) cin >> a[i] , sum += a[i];
	cout << C (n + m , sum);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T; T = 1; while (T --) solve ();
	return 0;
}