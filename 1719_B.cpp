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
	cin >> n >> m;
	if(m % 2 == 1){
		puts("YES");
		for(int i = 1; i <= n ; i += 2) cout << i <<' ' <<i + 1 << endl;
		return;
	}else{
		if(m % 4 == 2){
			puts("YES");
			for(int i = 2 ; i <= n ; i += 2){
				if(i % 4 == 2) cout << i << ' ' << i - 1 << endl;
				else cout << i - 1 << ' '  << i << endl;
			}
		}else puts("NO");
	}

}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
