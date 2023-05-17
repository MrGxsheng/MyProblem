#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;

	if(n % 2 == 0 && m % 2 == 0){
		printf("NO");
		return;
	}

	printf("YES\n");
	if(n & 1){
		for(int i = 1 ; i <= n ; i++)
			if(i & 1)
				for(int j = 1 ; j <= m ; j++){
					if(i == 1 && j == 1) continue;
					if(i == n && j == m) break;
					printf("%d %d\n",i,j);	
				}
			else 
				for(int j = m ; j >= 1 ; j--){
					printf("%d %d\n",i,j);	
				}
	}else {
		for(int i = 1 ; i <= m ; i++){
			if(i & 1)
				for(int j = 1 ; j <= n ; j++){
					if(i == 1 && j == 1) continue;
					if(i == m && j == n) break;
					printf("%d %d\n",j,i);	
				}
			else 
				for(int j = n ; j >= 1 ; j--){
					printf("%d %d\n",j,i);	
				}
		}
	}
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}