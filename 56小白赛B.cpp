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
	if(n <= 2){
         cout << 1 << endl;
        cout << n << endl;
    }else{
        cout << n << endl;
        for(int i = 1 ; i <= n ; i++) cout << 1 << ' ';
    }
    
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
