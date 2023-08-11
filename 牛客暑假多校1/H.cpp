#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;


void solve(){
	cin >> n;
	LL sum = 0;
	vector<int> a(n),b(n);
	vector<int> l,r;
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	for(int i = 0 ; i < n ; i++){
		cin >> b[i];
		if(b[i] > a[i]){
			l.push_back(i);
		}
		if(b[i] < a[i]){
			r.push_back(i);
		}

		sum += abs(a[i] - b[i]);
	}

	sort(l.begin(), l.end(),[&](int i ,int j){return abs(a[i] - b[i]) > abs(a[j] - b[j]);});
	sort(r.begin(), r.end(),[&](int i ,int j){return abs(a[i] - b[i]) > abs(a[j] - b[j]);});

	LL dec = 0;
	for(int i = 0 ; i < min(10000, (int)l.size()) ; i++){
		for(int j = 0 ; j < min(10000,(int)r.size()) ; j++){
			LL ii = l[i] , jj = r[j];
			dec = max(dec,1ll * abs(a[ii] - b[ii]) + 1ll * abs(a[jj] - b[jj]) - abs(a[ii] - b[jj]) - abs(a[jj] - b[ii]));
		}
	}
	cout << sum - dec << endl;

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