#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector a(2,vector<int>(n));

	for(int i = 0 ; i < 2 ; i++){
		for(int j = 0 ; j < n ; j++){
			int a;
			if((i + j) & 1) a = j + 1;
			else a = (j - 1 + n) % n + n + 1;
		
			cout << a << " \n"[j == n - 1];
		}
	}

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	// T = 1;
	while(T--) solve();
	return 0;
}