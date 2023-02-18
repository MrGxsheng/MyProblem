/**
 * 堆优化的dijkstara统计方案数
 */
#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010,mod = 100003,M = N * 2;
int n,m;
int h[N],e[M],ne[M],idx;
int dist[N];
int st[N];
int res[N];

void add(int a,int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dijkstra(){
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;

	priority_queue<PII,vector<PII>, greater<PII> > heap;
	heap.push({0,1});

	while(heap.size()){
		auto t = heap.top();
		heap.pop();

		int ver = t.second;
		if(st[ver]) continue;
		st[ver] = true;

		for(int i = h[ver] ; ~i ; i = ne[i]){
			int j = e[i];
			if(dist[j] > dist[ver] + 1){
				dist[j] = dist[ver] + 1;
				res[j] = res[ver];
				heap.push({dist[j],j});
			}else if(dist[j] == dist[ver] + 1){
				res[j] += res[ver];
				res[j] %= mod;
			}
		}
	}
}




void solve(){
	cin >> n >> m;
	memset(h,-1,sizeof h);
	while(m--){
		int a ,b;
		cin >> a >> b;
		add(a,b);
		add(b,a);
	}

	res[1] = 1;

	dijkstra();
	
	for(int i = 1 ; i <= n ; i++)
		cout << res[i] << endl;
	


}

int main(){
	int T;
	// cin >> T
	T = 1;
	while(T--) solve();
	return 0;
}
