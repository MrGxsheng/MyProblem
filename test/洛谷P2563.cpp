#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
int primes[N];
int cnt;
bool st[N];

void get_primes(int n){
	for(int i = 2 ; i <= n ; i++){
		if(!st[i]) primes[cnt++] = i;
		for(int j = 0 ; primes[j] <= n / i ; j ++){
			st[primes[j] * i] = true;
			if(i % primes[j] == 0) break;
		}
	}
}

void solve(){
	while(cin >> n){
		cnt = 0;
		memset(primes,0,sizeof primes);
		get_primes(n);
		vector<LL> f(n + 1);
		f[0] = 1;
		for(int i = 0 ; i < cnt ; i++)
			for(int j = primes[i] ; j <= n ; j++)
				f[j] += f[j - primes[i]];
		cout << f[n] << endl;
	}

}

int main(){
	int T;
	// cin >> T;
	T = 1;
	
	while(T--) solve();
	return 0;
}
