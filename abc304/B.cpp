#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	m = n;
	int cnt = 0;
	while(m){
		cnt++;
		m /= 10;
	}

	int z = 0;
	if(cnt > 3) z = cnt - 3;
	if(z) {
		n = n / pow(10,z);
		n = n * pow(10,z);
	}

	cout << n << endl;

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