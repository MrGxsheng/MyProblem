/**
 * 并查集+01背包
 * 
 */
#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m,k;
int p[N];
int f[N];
int s[N];//维护每个并查集中的数量
int find(int x){ 
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve(){
	cin >> n >> m >> k;
	if(k == 0) { // 特判
		cout << m << endl;
		return;
	}

	//初始化
	for(int i =1 ; i <= n ; i++){
		p[i] = i;
		s[i] = 1;
	}

	while(k--){
		int a , b;
		cin >> a >> b;
		int pa = find(a);
		int pb = find(b);
		if(pa != pb) {
			p[pa] = pb;
			s[pb] +=s[pa];
		}
	}

	int top = 0;
	for(int i = 1 ; i <= n ; i++)
		if(p[i] == i) s[++top] = s[i];  

	//01背包
	for(int i = 1 ; i <= top ; i++)
		for(int j = 2 * m ; j >= s[i] ; j--)
			f[j] = max(f[j],f[j - s[i]] + s[i]);

	//找距离m最近的
	int ans = 9999999 , minn = 99999999;
	for(int i = 1 ; i <= 2 * m ; i++){
		if(minn > abs(f[i] - m)) minn = abs(f[i] - m) , ans = f[i];
	}
	if(ans == 9999999) printf("0");
	else printf("%d",ans);

}

int main(){
	int T;
	// cin >> T;
	T =1 ;
	while(T--) solve();
	return 0;
}
