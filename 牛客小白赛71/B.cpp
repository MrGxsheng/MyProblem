#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
string ss[4] = {"ove","lve","loe","lov"};
void solve(){
	string s;
	cin >> s;
	
	auto b = s.find("ove");
	auto c = s.find("lve");
	auto d = s.find("loe");
	auto e = s.find("lov");
	if(~b || ~c || ~d || ~e) {
		cout << "YES" << endl;
		return;
	} 

	cout << "NO" << endl;
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