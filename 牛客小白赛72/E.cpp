#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m,p,q,k;
LL a[N],b[N],v[N];

bool check(LL x){
	LL sum = 0;
	for(int i = 1 ; i <= n ; i++){
		LL pp = (x + a[i] - 1) / a[i];
		int idx = upper_bound(b + 1 ,b + 1 + m , pp - 1) - b;
		sum += idx - 1;
	}
	auto idx = upper_bound(v + 1 , v + 1 + p , x - 1) - v;
	sum -= idx - 1;

	if(sum >= k) return false;
	return true;
}

void solve(){
	cin >> n >> m >> p >> q;

	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= m ; i++) cin >> b[i];

	for(int i = 1 ;i <= p ; i++){
		int x,y;
		cin >> x >> y;
		v[i] = 1ll * a[x] * b[y];
	}

	sort(a + 1 , a + 1 + n);
	sort(b + 1 , b + 1 + m);
	sort(v + 1 , v + 1 + p);

	while(q--){
		cin >> k;
		LL l = 1 , r = 1e12;
		while(l < r){
			LL mid = l + r + 1 >> 1;
			if(check(mid)) l = mid;
			else r = mid - 1;
		}
		cout << l << endl;
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