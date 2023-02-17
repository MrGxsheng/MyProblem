/**
 * 逆向思维
 * 
 */
#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010 , M = 1000010;
int n,m;
int h[N],e[M],ne[M],idx,s[N];
int p[N];
bool st[N];
void add(int a,int b){
	e[idx] = b;
	s[idx] = a;//存边的起点
	ne[idx] = h[a];
	h[a] = idx++;
}

int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve(){
	memset(h,-1,sizeof h);
	memset(st,true,sizeof st);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) p[i] = i;//并查集初始化

	for(int i = 1 ; i <= m ; i++){
		int a,b;
		cin >> a >> b;
		//建立双向边
		add(a,b);
		add(b,a);
	}

	int k;
	cin >> k;
	// pk 存创建的点,ans 存 答案（都是逆序）
	stack<int> pk,ans; 

	int res = n - k;
	for(int i = 1 ; i <= k ; i++){
		int x;
		cin >> x;
		st[x] = false;
		pk.push(x);
	}

	m = m * 2; //无向边边数 * 2 , res 是存储连通块数量
	res = n - k;
	for(int i = 1 ; i <= m ; i++){
		int S = find(s[i]);
		int E = find(e[i]);
		if(S != E && st[s[i]] && st[e[i]]){ // 保证 边的两个端点均存在 且不在一个连通块
			p[E] = S;
			res--; // 连上之后 连通块--
		} 	
	}

	ans.push(res);

	while(pk.size()){
		int tot = pk.top();
		pk.pop();

		res++;
		st[tot] = true;

		for(int i = h[tot] ; ~i ; i = ne[i]){ //遍历这个新建点的临边
			int j = e[i];
			int S = find(tot);
			int E = find(j);
			if(S != E && st[j]){
				res--;
				p[E] = S;
			}
		}
		ans.push(res);
	}
	while(ans.size()){
		res = ans.top();
		ans.pop();
		printf("%d\n",res);
	}

}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
