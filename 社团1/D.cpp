#include <bits/stdc++.h>
#define debug puts("-----")
#define eps (1e-8)
#define inf (1<<30)
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	vector<int> st(n);
	while(m--){
		int ans = 0;
		int op,num;
		cin >> op >> num;
		num--;
		if(op == 1) {
			if(num - 3 >= 0) st[num - 3] ++;
			if(num + 3 < n) st[num + 3] ++;
		
		}else{
			if(num - 3 >= 0) st[num - 3] --;
			if(num + 3 < n) st[num + 3] --;
		}
		for(int i = 0 ; i < n ; i++) 
			if(st[i]) ans++;
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
                                          
