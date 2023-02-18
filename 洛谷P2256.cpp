#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
map<string,string> mp;

string find(string x){
	if(x != mp[x]) mp[x] = find(mp[x]);
	return mp[x];
}

void solve(){
	cin >> n >> m;
	string s;
	for(int i = 0 ; i < n ; i++){
		cin >> s;
		mp[s] = s;
	}
	string a,b,pa,pb;
	while(m--){
		cin >> a >> b;
		pa = find(a);
		pb = find(b);
		if(pa != pb) mp[pa] = pb;
	}

	int Q;
	cin >> Q;
	while(Q--){
		cin >> a >> b;
		pa = find(a);
		pb = find(b);
		if(pa != pb) puts("No.");
		else puts("Yes.");
	}

}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
