#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	string s;
	cin >> s;
	array<int,7> a;
	for(int i = 0 ; i < 7 ; i++)
		a[i] = "atcoder"s.find(s[i]);

	int ans = 0;
	for(int i = 0 ; i < 7 ; i++)
		for(int j = i + 1 ; j < 7 ; j++)
			ans += a[i] > a[j];
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