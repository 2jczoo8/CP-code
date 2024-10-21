#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3005;
const int mod = 1e9 + 7;

int dp[N][N] , s[N] , n , m , l[N] , r[N] , R[N];

signed main() {
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) {
		char x; cin >> x; R[i] = i;
		s[i] = s[i - 1] + x - '0';
	}
	for (int i = 1;i <= m;i ++) {
		cin >> l[i] >> r[i];
		for (int j = l[i];j <= r[i];j ++) R[j] = max (R[j] , r[i]);
	} dp[0][0] = 1;
	for (int i = 1;i <= n;i ++) {
		int up = min (i , s[R[i]]);
		int dw = max (0ll , s[R[i]] - (R[i] - i));
		for (int j = dw;j <= up;j ++)
			dp[i][j] = (dp[i - 1][j - 1] * (j > 0) + dp[i - 1][j]) % mod;
	} cout << dp[n][s[n]];
	return 0;
}