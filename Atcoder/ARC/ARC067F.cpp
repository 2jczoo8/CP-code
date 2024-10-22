#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5005;
const int M = 205;

int n , a[N] , b[N][M] , m;

stack <int> s[M];

struct SGT {
    int tag[N << 2] , tr[N << 2];
    void push_up (int p) {
        tr[p] = max (tr[p << 1] , tr[p << 1 | 1]);
    }
    void make_tag(int p , int det) {
        tr[p] += det; tag[p] += det;
    }
    void push_down (int p) {
        make_tag (p << 1 , tag[p]);
        make_tag (p << 1 | 1 , tag[p]);
        tag[p] = 0;
    }
    void modify (int p , int l , int r , int tal , int tar , int det) {
        if (l >= tal && r <= tar) return make_tag (p , det);
        int mid = l + r >> 1; push_down (p);
        if (mid >= tal) modify (p << 1 , l , mid , tal , tar , det);
        if (mid < tar) modify (p << 1 | 1 , mid + 1 , r , tal , tar , det);
        push_up (p);
    }
}sgt;

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m; int ans = 0;
    for (int i = 2;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) for (int j = 1;j <= m;j ++) cin >> b[i][j];
    for (int i = 1;i <= n;i ++) {
        if (i > 1) sgt.modify (1 , 1 , n , 1 , i - 1 , -a[i]);
        for (int j = 1;j <= m;j ++) {
            while (!s[j].empty() && b[i][j] > b[s[j].top()][j]) {
                int pos = s[j].top(); s[j].pop();
                int l = 0; if (!s[j].empty()) l = s[j].top();
                sgt.modify (1 , 1 , n , l + 1 , pos , b[i][j] - b[pos][j]);
            }
            s[j].push (i); sgt.modify (1 , 1 , n , i , i , b[i][j]);
        }
        ans = max (ans , sgt.tr[1]);
    } cout << ans;
    return 0;
}