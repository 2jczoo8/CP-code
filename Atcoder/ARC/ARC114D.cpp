#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5005;
const int inf = 1e18;

int a[N] , t[N] , n , k , m , b[N] , dp[N][N * 2];

map <int , int> mp;

signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= k;i ++) cin >> t[i];
    for (int i = k + 1;i <= k + n;i ++) t[i] = a[i - k];
    k += n; memset (dp , 0x3f , sizeof dp); dp[0][0] = 0;
    sort (a + 1 , a + 1 + n); sort (t + 1 , t + 1 + k);
    for (int i = 1;i <= k;i ++) mp[t[i]] ++;
    for (int i = 1;i <= k;i ++) if (mp[t[i]] & 1) b[++ m] = t[i] , mp[t[i]] = 0;
    if (n < m) return cout << -1 , 0;
    for (int i = 1;i <= n;i ++) for (int j = 0;j <= m;j ++) {
        if (j) dp[i][j] = min(dp[i - 1][j - 1] + abs (a[i] - b[j]) , dp[i][j]);
        if (i >= 2) dp[i][j] = min(dp[i][j] , dp[i - 2][j] + a[i] - a[i - 1]);
    }
    cout << dp[n][m];
    return 0;
}