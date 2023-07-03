#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	char a,b;
	cin >> a >> b;
	if(a > b) swap(a,b);
	vector<int> v(8);
	v[2] = 3;
	v[3] = 4;
	v[4] = v[3] + 4;
	v[5] = v[4] + 1;
	v[6] = v[5] + 5;
	v[7] = v[6] + 9;
	cout << v[b - 'A' + 1] - v[a - 'A' + 1] << endl;

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