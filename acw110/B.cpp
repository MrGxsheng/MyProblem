#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;

void solve(){
	cin >> n;
	vector<int> a;
	for(int i = 1 ; i * (i + 1) <= n * 2 ; i++) a.push_back(i * (i + 1));

	for(int i = 1 ; i * (i + 1) <= n * 2 ; i++){
		int x = i * (i + 1);
		int tar = lower_bound(a.begin(), a.end(),n * 2 - x) - a.begin();
		if(n * 2 == x + a[tar]){
			cout << "YES" << endl;
			return;
		} 
	}
	cout << "NO" << endl;
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