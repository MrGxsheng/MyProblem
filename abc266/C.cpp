#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	array<int,8> x,y;
	for(int i = 0 ; i < 4 ; i++){
		cin >> x[i] >> y[i];
		x[i + 4] = x[i];
		y[i + 4] = y[i];
	}

	for(int i = 0 ; i < 4 ; i++){
		int o = (x[i + 1] - x[i]) * (y[i + 2] - y[i + 1]) - (x[i + 2] - x[i + 1]) * (y[i + 1] - y[i]);
		if(o <= 0){
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
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