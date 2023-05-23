#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	int a,b;
	cin >> n >> a >> b;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		if(x == a + b){
			cout << i + 1 << endl;
			return;
		}
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