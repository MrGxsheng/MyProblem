#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010 , mod = 998244353;
int n,m;
int p[N];
int siz[N];
vector<LL> cnt;
int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

LL qmi(int a, int b, int p)
{
    LL res = 1 % p;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * (LL)a % p;
        b >>= 1;
    }
    return res;
}


void solve(){
	cin >> n >> m;
	
	for(int i = 1 ; i <= n ; i++) p[i] = i , siz[i] = 1;


 	for(int i = 0 ; i < m  ; i++){
		int u,v;
		cin >> u >> v;

		int pa = find(u);
		int pb = find(v);
		if(pa != pb) {
			siz[pb] += siz[pa];
			p[pa] = pb;
		}
	}


	LL ans = 0;
	for(int i = 1 ; i <= n ; i++){
		if(find(i) == i){
			int x = siz[i];
			cnt.push_back((qmi(2,x,mod) - 1) % mod);
		}
	}
	
	ans = cnt[0];
	for(int i = 1 ; i < cnt.size() ; i++){
		ans = ans * cnt[i] % mod;
	}

	cout << ans % mod << endl;

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