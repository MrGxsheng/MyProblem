#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 110;
int n,m;
LL g[N][N], dis[N][N];
void solve(){
	cin >> n;

	for(int i = 1 ; i <= n ; i++){
		string s;
		cin >> s ;
		for(int j = 0 ; j < n ; j++){
			g[i][j + 1] = s[j] - '0';
			dis[i][j + 1] = g[i][j + 1];
			if(dis[i][j + 1] == 0) dis[i][j + 1] = 0x3f3f3f3f;
			if(i == j + 1) dis[i][j + 1] = 0;
		}
	}


	cin >> m;
	vector<int> a(m + 1);
	for(int i = 1 ; i <= m ; i++) cin >> a[i];

	for(int k = 1 ; k <= n ; k++)
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
				dis[i][j] = min(dis[i][k] + dis[k][j],dis[i][j]);

	vector<int> v;
	v.push_back(a[1]);
	int las = a[1];
	int cur = 0;
	for(int i = 2 ; i <= m ; i++){
		cur += dis[a[i - 1]][a[i]];
		if(dis[las][a[i]] < cur){
			las = a[i - 1];
			v.push_back(las);
			cur = dis[las][a[i]];
		}
	}

	v.push_back(a[m]);
	cout << v.size() << endl;
	for(auto x : v) cout << x << ' ';
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