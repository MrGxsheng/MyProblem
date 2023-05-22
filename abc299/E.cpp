#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
vector<int> G[N];

void solve(){
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	vector<bool> black(n,true);
	int k;
	cin >> k;

	vector<int> p(k),d(k);
	for(int i = 0 ; i < k ; i++){
		cin >> p[i] >> d[i];
		p[i]--;

		vector<int> dis(n,-1);
		queue<int> q;
		dis[p[i]] = 0;
		q.push(p[i]);

		while(!q.empty()){
			int x = q.front();
			q.pop();

			if(dis[x] < d[i]){
				black[x] = false;
			}
			for(auto y : G[x]){
				if(dis[y] == -1){
					dis[y] = dis[x] + 1;
					q.push(y);
				}
			}
		}
	}

	queue<int> q;
	vector<int> dis(n,-1);

	for(int i = 0 ; i < n ; i++){
		if(black[i]){
			q.push(i);
			dis[i] = 0;
		}
	}

	while(q.size()){
		int x = q.front();
		q.pop();

		for(auto y : G[x]){
			if(dis[y] == -1){
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
	}

	for(int i = 0 ; i < k ; i++){
		if(dis[p[i]] != d[i]){
			cout << "No" << endl;
			return;
		}
	}

	cout << "Yes" << endl;
	
	for(int i = 0 ; i < n ; i++) {
		cout <<  black[i];
	}
	cout << endl;
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