#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
bitset<110> f[110];
void solve(){
	cin >> n >> m;
	vector<int> p(n);
	for(int i = 0 ; i < n ; i++){
		int c;
		cin >> p[i] >> c;

		for(int j = 0 ; j < c ; j++){
			int x;
			cin >> x;
			f[i][x] = 1;
		}
	}

	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++){
			if(i == j) continue;
			if(p[i] >= p[j] ){
				bool vis = true;
				for(int k = 1 ; k <= m ; k++)
					if((f[j][k] == 0 && f[i][k] == 1)) vis = false;

				if(vis && (p[i] > p[j] || f[j].count() > f[i].count())){
					cout << "Yes" << endl;
					return;
				}
			}
		}
	cout << "No" << endl;
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