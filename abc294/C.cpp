#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	map<int,int> mp;
	vector<int> a(n + m);
	int cnt = 0;
	for(int i = 0; i < n ; i++){
		cin >> a[cnt];
		mp[a[cnt++]] = 1;
	}
	for(int i = 0; i < m ; i++){
		cin >> a[cnt];
		mp[a[cnt++]] = 2;
	}
	vector<int> b,c;
	int res = 1;
	sort(a.begin(), a.end());
	for(int i = 0 ; i < n + m ; i++){
		if(mp[a[i]] == 1) b.push_back(res++);
		else c.push_back(res++);
	}

	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	for(int i = 0 ; i < n ; i++) cout << b[i] << ' ';
	cout << endl;
	for(int i = 0 ; i < m ; i++) cout << c[i] << ' '; 

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