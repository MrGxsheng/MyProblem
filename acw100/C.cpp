#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1010;
int n,m;
int v[N], p[N], e[N], q[N], tot;
bool st[N];
//v 表示代价，p表示操作序列
//e表示原始序列，tot表示目前长度
//p[k] 表示k在原始序列位置
//st表示在操作序列中是否出现过
void solve(){
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) cin >> v[i];
    for (int i = 1; i <= m; i ++ ) cin >> p[i];

    for (int i = 1; i <= m; i ++ ) //创造最优牌堆
        if (!st[p[i]]) //判断是否第一次出现
        {
            e[++ tot] = p[i]; //加入牌底
            q[p[i]] = tot; //记录位置
            st[p[i]] = true; //标记：出现过
        }

    int ans = 0; //表示总代价
    for (int i = 1; i <= m; i ++ )
    {
        int k = p[i];
        for (int j = q[p[i]] - 1; j >= 1; j -- ) 
        {
            ans += v[e[j]];
            q[e[j]] = j + 1;
            e[j + 1] = e[j];
        }
        e[1] = k, q[e[1]] = 1;
        //修改位置，累计代价
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