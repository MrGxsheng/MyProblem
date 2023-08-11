#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010,mod = 1e9 + 7;
int n,m;
PII a[N];
vector<int> b;
int tr[N];
int f[N];
int find(int x){
	return lower_bound(b.begin(), b.end(),x) - b.begin() + 1;
}

int lowbit(int x){
	return x & -x;
}

void add(int x,int c){
	for(int i = x ; i <= N ; i += lowbit(i)) tr[i] += c;
}

int sum(int x){
	if(x <= 0) return 0;
	int res = 0;
	for(int i = x ; i ;i -= lowbit(i)) res += tr[i];
	return res;
}

void solve(){
	cin >> m >> n;
	b.push_back(0);
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i].first >> a[i].second;
		b.push_back(a[i].first);
		b.push_back(a[i].second);
		b.push_back(a[i].first - 1);
		b.push_back(a[i].second - 1);
	}
	b.push_back(m);
	sort(a + 1,a + n + 1,[&](const auto&p, const auto&q){
		return p.second < q.second;
	});

	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()),b.end());

	add(find(0),1);
	for(int i = 1 ; i <= n ; i++){
		int l = a[i].first;
		int r = a[i].second;
		f[i] = (((sum(find(r - 1)) - sum(find(l - 1))) % mod) + mod) % mod;
		add(find(r),f[i]);
	}

	int res = 0;
	for(int i = 1 ; i <= n ; i++)
		if(a[i].second >= m) res = (res + f[i]) % mod;
	cout << (res % mod + mod) % mod << endl;

}

signed  main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}