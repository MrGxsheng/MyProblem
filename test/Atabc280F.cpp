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
const int N = 100010 , M = N * 2;
int n,m;
vector<LL> dist(N,-1e18);
int p[N];
bool st[N];
bool vis[N];
vector<PII> v[N + 1];

int find(int x){
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}


void bfs(int start){
	vis[start] = true;
	dist[start] = 0;
	queue<int> q;

	q.push(start);

	while(q.size()){
		auto t = q.front();
		q.pop();
		for(auto [x,y] : v[t]){
			if(dist[x] == -1e18){
				dist[x] = dist[t] + y;
				q.push(x);
				vis[x] = true;
				continue;
			}

			if(dist[t] + y != dist[x] ){
				st[find(start)] = true;
				return;
			}
		}
	}
}



void solve(){
	 int Q;
	 cin >> n >> m >> Q;
	 for(int i = 1; i <= n ; i ++) p[i] = i;
	 for(int i = 1 ; i <= m ; i++){
	 	int a,b,c;
	 	cin >> a >> b >> c;
	 	v[a].push_back({b,c});
	 	v[b].push_back({a,-c});
	 	int pa = find(a);
	 	int pb = find(b);
	 	p[pa] = pb;
	 }

	 for(int i = 1 ; i <= n ; i++){
	 	if(vis[find(i)]) continue;
	 	vis[find(i)] = true;
	 	bfs(find(i));
	 }

	 while(Q--){
	 	int a,b;
	 	cin >> a >> b;
	 	int pa = find(a);
	 	int pb = find(b);
	 	if(pa != pb) {
	 		cout << "nan" << endl;
	 		continue;
	 	}

	 	if(st[pa]){
	 		cout << "inf" << endl;
	 		continue;
	 	} 

	 	cout << dist[b] - dist[a] << endl;

	 }
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
