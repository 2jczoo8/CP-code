#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int n , m , k , f[N] , inv[N] , fac[N];

int qpow (int a , int n) {
    int res = 1; for (;n;n >>= 1) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
    } return res;
}

int C (int n , int m) {
    if (n < m || n < 0 || m < 0) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

signed main() {
    cin >> n >> m >> k;
    fac[0] = inv[0] = 1;
    for (int i = 1;i <= N - 3;i ++)
        fac[i] = fac[i - 1] * i % mod,
        inv[i] = qpow (fac[i] , mod - 2);
    f[0] = 1; int ans = 0;
    for (int i = 1;i <= N - 3;i ++)
        f[i] = (2 * f[i - 1] - C (i - 1 , i - 1 - k) - C (i - 1 , m) + 2 * mod) % mod;
    for (int i = 0;i <= m + k;i ++)
        ans = (ans + f[i] * qpow (3 , m + k - i) % mod * C (n + i - 1 , n - 1)) % mod;
    cout << ans;
    return 0;
}