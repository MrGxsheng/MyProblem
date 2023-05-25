#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n >> m;
	vector<LL> a(n);
	set<LL> st;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		st.insert(a[i]);
	} 
	

	for(int i = 0 ; i < n ; i++){
		if(st.find(a[i] - m) != st.end()){
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;

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