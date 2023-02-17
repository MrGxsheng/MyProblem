#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
LL n,m;
LL solve(LL x){
	
	if(x >= 0 && x <= 10) return (LL)x * x;
	else if(x > 10 && x <= 50) return (LL)x * solve(x - 5);
	else if(x > 50 && x <= 100) return  (LL)x + solve(x - 10);

}

int main(){
	int T;
	// cin >> T;
	T = 1;
	cin >> n;
	while(T--) 
		cout << solve(n) << endl;
	return 0;
}
