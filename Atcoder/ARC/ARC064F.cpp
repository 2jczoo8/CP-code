#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int x , d[N] , cnt[N] , n , k;

int qpow (int a , int n) {
    int res = 1; for (;n;n >>= 1) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
    } return res;
}

signed main() {
    cin >> x >> k; int ans = 0;
    for (int i = 1;i * i <= x;i ++) {
        if (x % i == 0) d[++ n] = i;
        if (i * i != x && x % i == 0) d[++ n] = x / i;
    }
    sort (d + 1 , d + 1 + n);
    for (int i = 1;i <= n;i ++) {
        cnt[i] = qpow (k , (d[i] + 1) / 2);
        for (int j = 1;j < i;j ++)
            if (d[i] % d[j] == 0) cnt[i] = (cnt[i] - cnt[j] + mod) % mod;
        if (d[i] & 1) ans = (ans + d[i] * cnt[i]) % mod;
        else ans = (ans + d[i] / 2 * cnt[i]) % mod;
    }
    cout << ans;
    return 0;
}