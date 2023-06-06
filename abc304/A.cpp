#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,string> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> a(n);
	vector<string> s(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> s[i] >> a[i];
	}
	int idx = min_element(a.begin(), a.end()) - a.begin();

	cout << s[idx] << endl;
	for(int i = idx + 1 ; i != idx ; i ++){
		i %= n;
		if(i == idx) break;
		cout << s[i] << endl;
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