#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	int a = floor(n * 0.1);
	int b = floor(n * 0.2);
	int c = floor(n * 0.3);

	int aa = ceil(n * 0.1);
	int bb = ceil(n * 0.2);
	int cc = ceil(n * 0.3);
	cout << aa - a << ' ' << (aa - a) + (bb - b) << ' ' << (aa - a) + (bb - b) + cc - c;
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