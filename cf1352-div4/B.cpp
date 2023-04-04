#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 1000010;
int n,m;

void print(){
	for(int i = 0 ; i < m - 1 ; i ++) cout << 1 << ' ';
	cout << n - m + 1 << endl;
}

void print1(){
	for(int i = 0 ; i < m - 1 ; i ++) cout << 1 << ' ';
	cout << n - m + 1 << endl;
}

void solve(){
	int k;
	cin >> n >> k;
	int n1 = n - (k - 1);
	if (n1 > 0 && n1 % 2 == 1) {
		cout << "YES" << endl;
		for (int i = 0; i < k - 1; ++i) cout << "1 ";
		cout << n1 << endl;
		return;
	}
	int n2 = n - 2 * (k - 1);
	if (n2 > 0 && n2 % 2 == 0) {
		cout << "YES" << endl;
		for (int i = 0; i < k - 1; ++i) cout << "2 ";
		cout << n2 << endl;
		return;
	}
	cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}