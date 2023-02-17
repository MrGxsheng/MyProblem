#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m,k;
string s;
void solve(){
	cin >> n >> k;
	cin >> s;
	s = '?' + s;
	int res = 0;
	int last = -1;

	priority_queue<int,vector<int> , greater<int> > q;
	for(int i = 1 ; i <= n ; i++){
		if(s[i] == 'Z' && last == -1){
			last = i;
			continue;
		}
		else if(s[i] == 'Z'){
			q.push(i - last - 1);
			last = i;
		}
	}

	while(q.size() && k - q.top() >= 0){
		res += 4;
		k -= q.top();
		q.pop();
	}

	cout << res << endl;
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
