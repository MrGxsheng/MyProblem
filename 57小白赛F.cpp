#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;

int qmi(int a ,int b , int p){
	int ans = 1 ;
	while(b){
		if(b & 1) ans = (ans * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return ans % p;
}

void solve(){
	int p;
	cin >> n >> p;
	vector<int> a(n) , b(n);
	for(auto &i : a) scanf("%d",&i);
	for(auto &i : b) scanf("%d",&i);
	for(auto &i : a) i %= p;

	if(a == b){
		printf("0");
		return;
	}

	vector<int> c(p);

	for(int i = 0 ; i < n ; i++) c[(b[i] - a[i] + p) % p] = 1;
	int ans , minn = 1e9;
	for(int x = 1 ; x < p ; x++){
		int tmp = qmi(x,p - 2 , p);
		int times = -1;
		for(int i  = 0 ; i < p ;  i++)
			if(c[i])
				times = max(times,tmp * i % p);
		if(times < minn){
			minn = times;
			ans = x;
		}
	}
	cout << ans << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
