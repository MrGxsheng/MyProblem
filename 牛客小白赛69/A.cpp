#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
LL n,m;
void solve(){
	cin >> n >> m;
	LL x = n / m;
	LL y = n - x * m;
	if(x > y){
		cout << "niuniu eats less than others" << endl;
	}else if(x < y){
		cout << "niuniu eats more than others" << endl;
	}else cout << "same" << endl;
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