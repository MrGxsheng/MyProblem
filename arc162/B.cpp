#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> p(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> p[i];
		p[i]--;
	}	

	vector<array<int,2>> ans;
	for(int i = n - 1 ; i >= 2;  i--){
		int j = find(p.begin(), p.end(),i) - p.begin();
		if(j == 0){
			ans.push_back({1,1});
			rotate(p.begin(), p.begin() + 2 , p.begin() + 3);
			j = 1;
		}
		ans.push_back({j,i - 1});
		rotate(p.begin() + j - 1, p.begin() + j + 1 , p.begin() + i + 1);
		cerr << j << endl;
		for(int x = 0 ; x < n ; x ++) cout << p[x] << ' ';
		cout << endl;
	}

	if(p[0] != 0){
		cout << "No" << endl;
		return;
	}

	cout << "Yes" << endl;
	cout << ans.size() << endl;
	for(auto [i,j] : ans){
		cout << i << " " << j << endl;
	}

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