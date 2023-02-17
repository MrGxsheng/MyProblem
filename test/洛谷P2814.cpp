#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
map<string,string> p;
int n,m;

string find(string x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve(){
	char op;
	string s;
	string ss;
	while(true){
		cin >> op;
		if(op == '$') break;
		else if(op == '#') {
			cin >> s;
			if(!p.count(s)) p[s] = s;
		}
		else if(op == '+'){
			cin >> ss;
			if(!p.count(ss)) p[ss] = ss;
			string pa = find(ss);
			string pb = find(s);
			p[pa] = pb;
		}else if(op == '?'){
			cin >> ss;
			string pa = find(ss);
			cout << ss << ' ' << pa << endl;
		}
	}
}

int main(){
	int T;
	// cin >> T;
	T =1;
	while(T--) solve();
	return 0;
}

