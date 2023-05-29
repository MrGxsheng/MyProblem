#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	map<PII,bool> vis;
	for(int i = 0 ; i < m ; i++){
		int k;
		cin >> k;
		vector<int> a(k);
		for(int j = 0 ; j < k ; j++)
			cin >> a[j];
		

		for(int j = 0 ; j < k ; j++)
			for(int z = j ; z < k ; z++){
				vis[{a[j],a[z]}] = true;
				vis[{a[z],a[j]}] = true;
			}
	}

	for(int i = 1 ; i <= n ; i++)
		for(int j = i ; j <= n ; j++)
			if(!vis[{i,j}] && !vis[{j,i}]){
				cout << "No" << endl;
				return;
			}

	cout << "Yes" << endl;
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