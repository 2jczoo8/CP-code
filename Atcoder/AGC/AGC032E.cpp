#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5;

int a[N] , n , mod , ans = 1e18 + 7 , m;

bool check (int mid) {
    int mx = 0;
    for (int i = 1;i <= mid;i ++) {
        int tmp = a[i] + a[mid * 2 - i + 1];
        mx = max (mx , tmp % mod);
    } 
    for (int i = 1;i <= n - mid;i ++) {
        int tmp = a[i + 2 * mid] + a[m - i + 1];
        if (tmp < mod) return 0;
        mx = max (mx , tmp - mod);
    }
    ans = min (ans , mx);
    return 1;
}

signed main () {
    cin >> n >> mod; m = 2 * n;
    for (int i = 1;i <= m;i ++)  cin >> a[i];
    sort (a + 1 , a + 1 + m);
    int l = 0 , r = n; while (l <= r) {
        int mid = l + r >> 1;
        if (check (mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}