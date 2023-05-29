#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int a[N];
int s[N], ss[N];
bool check(int now, int idx){
	int z = s[idx] - s[now - 1], zz = ss[idx] - ss[now - 1];
	if(min(zz, z) > m)	return false;
	return true;	
}

bool check2(int now, int idx){
	int z = s[idx] - s[now - 1], zz = ss[idx] - ss[now - 1];
	if(min(zz, z) < m)	return false;
	return true;	
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i){
		cin >> a[i], s[i] = ss[i] = 0;
	}

	for(int i = 1; i <= n; ++ i){
		ss[i] = ss[i-1];
		s[i]	= s[i-1];
		while(a[i] % 2 == 0){
			++ s[i];
			a[i] /= 2;
		}
		while(a[i] % 5 == 0){
			++ ss[i];
			a[i] /= 5;
		}
	}
	// for(int i = 1 ; i <= n ; i++) cout << s[i] << ' ';
	// 	cout << endl;
	// for(int i = 1 ; i <= n ; i++) cout << ss[i] << ' ';
	// 	cout << endl;


	LL ans = 0;
	for(int i = 1; i <= n; ++ i){
		int l = i, r = n;
		int L, R;
		while(r > l){
			int mid = l + r + 1 >> 1;
			if(check(i, mid))	l = mid;
			else r = mid - 1;
		}
		if(!check(i, l))	continue;
		R = l;
		
		l = i, r = n;
		while(r > l){
			int mid = l + r >> 1;
			if(!check2(i, mid)) l = mid + 1;
			else r = mid;
		}
		if(!check2(i, l))	continue;
		L = l;
		ans += R - L + 1;
	}
	cout << ans << endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}