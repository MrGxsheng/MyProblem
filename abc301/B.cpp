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
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	vector<int> ans;
	for(int i = 1 ; i < n ; i++){
		int x = a[i - 1];
		if(a[i] - x > 0){
			while(a[i] != x){
				ans.push_back(x);
				x++;
			}
		}else{
			while(a[i] != x){
				ans.push_back(x);
				x--;
			}
		}
	}

	ans.push_back(a[n - 1]);

	for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] << ' ';
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