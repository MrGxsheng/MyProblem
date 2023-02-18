#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 110;
int n,m,k;
LL f[N][N][N];
LL a[N];
map<LL,bool> mp;
void solve(){
	cin >> n >> m >> k;

	for(int i = 1; i <= n ; i++) cin >> a[i];
	memset(f,-0x3f,sizeof f);
	for(int i = 0 ; i <= n ; i++) f[i][0][0] = 0;
	
	
	for(int i = 1 ; i <= n ; i++)
		for(int j = min(i,m) ; j >= 0; j--)
			for(int x = 0 ; x <= k - 1 ; x++){
				f[i][j][x] = max(f[i][j][x],f[i - 1][j][x]);
				if(j >= 1 && f[i - 1][j - 1][x] >= 0 )
				f[i][j][(x + a[i]) % k] = max(f[i][j][(x + a[i]) % k],f[i - 1][j - 1][x] + a[i]);
			}

	LL ans = -1;

	for(int i = m ; i <= n ; i++) 
		ans = max(f[i][m][0],ans);
	
	cout << ans << endl;


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

//        _                                    _  _  _         _                   
//       | |                                  (_)| || |       | |                  
//   ___ | |__    ___  _ __    __ _ __      __ _ | || |  __ _ | | __    ___  _ __  
//  / __|| '_ \  / _ \| '_ \  / _` |\ \ /\ / /| || || | / _` || |/ /   / __|| '_ \ 
//  \__ \| | | ||  __/| | | || (_| | \ V  V / | || || || (_| ||   <  _| (__ | | | |
//  |___/|_| |_| \___||_| |_| \__, |  \_/\_/  |_||_||_| \__,_||_|\_\(_)\___||_| |_|
//                             __/ |                                               
//                            |___/                                             
