#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 72;
int n,m,k;
LL f[N][N][N][N];
int a[N][N];

LL dfs(int i,int j,int x,int v){
	if(i == n + 1){
		if(v == 0) return 0;
		else return INT_MIN;
	}else if(f[i][j][x][v] != -1) return f[i][j][x][v];
	else {
		LL ans = INT_MIN;
		if(x < m / 2){
			if(j + 1 <= m) ans = max(ans,a[i][j] + dfs(i,j + 1,x + 1,(v + a[i][j]) % k));
			ans = max(ans,a[i][j] + dfs(i + 1,1,0,(v + a[i][j]) % k));
		}
		if(j + 1 <= m) ans = max(ans,dfs(i,j + 1,x,v));

		ans = max(ans,dfs(i + 1,1,0,v));
		return f[i][j][x][v] = ans;
	}
}

void solve(){
	cin >> n >> m >> k;

	for(int i = 1 ; i <= n ; i++)
		for(int j = 1; j <= m ; j++)
			cin >> a[i][j];
	memset(f,-1,sizeof f);

	LL ans = dfs(1,1,0,0);
	cout << max(0ll,ans) << endl;
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
