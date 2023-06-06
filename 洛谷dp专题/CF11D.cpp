#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
bool a[19][19];
LL f[600001][19]; // i 是出发点（二进制压缩） j是终点 当 两个数相同时 相当于找到一个环
LL ans;
void solve(){
	cin >> n >> m;
	for (int i = 0 ; i < m ; ++i){
		int u,v;
		cin >> u >> v;
		u--,v--;
		a[u][v] = a[v][u] = 1; //加边
	}

	for (int i = 0 ; i < n ; ++i)
		f[1 << i][i] = 1; // 初始化(创建以i为起点的路径)
	
	for (int i = 1 ; i <= (1 << n) ; ++i){
		for(int j = 0 ; j < n ; j++){
			if(!f[i][j]) continue; // 加速
			for(int k = 0 ; k < n ; k++){
				if(!a[j][k]) continue; // 加速
				if((i & -i) > 1 << k) continue;
				if(1 << k & i){ // 这个点走过
					if(1 << k == (i & -i)) // 起点与终点相同
						ans += f[i][j]; 
				}else f[i | 1 << k][k] += f[i][j]; // 没走过就走
			}
		}
	}
	//这种方法因为无向图的存在，会出现（同一条路径出现两次）（一条边和两个端点构成非法环）的情况，
	//这只需要在输出答案时 ans=(ans−m)/2 即可！
	cout << (ans - m) / 2 << endl;

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