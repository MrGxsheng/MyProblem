#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 3010 , M = 400010;
int n,m,k;
int h[N],e[M],ne[M],w[N],idx;
int dist[N][N];
bool st[N];
int  a[N],b[N];
priority_queue<PII,vector<PII>,greater<PII>> heap;

void add(int a,int b ,int c){
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dijkstra(int start){
	memset(st,0,sizeof st);
	dist[start][start] = 0;
	heap.push({0,start});

	while(heap.size()){
		auto t = heap.top();
		heap.pop();

		int ver = t.se;
		if(st[ver]) continue;
		st[ver] = true;
		for(int i = h[ver] ; ~i ; i = ne[i]){
			int j = e[i];
			if(dist[start][j] > dist[start][ver] + w[i]){
				dist[start][j] = dist[start][ver] + w[i];
				heap.push({dist[start][j],j});
			}
		}
	}
}

void solve(){
	cin >> n >> m >> k;
	memset(dist,0x3f,sizeof dist);
	memset(h,-1,sizeof h);
	while(m--) {
		int x, y, w;
		cin >> x >> y >> w;
		add(x,y,w);
		add(y,x,w);
	}
	
	for(int i = 1 ; i <= k ; i++)	cin >> a[i] >> b[i];
	
	
	for (int i = 1; i <= n; i++) dijkstra(i);
	
	
	int ans = 1e9;
	for (int v = 1; v <= n; v++) {
		for(int i = h[v] ; ~i ; i = ne[i]){
			int j = e[i];
			int cur = 0;
			for(int x = 1 ; x <= k ; x++)
				cur += min({dist[a[x]][b[x]], dist[a[x]][v] + dist[j][b[x]], dist[a[x]][j] + dist[v][b[x]]});
			
			ans = min(ans, cur);
		}
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
