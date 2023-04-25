#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	int time = 0;
	vector<int> a(n),b(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];
	for(int i = 0 ; i < n ; i++) cin >> b[i];
	int ans = 0;
	int idx = -1;

	for(int i = 0 ; i < n ; i++){
		if(a[i] + time <= m && b[i] > ans ){
			idx = i + 1;
			ans = b[i];
			time++;
		}else if(time >= m) break;
		else time ++;
	}
	cout << idx << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}