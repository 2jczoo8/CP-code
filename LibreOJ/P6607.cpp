#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int B = 450;
int n , m , fac[N] , inv[N] , f[2][N];
int C (int x , int y){
	if (x < 0 || y < 0 || x < y) return 0;
	return fac[x] * inv[y] % mod * inv[x - y] % mod;
}
int qpow (int a , int n){
	int res = 1; for (;n;n >>= 1) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
    } return res;
}
signed main(){
	cin >> n >> m; fac[0] = inv[0] = 1;
	for(int i = 1;i <= n + m;i ++) fac[i] = fac[i - 1] * i % mod;
	inv[n + m] = qpow (fac[n + m] , mod - 2);
	for(int i = n + m - 1;i >= 1;i --) inv[i] = inv[i + 1] * (i + 1) % mod;
	f[0][0] = 1; int ans = C(n + m - 1,n - 1);
	for(int i = 1;i <= B;i ++){
		for(int j = 0;j <= m;j ++) f[i & 1][j] = 0;
		for(int j = i;j <= m;j ++){
			f[i & 1][j] = (f[i & 1][j - i] + f[(i & 1) ^ 1][j - i]) % mod;
			if(j >= n + 1) f[i & 1][j] = (f[i & 1][j] - f[(i & 1) ^ 1][j - (n + 1)] + mod) % mod;
			int res = C (m - j - 1 + n , n - 1) * f[i & 1][j] % mod;
			if(i & 1) ans = (ans - res + mod) % mod;
			else ans = (ans + res) % mod;
		}
	}
	cout << ans;
	return 0;
}

