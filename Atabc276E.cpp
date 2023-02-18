#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
vector <char> G[N];
vector <int> vis[N];
int sx,sy;
bool st;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void bfs(){
	queue<PII> q;

	int dis = 0;
	for(int i = 0 ;  i < 4 ; i++){
		int x = sx + dx[i];
		int y = sy + dy[i];
		if(x < 0 || x >= n || y < 0 || y >= m || G[x][y] == '#') continue;
		vis[x][y] = ++ dis;
		q.push({x,y});
	}
		


	while(q.size()){
		auto t = q.front();
		q.pop();

		for(int i = 0 ; i < 4 ; i ++){
			int x = t.fi + dx[i];
			int y = t.se + dy[i];
			if(x < 0 || x >= n || y < 0 || y >= m || G[x][y] == '#' || G[x][y] == 'S') continue;
			if(!vis[x][y]){
				vis[x][y] = vis[t.fi][t.se];
				q.push({x,y});
			}else if(vis[x][y] != vis[t.fi][t.se]){
				st = true;
				return;
			}
		}
	}
}



void solve(){
	cin >> n >> m;

	for(int i = 0 ; i < n ; i++){
		string s;
		cin >> s;
		for(int j = 0 ; j < m ; j++){
			G[i].push_back(s[j]);
			vis[i].push_back(0);
			if(s[j] == 'S') sx = i,sy = j;
		}
	}
	bfs();
	
	if(!st) cout << "No" << endl;
	else cout << "Yes" << endl; 
		
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
