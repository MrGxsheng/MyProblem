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
void solve(){
	cin >> n >> m;

	vector<int> a(n * n , n * n + 1) , inva(n * n , - 1);
	vector<vector<int>> adj(n * n);
	vector<int> deg(n * n);

	for(int i = 0 ; i < m ; i++){
		int o;
		cin >> o;
		if(o == 1){
			int x,y,z;
			cin >> x >> y >> z;
			x--,y--;
			a[x * n + y] = z;
			inva[z - 1] = x * n + y;
		}else{
			int x,y;
			cin >> x >> y;
			x--,y--;
			for(int j = 0 ; j < n ; j++){
				if(j != y){
					adj[x * n + j].push_back(x * n + y);
					deg[x * n + y]++;
				}

				if(j != x){
					adj[x * n + y].push_back(j * n + y);
					deg[j * n + y]++;
				}
			}
		}
	}

	vector<int> q;
	for(int i = 0 ; i < n * n ; i++){
		if(!deg[i]) q.push_back(i);
	}

	bool ok = true;
	for(int i = 0 ; i < n * n ; i++){
		if(q.size() <= i){
			ok = false;
			break;
		}

		int x = q[i];
		for(auto y : adj[x]){
			if(!--deg[y]) q.push_back(y);
		}
	}

	if(ok){
		auto f = a;
		for(int i = n * n - 1 ; i >= 0 ; i--){
			int x = q[i];
			for(auto y : adj[x]){
				f[x] = min(f[x],f[y]);
				deg[y]++;
			}
		}

		priority_queue<PII> h;
		for(int i = 0 ; i < n * n ; i++){
			if(!deg[i] && a[i] > n * n) h.emplace(-f[i],i);
		}

		for(int i = 0 ; i < n * n ; i++){
			int x;
			if(inva[i] != -1){
				x = inva[i];
				if(deg[x]){
					ok = false;
					break;
				}
			}else{
				if(h.empty()){
					ok = false;
					break;
				}
				x = h.top().second;
				h.pop();
			}
			a[x] = i + 1;
			for(auto y : adj[x]){
				if(!--deg[y] && a[y] > n * n) h.emplace(-f[y],y);
			}
		}
	}
		if(!ok) a.assign(n * n,0);

		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				cout << a[i * n + j] << ' ';
			}
			cout << endl;
		}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
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
