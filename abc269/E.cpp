#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	int l = 0 , r = n;
	while(r - l > 1){
		int x = l + r >> 1;
		cout << "?" << 1 << " " << x << " " << 1 << " " << n << endl;
		int res;
		cin >> res;
		if(res == x) l = x;
		else r = x;
	}

	int X = r;
	l = 0 , r = N;
	while(r - l > 1){
		int x = l + r >> 1;
		cout << "?" << 1 << " " << n << " " << 1 << " " << x << endl;
		int res;
		cin >> res;
		if(res == x) l = x;
		else r = x;
	}

	int Y = r;
	cout << "! " << X << " " << Y << endl;
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