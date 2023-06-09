#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m,k,b;
void solve(){

	cin >> n >> m >> k >> b;
	k++;
	vector<int> h(n),a(n);
	for(int i = 0 ; i < n ; i++) cin >> h[i];
	for(int i = 0 ; i < n ; i++) cin >> a[i];

	for(int i = 0 ; i < n ; i++){
		h[i] %= k;
		int z = m;
		z--;
		int x = (k - h[i] + a[i] - 1) / a[i];
		int y = (k - b + a[i] - 1) / a[i];
		if(x > z) cout << h[i] + a[i] * z << ' ';
		else{
			z -= x;

			z %= y;
			cout << b + a[i] * z << ' '; 
		}
	}
	cout << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}