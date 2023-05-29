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
	set<int> st;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
		st.insert(a[i]);
	} 
	sort(a.begin(), a.end());
	
	if(st.size() < n){
		cout << -1 << endl;
		return;
	}
	for(int i = 0 ;i < n ; i++) cout << a[i] << ' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}