#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;
void solve(){
	cin >> n;
	vector<int> v;
	int cnt = 0;
	int z = 0;
	m = n;
	while(n){
		int x = m % 10;
		m /= 10;
		if(x){
			v.push_back(x * pow(10,z));
			n -= x * pow(10,z);
			cnt++;
		} 
		z++;
	}
	reverse(v.begin(), v.end());
	cout << cnt << endl;
	for(int i = 0 ; i < v.size() ; i++) cout << v[i] << ' ';
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