#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n;

void solve(){
	string s;
	s += '?';
	string aa;

	cin >> n >> aa;
	s += aa;
	string res;
	vector<char> a(n + 1);
	int cnt = 0;
	for(int i = n ; i >= 1;){
		if(s[i] == '0'){
			int x = s[i - 1] - '0'  + (s[i - 2] - '0') * 10;
			char xx = (x - 1 + 'a');
			a[cnt++] = xx;
			i -= 3;
		}else {
			char xx = (s[i] - '0' - 1 + 'a');
			a[cnt++] = xx;
			i--;
		}
	}
	for(int i = cnt - 1 ; i >= 0 ; i --) cout << a[i];
	cout << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
