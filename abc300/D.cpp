#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
LL n,m;

struct Primes {
    bitset <N> st;
    int cnt,primes[N],idx[N],n;
 
    Primes(int n = N - 1) {
        this->n = n;
        init(n);
    }
 
    void init(int n) {
        st[0] = st[1] = 1;
        for(int i = 2;i <= n;i ++) {
            if(!st[i]) {
                primes[++ cnt] = i;
                idx[i] = cnt;
            }
            for(int j = 1;primes[j] <= n / i;j ++) {
                st.flip(primes[j] * i);
                if(i % primes[j] == 0) break;
            }
        }
    }
    
    //判断x是否是质数      
    bool isPrime(int x) {
        assert(x <= n);
        return !st[x];
    }
    
    //求解x在质数表是第几个                    
    bool atIndex(int x) {
        assert(!st[x]);
        assert(x <= n);
        return idx[x];
    }
};
using i128 = __int128;

void solve(){
    cin >> n;
	Primes pr(1e6);
	vector<int> v;
	for(int i = 1 ; i <= 1e6 ; i++)
		if(pr.isPrime(i)) v.push_back(i);
    
	int cnt = 0;
	for(int i = 0 ; i < v.size() ; i++){
		LL v1 = 1ll * v[i] * v[i];
		if(v1 > n) break;
		for(int j = i + 1 ; j < v.size() ; j++){
			i128 v2 = (i128) 1 * v[j];
			if((i128) 1ll * v1 * v2 > n) break;
			for(int k = j + 1 ; k < v.size() ; k++){
				i128 v3 = 1ll * v[k] * v[k];
				if((i128) v1 * v2 * v3 > n) break;
				cnt++;
			}
		}
	}

	cout << cnt << endl;
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