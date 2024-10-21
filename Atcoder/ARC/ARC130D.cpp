#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb emplace_back

const int N = 3005;
const int mod = 998244353;

int n , dp[N][N][2] , tmp[N][2];
int pre[N] , suf[N] , siz[N] , C[N][N];

vector <int> G[N];

void dfs (int u , int fa) {
    siz[u] = dp[u][1][0] = dp[u][1][1] = 1;
    for (int v : G[u]) if (v != fa) {
        dfs (v , u) ;
        for (int i = 0;i <= siz[v] + 1;i ++) pre[i] = suf[i] = 0;
        for (int i = 1;i <= siz[v];i ++) pre[i] = pre[i - 1] + dp[v][i][0] , pre[i] %= mod;
        for (int i = siz[v];i;i --) suf[i] = suf[i + 1] + dp[v][i][1] , suf[i] %= mod;
        for (int i = 1;i <= siz[u] + siz[v];i ++) tmp[i][0] = tmp[i][1] = 0;
        for (int i = 1;i <= siz[u];i ++) {
            for (int j = 0;j <= siz[v];j ++) {
                tmp[i + j][0] = (tmp[i + j][0] + C[i - 1 + j][j] * C[siz[u] - i + siz[v] - j][siz[v] - j] % mod * dp[u][i][0] % mod * suf[j + 1]) % mod;
                tmp[i + j][1] = (tmp[i + j][1] + C[i - 1 + j][j] * C[siz[u] - i + siz[v] - j][siz[v] - j] % mod * dp[u][i][1] % mod * pre[j]) % mod;
            }
        }
        for (int i = 1;i <= siz[u] + siz[v];i ++) dp[u][i][0] = tmp[i][0] , dp[u][i][1] = tmp[i][1];
        siz[u] += siz[v];
    } 
}

signed main() {
    for (int i = 0;i < N;i ++) {
        C[i][0] = 1;
        for (int j = 1;j <= i;j ++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    cin >> n; for (int i = 1;i < n;i ++) {
        int u , v; cin >> u >> v;
        G[u].pb (v); G[v].pb (u);
    } dfs (1 , 0); int ans = 0;
    for (int i = 1;i <= n;i ++) 
        ans = (ans + dp[1][i][0] + dp[1][i][1]) % mod;
    cout << ans << '\n';
    return 0;
}