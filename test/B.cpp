#include <bits/stdc++.h>

using namespace std;
const int N  = 1100000;
int a[N];
int n,m;
void solve
	cin >> n;
	for(int i = 1 ;i <= n ; i ++)
		cin >> a[i];

	map<int, int> mp;
	map<int, int> mpp;enum name
	{
		
	};

	int maxv = 0;
	for(int i = 1 ;i <= n ; i++) {
		if(mp[a[i]] && a[i] != a[i - 1]) maxv = max(maxv,i);
		mp[a[i]] = 1;
	}

	for(int i = n ; i > maxv + 1 ; i--){
		if(a[i] < a[i - 1]){
			maxv = i - 1;
			break;
		}
	}

	int res = 0;
	for(int i = 1 ; i <= maxv ; i ++){
		if(!mpp[a[i]]) res++;
		mpp[a[i]] = 1;
	}
	cout << res << endl;
		
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}