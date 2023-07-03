#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;


int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
	st[1] = 1;
	st[0] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        if (st[i]) continue;
        primes[cnt ++ ] = i;
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}

void solve(){
	cin >> n;


	vector<int> a;
	while(n){
		a.push_back(n);
		n /= 10;
	}

	
	for(int i = 0 ; i < a.size() ; i++){
		if(st[a[i]]){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	get_primes(N - 1);
	while(T--) solve();
	return 0;
}