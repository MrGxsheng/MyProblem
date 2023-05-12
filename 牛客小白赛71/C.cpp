#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef __int128 LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	int a,b,c = 2;
	LL x,y;
	cin >> a >> b;
	x = a,y = b;
	while(1){
		LL t = 1;
		for(int i = 1 ; i <= y ; i++){
			if(t * x > 1e18){
				cout << c << endl;
				return;
			}
			t *= x;
		}
			c ++;
			x = y;
			y = t;
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