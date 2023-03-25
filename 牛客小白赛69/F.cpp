#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
PII p[N];
bool vis[1100][1100];
int cal(PII a, PII b){
	 return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

void solve(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> p[i].first >> p[i].second;
		vis[500 + p[i].first][500 + p[i].second] = 1;
	}

	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		map<int,int> cnt;
		for(int j = 0 ; j < n ; j++){
			if(i == j) continue;
			cnt[cal(p[i],p[j])]++;
		}

		for(auto x : cnt){
			int t = x.second;
			ans += t * (t - 1) / 2;
		}
	}

	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1 ; j < n ; j++){
			PII a = p[i] , b = p[j];
			int midx = a.first + b.first;
			int midy = a.second + b.second;
			if(midx % 2 == 0 && midy % 2 == 0){
				midx /= 2;
				midy /= 2;
				if(vis[midx + 500][midy + 500]) ans--;
			}
		}
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