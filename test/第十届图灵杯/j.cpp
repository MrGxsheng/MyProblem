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
const int N = 1000010;
int n,m;
bool st[N];
void solve(){
	cin >> n;
	vector<int> a(n + 1),deg(n + 1),g[n + 1],dis(n + 1);

	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		g[i].push_back(a[i]);
		deg[a[i]] ++;
	}
	queue<int> q;

	for(int i = 0 ; i <= n  ; i++)
		if(deg[i] == 0) {
			q.push(i);
			dis[i] = 1;
			st[i] = true;
		}

	while(q.size()){
		int t = q.front();
		q.pop();
		for(auto x : g[t]){
			dis[x] = max(dis[x] ,dis[t] + 1);
			if(--deg[x] == 0){
				q.push(x);
				st[x] = true;
			}
		}
	}

	int ans = 0;
	for(int i = 0 ; i <= n ; i ++)
		if(!st[i]) ans++;
	int res = 0;
	for(int i = 0 ; i <= n ; i++)
		res = max(res,dis[i]);

	ans += res;
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
