#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> a(n);
	vector<int> b,c;
	for(int i = 0 ; i < n ; i++){ 
		cin >> a[i];
		if(a[i] & 1) b.push_back(a[i]);
		else c.push_back(a[i]);
	}

	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	int maxx = -1;
	if(b.size() >= 2) maxx = max(maxx,b[b.size() - 1] + b[b.size() - 2]);
	if(c.size() >= 2) maxx = max(maxx,c[c.size() - 1] + c[c.size() - 2]);
	cout << maxx << endl;

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