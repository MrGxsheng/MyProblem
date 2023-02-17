#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
LL s;
int a[N];
int fib[N];
map<LL,int> mp;

bool dfs(int u , int pre){
	if(u == -1 ) return true;
	for(int i = 1 ; i <= n ; i++){
		if(i == pre) continue;
		if(a[i] >= fib[u]){
			a[i] -= fib[u];
			if(dfs(u - 1 , i)) return true;
			a[i] += fib[u];
		}
	}
	return false;
}


void solve1(){
	cin >> n;
	s = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		s += a[i];
	}

	if(mp.find(s) == mp.end()){ 
		puts("No");
		return;
	}else{
		if(dfs(mp[s],0)) puts("YES");
		else puts("NO");
	}
}

void solve(){
	cin >> n;
	s = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		s += a[i];
	}

	if(mp.find(s) == mp.end()){ 
		puts("No");
		return;
	}
	else {
		bool st = true;
		int last = 0;
		for(int i = mp[s] ; i >= 0  && st; i --){
			int k = 0;
			for(int j = 1 ; j <= n ; j++){
				if(j == last) continue;
				if(a[j] > a[k]) k = j;
			}

			if(a[k] >= fib[i]) a[k] -= fib[i] , last = k;
			else st = false;
		}
		st ? puts("YES") : puts("NO");

	}

}

int main(){
	int T;
	cin >> T;
	s = 2;
	mp[1] = 0;
	mp[2] = 1;
	fib[0] = fib[1] = 1;
	for(int i = 2 ; i <= 43 ; i++){
		s += (fib[i] = fib[i - 2] + fib[i - 1]);
		mp[s] = i;
	}
	while(T--) solve1();
	return 0;
}
