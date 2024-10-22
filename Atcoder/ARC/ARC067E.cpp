#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 5;
const int mod = 1e9 + 7;

int n , f[N][N] , g[N][N] , C[N][N];
int a , b , c , d , inv[N];

int qpow (int a , int n) {
    int res = 1; for (;n;n >>= 1) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
    } return res;
}

signed main() {
    for (int i = 0;i < N;i ++) {
        C[i][0] = 1;
        for (int j = 1;j <= i;j ++) 
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
    int x = 1;
    for (int i = 1;i < N;i ++) {
        x = x * i % mod;
        inv[i] = qpow (x , mod - 2);
    }
    cin >> n >> a >> b >> c >> d;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j * i <= n;j ++) {
            g[i][j] = 1;
            for (int k = i * j;k;k -= i)
                g[i][j] = g[i][j] * C[k][i] % mod;
            g[i][j] = g[i][j] * inv[j] % mod;
        }
    }
    f[a - 1][0] = 1;
    for (int i = a;i <= b;i ++) {
        for (int j = 0;j <= n;j ++) {
            f[i][j] = f[i - 1][j];
            for (int k = c;j >= k * i && k <= d;k ++)
                f[i][j] = (f[i][j] + f[i - 1][j - k * i] * C[n - j + k * i][k * i] % mod * g[i][k]) % mod;
        }
    }
    cout << f[b][n];
    return 0;
}