#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> a(n),b(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	for(int i = 0 ; i < n ; i++) cin >> b[i];

	auto vA = a , vB = b;
	sort(vA.begin(), vA.end());
	sort(vB.begin(), vB.end());

	if(vA != vB){
		cout << "No" << endl;
		return;
	}

	if(set(vA.begin(), vA.end()).size() < n){
		cout << "Yes" << endl;
		return;
	}

	vector<int> p(n);
	for(int i = 0 ; i < n ; i++){
		p[a[i] - 1] = b[i] - 1;
	}

	int par = 0;
	vector<bool> vis(n);

	for(int i = 0 ; i < n ; i++){
		if(vis[i]) continue;
		int j = i;
		while(!vis[j]){
			vis[j] = true;
			par ^= 1;
			j = p[j];
		}
		par ^= 1;
	}

	if(par == 0){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
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