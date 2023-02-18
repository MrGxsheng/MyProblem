#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
int a[N];
map<int,int> mp;
priority_queue<int> q;
void solve(){
	cin >> n;

	for(int i = 1; i <= n ; i++){ 
		cin >> a[i];
		q.push(a[i]);
		mp[a[i]] ++;
	}
		

	int mex = 1;
	while(n){
		if(mp.count(mex)) mex++,n--;
		else if(n - 2 >= 0) n -= 2,mex++;
		else break;
	}
	cout << mex - 1 << endl;
	
}

int main(){
	int T;
	// cin >> T;
	T = 1;
	while(T--) solve();
	return 0;
}
