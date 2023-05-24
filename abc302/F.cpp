#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;

	vector<vector<int>> s(n),f(m);
	for(int i = 0 ; i < n ; i++ ){
		int A;
		cin >> A;
		s[i].resize(A);
		for(int j = 0 ; j < A ; j++){
			cin >> s[i][j];
			s[i][j]--;
			f[s[i][j]].push_back(i);
		}
	}

	vector<bool> vis(n);
	vector dis(m,-1);
	queue<int> q;
	q.push(0);
	dis[0] = 0;

	while(!q.empty()){
		int x = q.front();
		q.pop();

		for(auto i : f[x]){
			if(!vis[i]){
				vis[i] = true;
				for(auto y : s[i]){
					if(dis[y] == -1){
						dis[y] = dis[x] + 1;
						q.push(y);
					}
				}
			}
		}
	}

	int ans = dis[m - 1];
	if(ans != -1) ans--;
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