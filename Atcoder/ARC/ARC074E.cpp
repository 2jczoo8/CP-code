#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5005;
const int mod = 1e9 + 7;

int L[N][5] , R[N][5] , l[N];
int r[N] , dp[N][N] , q[N][N];
int sum[N] , n , m;

void add (int &a , int b) {
	a = (a + b) % mod;
}

void solve () {
	cin >> n >> m;
	for (int i = 0;i <= n;i ++)
		for (int j = 0;j <= n;j ++) dp[i][j] = q[i][j] = 0;
	for (int i = 0;i <= n;i ++) l[i] = 1 , sum[i] = r[i] = 0;
	for (int i = 0;i <= n;i ++)
		for (int j = 0;j < 5;j ++)
			L[i][j] = 0 , R[i][j] = i;
	q[0][++ r[0]] = 0; sum[0] = dp[0][0] = 1;
	for (int i = 1;i <= m;i ++) {
		int ll , rr , x; cin >> ll >> rr >> x;
		R[rr][x + 1] = min(R[rr][x + 1] , ll - 1);
		L[rr][x] = max (L[rr][x] , ll);
		if (rr - ll + 1 < x) dp[0][0] = sum[0] = 0;
	}
	for (int i = 2;i <= n;i ++) {
		for (int j = 0;j < i - 1;j ++) {
			dp[i - 1][j] = sum[j];
			add (sum[j] , dp[i - 1][j]);
			add (sum[i - 1] , dp[i - 1][j]);
			q[i - 1][++ r[i - 1]] = j;
		}
		for (int j = 0;j < i;j ++) {
			if (j < L[i][2] || j > R[i][2]) {
				while (r[j] >= l[j]) {
					add (sum[j] , mod - dp[j][q[j][r[j]]]);
					if (j != q[j][r[j]]) add (sum[q[j][r[j]]] , mod - dp[j][q[j][r[j]]]);
					dp[j][q[j][r[j]]] = 0; r[j] --;
				}
			}
			else {
				while (l[j] <= r[j] && q[j][r[j]] > R[i][3]) {
					add (sum[j] , mod - dp[j][q[j][r[j]]]);
					if (j != q[j][r[j]]) add (sum[q[j][r[j]]] , mod - dp[j][q[j][r[j]]]);
					dp[j][q[j][r[j]]] = 0; r[j] --;
				}
				while (l[j] <= r[j] && q[j][l[j]] < L[i][3]) {
					add (sum[j] , mod - dp[j][q[j][l[j]]]);
					if (j != q[j][l[j]]) add (sum[q[j][l[j]]] , mod - dp[j][q[j][l[j]]]);
					dp[j][q[j][l[j]]] = 0; l[j] ++;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0;i <= n;i ++)
		for (int j = 0;j <= n;j ++)
			if (i + j) add (ans , 6 * dp[i][j]);
			else add (ans , 3 * dp[i][j]);
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T; T = 1; while (T --) solve ();
	return 0;
}