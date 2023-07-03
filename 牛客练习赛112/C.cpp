#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
int arr1[N],arr2[N],pos[N];
int q[N];
void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		cin >> arr1[i];
		pos[arr1[i]] = i;
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> arr2[i];
		arr2[i] = pos[arr2[i]];
	} 

	int hh = 1 , tt = 0;

	for(int i = 1 ; i <= n ; i++){
		if(tt == 0 || arr2[i] > q[tt]) q[++tt] = arr2[i];
		else {
			int idx = lower_bound(q + 1 , q + 1 + tt , arr2[i]) - q;
			q[idx] = arr2[i];
		}
	}
	cout << n - tt << endl;

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