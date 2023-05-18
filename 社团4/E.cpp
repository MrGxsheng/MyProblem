#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;

void solve(){
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1 ; i <= n ; i++) cin >> a[i];

	LL ans = 0;
	for(int i = 1 ; i <= n ; i++)
		for(int j = i + 1 ; j <= n ; j++)
			if(a[i] < a[j])
				for(int c = j + 1 ; c <= n ; c++)
					if(a[i] < a[c] && a[c] < a[j])
						for(int d = c + 1 ; d <= n ; d++)
							if(a[i] < a[c] && a[c] < a[j] && a[j] < a[d]) ans++;
				
		
	
	cout << ans << endl;

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