#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5005;
const int mod = 1e9 + 7;

int n , k , f[N][N];

signed main() {
	cin >> n >> k;
	for (int i = 2;i <= n;i ++) f[1][i] = 1;
	for (int i = 2;i < k;i ++) {
		f[i][n - i + 2] = f[i - 1][n - i + 2];
		for (int j = n - i + 1;j >= 2;j --)
			f[i][j] = (f[i - 1][j] + f[i][j + 1]) % mod;
	} int ans = 0;
	for (int i = 2;i <= n - k + 2;i ++)
		ans += f[k - 1][i];
	ans %= mod;
	if (k == 1) ans = 1;
	for (int i = 1;i < n - k;i ++) ans = ans * 2 % mod;
	cout << ans << '\n';
	return 0;
}