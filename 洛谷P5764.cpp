/**
 * 堆优化的dijksra + dfs
 */
#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010 , M = N * 2,INF = 0x3f3f3f3f;
int n,m;
int id[6];
int h[N],e[M],ne[M],w[N],idx;
int dist[6][N];
bool st[N];
int res;

int dfs(int u,int start , int distance){
	if(u > 5) return distance;

	int res = INF;
	for(int i = 1 ; i <= 5 ; i++){
		if(!st[i]){
			int next = id[i];
			st[i] = true;
			res = min(res,dfs(u + 1 ,i,distance + dist[start][next]));
			st[i] = false;
		}
	}
	return res;
}


void dijkstra(int start,int dist[]){
	memset(dist,0x3f,N * 4); // int 4个字节，所以大小是4*N
	dist[start] = 0;
	memset(st,0,sizeof st);

	priority_queue<PII, vector<PII>, greater<PII> > heap;
	heap.push({0,start});

	while(heap.size()){
		auto t = heap.top();
		heap.pop();

		int ver = t.second;
		if(st[ver]) continue;
		st[ver] = true;

		for(int i = h[ver] ; ~i ; i = ne[i]){
			int j = e[i];
			if(dist[j] > dist[ver] + w[i]){
				dist[j] = dist[ver] + w[i];
				heap.push({dist[j],j});
			}
		}
	}
}

void add(int a ,int b ,int c){
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

void solve(){
	cin >> n >> m;
	memset(h,-1,sizeof h);
	id[0] = 1;
	for(int i = 1 ; i <= 5 ; i++ ) cin >> id[i];

	while(m--){
		int a ,b ,c;
		cin >> a >> b >> c;
		add(a,b,c);
		add(b,a,c);
	}

	for(int i = 0 ; i < 6 ; i++) dijkstra(id[i],dist[i]);
	memset(st,0,sizeof st);
	
	printf("%d\n", dfs(1,0,0));
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}

