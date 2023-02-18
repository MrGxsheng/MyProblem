#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 100010 , M = 200010 , INF = 0x3f3f3f3f;
int n,m;
vector<int> e[N];
char g[N];
void init(){
	for(int i = 1 ; i <= 26 ;  i++) g[i] = char(i - 1 + 'a');
}

void solve(){
	vector<int> ans;
	string s;
	cin >> s;
	int pt = 0;
	int st = s[0] - 'a',ed = s.back() - 'a';
	for(int i = 0 ; i < 26 ; i ++) e[i].clear();
	for(int i = 0 ; i < s.size() ; i++) e[s[i] - 'a'].push_back(i + 1);
	int n = s.size();
	if(st == ed){
		cout << 0 << ' ' << e[st].size() << endl;
		cout << 1 << ' ';
		for(auto i : e[st])
			if(i != 1 && i != n )
				cout << i << ' ';
		cout << n << endl;
		return;
	}

	ans.push_back(1);
	int yd = st,pe = st;
	while(yd > ed){
		if(e[yd].size() >= 2 || (e[yd].size() == 1 && yd != st)){
			pt += abs(pe - yd);
			for(auto i : e[yd]) if(i != 1) ans.push_back(i);
			pe = yd;
		}
		yd--;
	}

	while(yd < ed){
		if(e[yd].size() >= 2 || (e[yd].size() == 1 && yd != st)){
			pt += abs(pe - yd);
			for(auto i : e[yd]) if(i != 1) ans.push_back(i);
			pe = yd;
		}
		yd++;
	}
	pt += abs(pe - yd);
	for(auto x : e[yd])
		if(x != n && x != 1) ans.push_back(x);
	ans.push_back(n);
	cout << pt << ' ' << ans.size() << endl;
	for(auto x : ans) cout << x << ' ';
	cout << endl;
}

int main(){
	int T;
	init();
	cin >> T;
	while(T--) solve();
	return 0;
}
