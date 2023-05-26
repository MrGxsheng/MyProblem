#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int a,b,c;

bool check(int x){
	return x % 4 == 0 && (x % 100 != 0 || x % 400 == 0);
}

void solve(){
	while(cin >> a >> b >> c && a){
		int ans = 0;
		if(check(a)){
			int z[] = {31,29,31,30,31,30,31,31,30,31,30,31};
			for(int i = 0 ; i < b - 1 ; i++)
				ans += z[i];
			
			ans += c;
		}else{
			int z[] = {31,28,31,30,31,30,31,31,30,31,30,31};
			for(int i = 0 ; i < b - 1 ; i++)
				ans += z[i];
			ans += c;
		}
		cout << ans << endl;
	}
	
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}