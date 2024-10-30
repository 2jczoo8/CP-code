#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair <int , int>
#define fi first
#define se second
#define mkp make_pair

const int N = 1e6 + 5;

int n , a[N] , ans[N] , w , vis[N] , cst;

priority_queue <pii , vector <pii> , greater <pii> > q1 , q0;

signed main () {
    cin >> n >> w; for (int i = 1;i <= n;i ++) cin >> a[i] >> a[i + n] , a[i + n] -= a[i];
    for (int i = 1;i <= n;i ++) q1.push (mkp (a[i] , i)) , q0.push (mkp (a[i] + a[i + n] , i));
    while (w --) {
        while (!q1.empty() && vis[q1.top().se]) q1.pop();
        while (!q0.empty() && vis[q0.top().se]) q0.pop();
        int p = q1.top().se; q1.pop(); 
        while (!q1.empty() && vis[q1.top().se]) q1.pop();
        if (w && !q0.empty() && a[p] + q1.top().fi >= q0.top().fi) q1.push (mkp (a[p] , p)) , p = q0.top().se , q0.pop();
        if (p <= n) q1.push (mkp (a[p + n] , p + n));
        cst += a[p]; ans[(p > n ? p - n : p)] ++; vis[p] ++;
    }
    cout << cst << '\n';
    for (int i = 1;i <= n;i ++) cout << ans[i];
    return 0;
}