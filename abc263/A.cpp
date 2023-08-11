#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	vector<int> a(5);
	for(int i = 0 ; i < 5 ; i++) cin >> a[i];

	sort(a.begin(), a.end());

	if((a[0] == a[2] && a[3] == a[4]) || (a[0] == a[1] && a[2] == a[4])) cout << "Yes" << endl;
	else cout << "No" << endl;

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