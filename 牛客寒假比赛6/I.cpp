#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
int cnt[N];
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({0, 1});

	while (q.size()) 
	{
		auto t = q.top();
		q.pop();

		int ver = t.second;

		if (st[ver]) continue;
		st[ver] = true;

		for ( int i = h[ver]; i != -1; i = ne[i] ) {
			int j = e[i];
			if (dist[j] > dist[ver] + w[i]) {
				dist[j] = dist[ver] + w[i];
				q.push({dist[j], j});
			}
		}
	}
	return dist[n];
}

void bfs()
{
	queue<int> q;
	q.push(1);

	while (q.size()) 
	{
		int t = q.front();
		q.pop();

		for ( int i = h[t]; i != -1; i = ne[i] ) {
			int j = e[i];
			if (cnt[j] || j == 1) continue;
			cnt[j] = cnt[t] + 1;
			q.push(j);
		}
	}
}
void solve(){
	memset(h, -1, sizeof h);

	cin >> n >> m;
	for ( int i = 1; i <= m; i ++ ) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a != 1 && b != 1) c = 1;
		add(a, b, c);
		add(b, a, c);
	}

	bfs();

	if (cnt[n] != m) cout << cnt[n] << endl;
	else cout << dijkstra() << endl;

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
