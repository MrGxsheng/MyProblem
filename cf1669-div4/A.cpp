#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	if(n <= 1399) cout << "Division 4" << endl;
	else if(n <= 1599) cout << "Division 3" << endl;
	else if(n <= 1899) cout << "Division 2" << endl;
	else cout << "Division 1" << endl;	
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}