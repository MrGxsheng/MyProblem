/*
	欧拉路+并查集

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
char s[15];
int deg[N]; //每个点的度数
int p[N];
unordered_map<string,int> M;

int getid(const char *s){
	return M[s] ? M[s] : M[s] = ++n; //字符串转化为序号
}

//并查集
int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

//判断 是否是有效合并
bool join(int a ,int b){
	int x = find(a);
	int y = find(b);
	if(x == y) return false;
	p[x] = y;
	return true;
}

void solve(){
	int x ,y,cnt = 0;
	for(int i = 1 ; i <= N ; i++) p[i] = i;//并查集初始化
	while(~scanf("%s",s)){
		x = getid(s);//求编号
		scanf("%s",s);
		y = getid(s);
		if(join(x,y)) ++cnt;//记录有效合并次数
		++deg[x];//统计度数
		++deg[y];
	}

	//欧拉图 判断是否联通，只有当cnt==n-1时是联通的
	if(cnt < n - 1) {
		puts("Impossible");
		return;
	}

	cnt = 0; //判断奇数度点的个数
	for(int i = 1 ; i <= n ; i++) 
		if((deg[i] & 1) && ++cnt > 2){
			puts("Impossible");
			return;
		}

	puts("Possible");
}

int main(){
	int T;
	// cin >> T;
	T =1;
	while(T--) solve();
	return 0;
}

