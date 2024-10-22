#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n , tr[N] , p[N] , pa , pb , pc;

struct node {
    int a , b , c , id;
}t[N];

bool cmp1 (node a , node b) {
    return a.a < b.a;
}

bool cmp2 (node a , node b) {
    return a.b < b.b;
}

void add (int x) {
    for (;x <= n;x += x & (-x)) tr[x] ++;
}

void del (int x) {
    for (;x <= n;x += x & (-x)) tr[x] --;
}

int query (int x) {
    int res = 0;
    for (;x;x -= x & (-x)) res += tr[x];
    return res;
}

void cdq (int l , int r) {
    if (l == r) return ;
    int mid = l + r >> 1; cdq (l , mid); cdq (mid + 1 , r);
    int j = l;
    for (int i = mid + 1;i <= r;i ++) {
        while (j <= mid && t[j].b < t[i].b) add (t[j].c) , j ++;
        p[t[i].id] += query (t[i].c);
    } 
    for (;j > l;del (t[-- j].c));
    sort (t + l , t + 1 + r , cmp2);
}

int C (int n) {
    return n * (n - 1) / 2;
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i ++) {
        cin >> t[i].a >> t[i].b >> t[i].c;
        t[i].id = i;
    } sort (t + 1 , t + 1 + n , cmp1);
    cdq (1 , n);
    for (int i = 1;i <= n;i ++) tr[i] = 0;
    sort (t + 1 , t + 1 + n , cmp1);
    for (int i = 1;i <= n;i ++) pa += C (query (t[i].b)) , add (t[i].b);
    for (int i = 1;i <= n;i ++) tr[i] = 0;
    for (int i = 1;i <= n;i ++) pc += C (query (t[i].c)) , add (t[i].c);
    for (int i = 1;i <= n;i ++) tr[i] = 0; sort (t + 1 , t + 1 + n , cmp2);
    for (int i = 1;i <= n;i ++) pb += C (query (t[i].c)) , add (t[i].c);
    int ans = n;
    ans += (n) * (n - 1) * (n - 2) / 6;
    ans += C (n);
    for (int i = 1;i <= n;i ++) ans -= p[i] - C (p[i]) * 2;
    ans -= pa + pb + pc;
    cout << ans;
    return 0;
}