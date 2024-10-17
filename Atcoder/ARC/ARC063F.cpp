#include <bits/stdc++.h>
using namespace std;
#define pii pair <int , int>
#define fi first
#define se second

const int N = 3e5 + 5;

int ans , w , h , n , tr[N << 2] , tag[N << 2];

stack <pii> up , dw;

void push_up (int p) {
    tr[p] = max (tr[p << 1] , tr[p << 1 | 1]);
}

void push_down (int p) {
    if (tag[p]) {
        tr[p << 1] += tag[p]; tag[p << 1 | 1] += tag[p];
        tag[p << 1] += tag[p]; tr[p << 1 | 1] += tag[p];
        tag[p] = 0;
    }
}

void modify (int p , int l , int r , int tal , int tar , int det) {
    if (tal > tar) return ;
    // cerr << p << ' ' << l << ' ' << r << ' ' << tal << ' ' << tar << ' ' << tr[p] << '\n';
    if (l >= tal && r <= tar) {
        tr[p] += det; tag[p] += det;
        return ;
    }
    int mid = l + r >> 1; push_down (p);
    if (mid >= tal) modify (p << 1 , l , mid , tal , tar , det);
    if (mid < tar) modify (p << 1 | 1 , mid + 1 , r , tal , tar , det);
    push_up (p);
}

pii a[N];

void solve () {
    sort (a + 1 , a + 1 + n);
    for (int i = 1;i < n;i ++) {
        int r = i;
        if (a[i].se < (h >> 1)) {
            while (!up.empty() && up.top().se < a[i].se) {
                int x = up.top().fi; 
                // cerr << "query" << x << ' ' << r << ' ' << a[i].se - dw.top().se << '\n';
                // cerr << "see " << x << ' ' << r << ' ' << a[i].se - dw.top().se << '\n';
                modify (1 , 1 , n , x , r - 1 , up.top().se - a[i].se);
                up.pop(); r = x;
            }
            up.push ({r , a[i].se});
        }
        else {
            while (!dw.empty() && dw.top().se > a[i].se) {
                int x = dw.top().fi;
                modify (1 , 1 , n , x , r - 1 , a[i].se - dw.top().se);
                dw.pop(); r = x;
            } dw.push ({r , a[i].se});
        }
        up.push ({i , 0}); dw.push ({i , h});
        modify (1 , 1 , n , i , i , h - a[i].fi);
        ans = max (ans , tr[1] + a[i + 1].fi);
        // cerr << i << ' ' << a[i].fi << ' ' << a[i].se << ' ' << tr[1] << '\n';
    }
    while (!up.empty()) up.pop(); while (!dw.empty()) dw.pop();
    for (int i = 1;i <= n * 4;i ++) tr[i] = tag[i] = 0;
}

signed main() {
    cin >> w >> h >> n;
    for (int i = 1;i <= n;i ++) cin >> a[i].fi >> a[i].se;
    a[++ n] = {0 , 0}; a[++ n] = {w , h};
    solve (); swap (w , h);
    for (int i = 1;i <= n;i ++) swap (a[i].fi , a[i].se);
    solve (); cout << ans * 2;
    return 0;
}