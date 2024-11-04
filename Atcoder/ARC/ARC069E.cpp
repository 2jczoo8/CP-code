#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;

int a[N] , n , b[N] , s[N];

signed main() {
    cin >> n; for (int i = 1;i <= n;i ++) cin >> a[i] , b[i] = a[i];
    sort (b + 1 , b + 1 + n); for (int i = 1;i <= n;i ++) s[i] = s[i - 1] + b[i];
    int nw = 0;
    for (int i = 1;i <= n;i ++) {
        if (a[i] <= nw) cout << 0 << '\n';
        else {
            int l = 1 , r = n , res = 0;
            while (l <= r) {
                int mid = l + r >> 1;
                if (b[mid] >= a[i]) res = mid , r = mid - 1;
                else l = mid + 1;
            }
            int cnt = n - res + 1 , sum = 0;
            l = 1; r = n; int st;
            while (l <= r) {
                int mid = l + r >> 1;
                if (b[mid] > nw) st = mid , r = mid - 1;
                else l = mid + 1;
            }
            sum = s[res - 1] - s[st - 1] - nw * (res - st);
            cout << cnt * (a[i] - nw) + sum << '\n';
            nw = a[i];
        } 
    }
    return 0;
}