#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010,mod = 998244353;
int n,m;
LL f[N][10];
void solve(){
	cin >> n;
	for(int i = 1 ; i <= 9 ; i++) {
		if(i == 1) f[2][i] = 2;
		else if(i == 9) f[2][i] = 2;
		else f[2][i] = 3;
	}
	for(int i = 3 ; i <= n ; i++)
		for(int j = 1 ; j <= 9 ; j++){
			if(j == 1) f[i][j] = (f[i - 1][j + 1] + f[i - 1][j] + f[i][j]) % mod;
			else if(j == 9) f[i][j] = (f[i - 1][j - 1] + f[i - 1][j] + f[i][j]) % mod ;
			else f[i][j] = (f[i - 1][j + 1] + f[i - 1][j] + f[i - 1][j - 1] + f[i][j] ) % mod;
	}
	LL res = 0;
	for(int i = 1 ; i <= 9 ; i++) res = (res + f[n][i]) % mod;
	cout << res % mod << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}

/*
*
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/
