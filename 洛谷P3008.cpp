#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010,M = 1500010,INF = 0x3f3f3f3f;
int n,m,mr,mp,S;
int h[N],e[M],ne[M],w[M],idx;
int dist[N];
bool st[N];
int din[N];
int id[N];
int bcnt;
queue<int> q;
vector<int> block[N];

void add(int a,int b, int c){
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dfs(int u,int bid){
	id[u] = bid;
	block[bid].push_back(u);
	for(int i = h[u] ; ~i ; i = ne[i]){
		int j = e[i];
		if(!id[j]) dfs(j,bid);
	}
}

//对优化的dijkstra
void dijkstra(int bid){
	priority_queue<PII , vector<PII> , greater<PII>> heap;
	for(int i : block[bid])
			heap.push({dist[i],i});
	
	while(heap.size()){
		auto t = heap.top();
		heap.pop();

		int ver = t.y;
		if(st[ver]) continue;
		st[ver] = true;
		for(int i = h[ver] ; ~i ; i = ne[i]){
			int j = e[i];
			if(id[ver] != id[j] && --din[id[j]] == 0) q.push(id[j]);
			if(dist[j] > dist[ver] + w[i]){
				dist[j] = dist[ver] + w[i];
				if(id[j] == id[ver]) heap.push({dist[j],j});
			} 
		}
	}
}

//拓扑排序
void topsort(){
	memset(dist,0x3f,sizeof dist);
	dist[S] = 0;

	for(int i = 1 ; i <= bcnt ; i++)
		if(!din[i]) q.push(i);
	
	while(q.size()){
		int t = q.front();
		q.pop();
		dijkstra(t);
	}
}


void solve(){
	cin >> n >> mr >> mp >> S;
	memset(h,-1,sizeof h);
	while(mr--){
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b,c);
		add(b,a,c);
	}

	for(int i = 1 ; i <= n ; i++)
		if(!id[i]) 
			
			dfs(i,++bcnt);
		
	
	while(mp--){
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b,c);
		din[id[b]] ++;
	}

	topsort();

	for(int i = 1 ; i <= n ; i++){
		if(dist[i] > INF / 2) puts("NO PATH");
		else cout << dist[i] << endl;
	}
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
