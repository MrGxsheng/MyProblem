#include <bits/stdc++.h>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;
typedef long long LL;
const int N = 1000010;
int n,m;
int a[N];

void print(){
	for(int i = 1 ; i <= n ; i++) cout << a[i] << " \n"[i == n];
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n ; i++) a[i] = i;

	cout << n << endl;
	print();
	swap(a[1],a[n]);
	print();
	for(int i = n ; i >= 3 ; i--) {
		swap(a[i],a[i - 1]);
		print();
	}


}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
