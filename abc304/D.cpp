#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	int W,H;
	cin >> W >> H;
	cin >> n;
	vector<PII> p(n);
	for(int i = 0 ; i < n ; i++) cin >> p[i].first >> p[i].second;

	int A;
	cin >> A;
	vector<int> a(A + 1);
	for(int i = 0 ; i < A ; i++) cin >> a[i];
	a[A] = W;

	int B;
	cin >> B;
	vector<int> b(B + 1);
	for(int i = 0 ; i < B ; i++) cin >> b[i];
	b[B] = H;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	function <LL(int,int)> find = [&] (int x,int y){
		int ta = lower_bound(a.begin(), a.end(),x) - a.begin();
		int tb = lower_bound(b.begin(), b.end(),y) - b.begin();
		return 1ll * tb * (A + 1) + ta + 1;
	};

	map<LL,int> mp;
	for(int i = 0 ; i < n ; i++){
		LL id = find(p[i].first,p[i].second);
		mp[id]++;
	}

	int mi = 1e9 , ma = -1e9;
	A++,B++;
	if(mp.size() != 1ll * A * B) mi = 0;
	for(auto [c,v] : mp){
		mi = min(v,mi);
		ma = max(v,ma);
	}

	cout << mi << ' ' << ma << endl;
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