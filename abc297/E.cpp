#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];

	set<LL> s{0};

	for(int i = 0 ; i < m ; i++){
		LL x = *s.begin();
		s.erase(x);
		for(int j = 0 ; j < n ; j++){
			s.insert(x + a[j]);
		}
	}
	cout << *s.begin() << endl;
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