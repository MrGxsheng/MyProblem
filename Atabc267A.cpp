#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
void solve(){
	string s;
	cin >> s;
	if(s == "Monday") cout << 5 << endl;
	else if(s == "Tuesday") cout << 4 << endl;
	else if(s == "Wednesday") cout << 3 << endl;
	else if(s == "Thursday") cout << 2 << endl;
	else if(s == "Friday") cout << 1 << endl;
}

int main(){
	int T;
	T = 1;
	while(T--) solve();
	return 0;
}
