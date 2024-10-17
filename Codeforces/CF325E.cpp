#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;

int n , f[N] , nxt[N];

int find (int x) {
    if (f[x] == x) return x;
    return f[x] = find (f[x]);
}

void merge (int x , int y) {
    f[find (y)] = find (x);
}

signed main() {
    cin >> n;
    if (n & 1) return cout << -1 << '\n' , 0;
    for (int i = 1;i <= n;i ++) f[i] = i;
    for (int i = 0;i < n / 2;i ++) 
        merge (i , nxt[i] = 2 * i),
        merge (i + n / 2 , nxt[i + n / 2] = 2 * i + 1);
    for (int i = 0;i < n / 2;i ++) if (find (i) != find (i + n / 2)) swap (nxt[i] , nxt[i + n / 2]) , merge (i , i + n / 2);
    cout << 0 << ' '; for (int i = nxt[0];i;i = nxt[i]) cout << i << ' '; cout << 0 << ' ';
    return 0;
}