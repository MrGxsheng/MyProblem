#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;

int ask(int x){
	cout << "? " << x << endl;
	int v;
	cin >> v;
	return v;
}

void solve(){
	cin >> n;
	int l = 1 , r = n;
	while(l <= r){
		int mid = l + r >> 1;
		if(ask(mid) ^ 1) l = mid + 1;
		else r = mid - 1;
	}

	cout << "! " << l - 1 << endl;
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