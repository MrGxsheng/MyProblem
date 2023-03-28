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
	cin >> n;
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 6 ; j++)
			if(n){
				cout << 1;
				n--;
			} 
			else cout << 0;
		cout << endl;
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

