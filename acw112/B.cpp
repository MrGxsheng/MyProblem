#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++) cin >> a[i];

	for(int i = 0 ; i < n ; i++)
		if(a[i] == i + 1) continue;
		else{
			auto b = a;
			reverse(b.begin() + i,b.begin() + a[i]);
			for(int j = 0 ; j < n ; j++){
				if(b[j] != j + 1){
					cout << 0 << ' ' << 0 << endl;
					return;
				}
			}
			cout << i + 1 << ' ' << a[i] << endl; 
			return;
		}
	cout << 0 << ' ' << 0 << endl;

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