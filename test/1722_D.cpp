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
	cin >> n;
	string s;
	cin >> s;
	s = "?" + s;
	LL res = 0;
	for(int i = 1 ; i <= n ; i++){
		if(s[i] == 'L') res += i - 1;
		if(s[i] == 'R') res += n - i;
	}

	priority_queue<LL> q;
	for(int i = 1 ; i <= n ; i++){
		if(s[i] == 'L'){
			q.push(max(0,n - i - i + 1));
		}else{
			q.push(max(0,i - 1 - n + i));
		}
	}

	for(int i = 1 ; i <= n ; i++){
		res += q.top();
		cout << res << " ";
		q.pop();
	}
	cout << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
