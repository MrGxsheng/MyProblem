#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	string s;
	cin >> n >> s;
	int cnt1 = 0 , cnt2 = 0;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == 'T') cnt1++;
		else cnt2++;
	}

	if(cnt2 == cnt1){
		if(s[n - 1] == 'T') cout << "A" << endl;
		else cout << "T" << endl;
	}else{
		if(cnt1 > cnt2) cout << "T" << endl;
		else cout << "A" << endl;
	}

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