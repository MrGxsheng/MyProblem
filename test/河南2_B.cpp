#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<LL> a(n + 1);
	map<LL,int> mp;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];

	for(int i = 2 ; i <= n ;i ++)
		for(int j = i ; j <= n ; j++)
			mp[a[i] * a[j]] = i;

	int res = 0;
	for(int i = 1 ; i < n ; i++)
		for(int j = i + 1 ; j <= n ; j++)
			if(a[i] == 0 && a[j] == 0){
				res++;
				break;
			}else if(a[j] == 0) continue;
			else if(a[i] % a[j] == 0){
				LLcnt = a[i] / a[j];
				if(mp[cnt] > i){
					res++;
					break;
				}
			}
		
	cout << res << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
