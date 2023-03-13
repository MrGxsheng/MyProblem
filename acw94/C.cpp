#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 510;
int n,m;
LL g[N][N],b[N][N];
int x[N];
bool st[N];
LL ans[N];
void floyd(int x){
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			g[i][j] = min(g[i][j],g[i][x] + g[x][j]);
}

void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			cin >> g[i][j];
	for(int i = 1 ; i <= n ; i++) cin >> x[i];

	for(int i = n ; i >= 1 ; i--){
		st[x[i]] = true;
		floyd(x[i]);
		for(int j = 1 ; j <= n ; j++){
			if(!st[j]) continue;
			for(int x = 1 ; x <= n ; x++)
				if(st[x]) ans[i] += g[j][x];
		}
	}

	for(int i = 1 ; i <= n ; i++) cout << ans[i] << ' ';

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
