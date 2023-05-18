#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 10000010 , mod = 998244353;
LL n,m;
LL mul[N];
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
	cin >> n;

	LL res = (1 + n) * n / 2 % mod;
	cout << res % mod * res % mod << ' ' << qmi(mul[n],2 * n,mod) % mod << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	mul[1] = 1;
	for(LL i = 2 ; i < N ; i++)
		mul[i] -= mul[i - 1] * i % mod;
	cin >> T;
	while(T--) solve();
	return 0;
}