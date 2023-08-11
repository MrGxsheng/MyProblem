#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m,c;
void solve(){
	cin >> n >> c;
	int A = (1 << 30) - 1 , O = 0 , X = 0;
	for(int i = 0 ; i < n ; i++){
		int t,x;
		cin >> t >> x;

		if(t == 1){
			A &= x;
			O &= x;
			X &= x;
		}else if(t == 2){
			A |= x;
			O |= x;
			X &= ~x;
		}else {
			int t = x & (~A | O);
			A ^= t;
			O ^= t;
			X ^= x ^ t;
		}

		c = ((c & A) | O) ^ X;
		cout << c << endl;
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