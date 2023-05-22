#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;

	cout << fixed << setprecision(2);

	if(n & 1){
		cout << pow(2,(n + 1) / 2) / 2<< endl;
	}else{
		cout << sqrt(pow(2,n / 2) / 2 * pow(2,n / 2))<< endl;
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