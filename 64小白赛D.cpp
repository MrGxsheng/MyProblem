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
const int N = 300010 , M = 600010;
int n,m;
int h[N],w[N],e[M],ne[M],idx;
int siz[N];
void add(int a, int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dfs(int u){
	siz[u] = 1;
	for(int i = h[u] ; ~i ; i = ne[i]){
		int j = e[i];
		dfs(j);
		siz[u] += siz[j];
	}
}

void solve(){
	cin >> n;
	memset(h,-1,sizeof h);
	for(int i = 1 ; i <= n ; i++) siz[i] = 1;
	for(int i = 1 ; i <= n ; i++) cin >> w[i];
	for(int i = 2 ; i <= n ; i++){
		int x;
		cin >> x;
		add(x,i);
	}

	dfs(1);

	sort(w + 1 , w + 1 + n);
	sort(siz + 1 ,siz + 1 + n);

	LL ans = 0;
	for(int i = 1 ; i <= n ; i++){
		ans += w[i] * siz[i]; 
	}

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
