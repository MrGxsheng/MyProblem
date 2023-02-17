#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 6e6 + 10;
int n,m;
bool prime[N];
int is_prime[N],cnt;
int a[N];
set<int> st;
int mi = 1,ans[N];

void get(){
	for(int i = 2 ; i < N; i ++){
		if(!prime[i]) is_prime[++cnt] = i;
		for(int j = 1 ; is_prime[j] < N / i ; j ++){
			prime[is_prime[j] * i] = 1;
			if(i % is_prime[j] == 0) break;
		}
	}
}

void solve(){
	cin >> n >> m;
	int x;
	for(int i = 1 ; i <= n ; i++){
		cin >> x;
		st.insert(x);
		while(x == is_prime[mi] || st.count(is_prime[mi])) mi++;
		ans[i] = mi;
	}
	
	while(m--){
		int x;
		cin >> x;
		cout << is_prime[ans[x]] << endl;

	}
}

int main(){
	get();
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
