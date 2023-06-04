#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	if(n == 1){
		cout << 1 << endl;
	}else if(n % 2){
		cout << -1 << endl;
	}else{
		for(int i = 0 ; i < n ; i++)
			cout << (i ^ 1) + 1 << ' ';
		cout << endl;
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}