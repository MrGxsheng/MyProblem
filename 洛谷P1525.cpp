/*
	二分图

*/

#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
int h[N],e[N],ne[N],idx,w[N];
int color[N];

void add(int a , int b ,int c){
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool dfs(int u , int c , int mid){
	color[u] = c;
	for(int i = h[u] ; ~i ; i = ne[i]){
		int j = e[i];
		if(w[i] <= mid) continue;
		if(color[j]){
			if(color[j] == c) return false;
		}else if(!dfs(j,3 - c, mid)) return false;
	}
	return true;
}

bool check(int mid){
	memset(color,0,sizeof color);
	for(int i = 1 ; i <= n ; i++)
		if(!color[i])
			if(!dfs(i,1,mid)) return false;
	return true;
}

void solve(){
	cin >> n >> m;
	memset(h,-1,sizeof h);
	while(m--){
		int a , b,c;
		cin >> a >> b >> c;
		add(a,b,c);
		add(b,a,c);
	}

	int l  = 0 , r = 1e9;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}

	printf("%d\n",r);
}

int main(){
	int T;
	// cin >> T;
	T =1;
	while(T--) solve();
	return 0;
}

