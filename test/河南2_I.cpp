#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
LL n,m;
LL cnt;
//       位数     层数   每位数上的和   枚举出的数
void dfs(int sum,int u ,LL num1,LL num2){
	if(num2 > n) return;
	if(num1 > 2 * sum) return;
	if(u > sum){
		if(num1 == 2 * sum) cnt++;
		return;
	}

	for(int i = 0 ; i <= 9 ; i++){
		if(u == 1 && i == 0) continue;
		dfs(sum,u + 1,num1 + i , num2 * 10 + i);
	}
}

void solve(){
	cin >> n;

	for(int i = 1; i <= 10 ; i++)
		dfs(i,1,0,0);
	cout << cnt << endl;
	
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
