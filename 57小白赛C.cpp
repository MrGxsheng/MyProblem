#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
LL n,m,k,a,b;

void solve(){
    cin >> n >> k >> a >> b;

    if(a == b || abs(a - b) > k){
        puts("YES");
        return;
    }

    if(n <= k) puts("NO");
    else if((abs(a - 1) > k || abs(a - n) > k) && (abs(b - 1) > k || abs(b - n) > k)) puts("YES");
    else puts("NO");
    
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
