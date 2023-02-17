#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 2000010;
int n,m;
int a[N];
int res[j];

void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	sort (a + 1 ,a + 1 + n);
	int k = 1;
	
	for(int i = 0 ; i <= 9 ; i ++){
		int j = i;
		if(!j) j = 10;
		while(j <= n){
			res[j] = a[k++];
			j+= 10;
		}
	}

	for(int i = 1 ; i <= n ; i++ ) cout << res[i] << ' ';

}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
