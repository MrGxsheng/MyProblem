#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	LL p,q,r;
	cin >> n >> p >> q >> r;
	vector<int> a(n);
	vector<LL> s(n + 1);
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		s[i + 1] = s[i] + a[i];
	}	

	for(int x = 0 ,y = 0 ,z = 0 , w = 0 ; x < n ; x++){
		while(y < n && s[y] - s[x] < p) y++;
		while(z < n && s[z] - s[y] < q) z++;
		while(w < n && s[w] - s[z] < r) w++;
		if(s[y] - s[x] == p && s[z] - s[y] == q && s[w] - s[z] == r){
			cout << "Yes" << endl;
			return;
		}
	}

	cout << "No" << endl;
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