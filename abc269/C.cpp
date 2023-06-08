#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
LL n,m;
void solve(){
	cin >> n;
	vector<LL> idx;
	int id = 0;
	m = n;
	while(m){
		if(m & 1) idx.push_back(id);
		id++;
		m >>= 1;
	}
	m = idx.size();
	vector<LL> ans;
	for(int i = 0 ; i < (1 << m) ; i++){
		LL x = 0;
		for(int j = 0 ; j < m ; j++)
			if(i >> j & 1){
				x |= 1ll << idx[j];
			}
		ans.push_back(x);
	}

	sort(ans.begin(), ans.end());
	for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] << endl;
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