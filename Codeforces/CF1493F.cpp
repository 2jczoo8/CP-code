#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back

int qry (int h , int w , int ax , int ay , int bx , int by) {
    cout << "? " << h << ' ' << w << ' ' << ax << ' ' << ay << ' ' << bx << ' ' << by << endl;
    int f; cin >> f; return f;
}

int a , b , ans = 1;

void solve (int n) {
    vector <int> fac; int x = n;
    for (int i = 2;i <= n;i ++) while (x % i == 0) x /= i , fac.pb(i);
    if (x > 1) fac.pb (x); x = n;
    for (int i : fac) {
        int d = x / i;
        if (i == 2) {
            if (qry (d , b , 1 , 1 , d + 1 , 1)) x /= i;
            continue;
        }
        else if (qry (d * (i / 2) , b , 1 , 1 , d * (i / 2 + 1) + 1 , 1)) {
            if (qry (d * (i / 2) , b , d + 1 , 1 , d * (i / 2 + 1) + 1 , 1)) x /= i;
        }
    }
    int cnt = 0;
    for (int i = x;i <= n;i += x) if (n % i == 0) cnt ++;
    ans *= cnt;
}

void solve1 (int n) {
    vector <int> fac; int x = n;
    for (int i = 2;i <= n;i ++) while (x % i == 0) x /= i , fac.pb(i);
    if (x > 1) fac.pb (x); x = n;
    for (int i : fac) {
        int d = x / i;
        if (i == 2) {
            if (qry (a , d , 1 , 1 , 1 , 1 + d)) x /= i;
            continue;
        }
        else if (qry (a , d * (i / 2) , 1 , 1 , d * (i / 2 + 1) + 1 , 1)) {
            if (qry (a , d * (i / 2) , 1 , 1 + d , 1 , d * (i / 2 + 1) + 1)) x /= i;
        }
    }
    int cnt = 0;
    for (int i = x;i <= n;i += x) if (n % i == 0) cnt ++;
    ans *= cnt;
}

signed main() {
    cin >> a >> b;
    solve (a); solve1 (b);
    cout << "! " << ans << endl;
    return 0;
}