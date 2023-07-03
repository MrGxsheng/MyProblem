#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	int x,y;
	cin >> x >> y;
    if (min({x, y, 16 - x, 16 - y}) % 2 == 1) {
        cout << "black\n";
    } else {
        cout << "white\n";
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