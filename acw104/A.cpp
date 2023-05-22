#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,a;
void solve(){
	cin >> n >> a;
	if(a & 1){
		cout << (a - 1) / 2 + 1 << endl;
	}else{
		cout << (n - 2) / 2 - (a - 2) / 2 + 1  << endl;
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