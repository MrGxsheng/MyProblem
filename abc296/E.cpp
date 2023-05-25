#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i];
		a[i]--;
	}

	int ans = 0;
	vector<int> vis(n,-1);
	for(int i = 0 ; i < n ; i++){
		int j = i;
		while(vis[j] == -1){
			vis[j] = i;
			j = a[i];
		}
		if(vis[j] == i){
			int t = j;
			do{
				t = a[t];
				ans += 1;
			}while(t != j);
		}
	}
	cout << ans << endl;


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